
from abc import ABC, abstractmethod
from decimal import Decimal, ROUND_HALF_UP


class DatabaseAccess(ABC):
    @abstractmethod
    def get_employee_by_id(self, employee_id: int):
        pass

    @abstractmethod
    def lookup_value(self, named_constant: str) -> float:
        pass

class Employee:
    def __init__(self, annual_salary: Decimal, tenure: int, seniority: 'SeniorityLevel'):
        self._annual_salary = annual_salary
        self._tenure = tenure
        self._seniority = seniority

    @property
    def annual_salary(self) -> Decimal:
        return self._annual_salary

    @property
    def tenure(self) -> int:
        return self._tenure

    @property
    def seniority(self) -> 'SeniorityLevel':
        return self._seniority

class SeniorityLevel(ABC):
    @abstractmethod
    def get_pension_contribution_bonus(self, database_access: 'SalaryContributionPercentages') -> float:
        pass

class JuniorEmployee(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: 'SalaryContributionPercentages') -> float:
        return 0.0

class LeadershipTeam(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: 'SalaryContributionPercentages') -> float:
        # BUG: Should be leadership_team_percentage
        return database_access.lookup_value(SalaryContributionPercentages.mid_seniority_percentage)

class MidLevel(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: 'SalaryContributionPercentages') -> float:
        return database_access.lookup_value(SalaryContributionPercentages.mid_seniority_percentage)

class SalaryContributionPercentages:
    no_tenure_percentage = "NO_TENURE_PERCENTAGE"
    medium_tenure_percentage = "MEDIUM_TENURE_PERCENTAGE"
    long_tenure_percentage = "LONG_TENURE_PERCENTAGE"
    leadership_team_percentage = "LEADERSHIP_TEAM_PERCENTAGE"
    mid_seniority_percentage = "MID_SENIORITY_PERCENTAGE"
    base_contribution_rate = "BASE_CONTRIBUTION_RATE"

    def __init__(self, database_access: DatabaseAccess):
        self._database_access = database_access

    def lookup_value(self, named_constant: str) -> float:
        return self._database_access.lookup_value(named_constant)



class PensionContributionCalculator:
    def __init__(self, database_access: 'DatabaseAccess'):
        self._database_access = database_access

    def calculate_pension_contribution(self, employee_id: int) -> Decimal:
        employee = self._database_access.get_employee_by_id(employee_id)
        annual_salary = employee.annual_salary
        tenure_years = employee.tenure
        seniority = employee.seniority
        contribution_percentages = SalaryContributionPercentages(self._database_access)
        return self.calculate_pension_contribution_static(
            annual_salary, tenure_years, seniority, contribution_percentages
        )

    @staticmethod
    def calculate_pension_contribution_static(
            annual_salary: Decimal, tenure_years: int, seniority: 'SeniorityLevel',
            percentages: 'SalaryContributionPercentages'
    ) -> Decimal:
        # BUG: Should raise a ValueError if annual_salary is zero or below
        if annual_salary <= 0:
            raise ValueError("Annual salary must be greater than zero")

        tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.no_tenure_percentage)

        # BUG: Should be a long tenure bonus for 15 years or more
        if tenure_years >= 10:
            tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.long_tenure_percentage)
        elif tenure_years >= 5:
            tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.medium_tenure_percentage)

        # BUG: some of the seniority bonuses need adjusting - look in the relevant source files for them
        seniority_bonus = seniority.get_pension_contribution_bonus(percentages)
        total_contribution_percentage = (
                percentages.lookup_value(SalaryContributionPercentages.base_contribution_rate)
                + tenure_bonus
                + seniority_bonus
        )

        return (annual_salary * Decimal(total_contribution_percentage)).quantize(
            Decimal('0.01'), rounding=ROUND_HALF_UP
        ) / Decimal(100)
