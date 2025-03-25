from data_access import SalaryContributionPercentages


class FakePercentages(SalaryContributionPercentages):
    def __init__(self, salary_percentages: dict):
        super().__init__(None)
        self._salary_percentages = salary_percentages

    @staticmethod
    def get_standard_values() -> 'FakePercentages':
        salary_percentages = {
            "LONG_TENURE_PERCENTAGE": 3.5,
            "MEDIUM_TENURE_PERCENTAGE": 2.0,
            "NO_TENURE_PERCENTAGE": 0.0,
            "LEADERSHIP_TEAM_PERCENTAGE": 2.5,
            "MID_SENIORITY_PERCENTAGE": 3.0,
            "BASE_CONTRIBUTION_RATE": 5.0,
        }
        return FakePercentages(salary_percentages)

    def lookup_value(self, named_constant: str) -> float:
        return self._salary_percentages[named_constant]
