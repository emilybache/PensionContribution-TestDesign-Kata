from abc import ABC, abstractmethod
from decimal import Decimal

from data_access import SalaryContributionPercentages

class SeniorityLevel(ABC):
    @abstractmethod
    def get_pension_contribution_bonus(self, database_access: SalaryContributionPercentages) -> float:
        pass


class JuniorEmployee(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: SalaryContributionPercentages) -> float:
        return 0.0


class LeadershipTeam(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: SalaryContributionPercentages) -> float:
        # BUG: Should be leadership_team_percentage
        return database_access.lookup_value(SalaryContributionPercentages.mid_seniority_percentage)


class MidLevel(SeniorityLevel):
    def get_pension_contribution_bonus(self, database_access: SalaryContributionPercentages) -> float:
        return database_access.lookup_value(SalaryContributionPercentages.mid_seniority_percentage)


class Employee:
    def __init__(self, annual_salary: Decimal, tenure: int, seniority: SeniorityLevel):
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
    def seniority(self) -> SeniorityLevel:
        return self._seniority


