from decimal import Decimal, ROUND_HALF_UP

from data_access import DatabaseAccess, SalaryContributionPercentages
from domain import SeniorityLevel


class PensionContributionCalculator:
    def __init__(self, database_access: DatabaseAccess):
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
            annual_salary: Decimal, tenure_years: int, seniority: SeniorityLevel,
            percentages: SalaryContributionPercentages
    ) -> Decimal:
        # BUG: Should raise a ValueError if annual_salary is zero or below

        tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.no_tenure_percentage)

        # BUG: Should be a long tenure bonus for 15 years or more
        if tenure_years >= 10:
            tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.long_tenure_percentage)
        elif tenure_years >= 5:
            tenure_bonus = percentages.lookup_value(SalaryContributionPercentages.medium_tenure_percentage)

        # BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
        seniority_bonus = seniority.get_pension_contribution_bonus(percentages)
        total_contribution_percentage = (
                percentages.lookup_value(SalaryContributionPercentages.base_contribution_rate)
                + tenure_bonus
                + seniority_bonus
        )

        # BUG: should divide by 100 (not 10) to get a percentage of annual salary
        return (annual_salary * Decimal(total_contribution_percentage)).quantize(
            Decimal('0.01'), rounding=ROUND_HALF_UP
        ) / Decimal(10)
