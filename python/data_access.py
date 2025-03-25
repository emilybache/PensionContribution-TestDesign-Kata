from abc import ABC, abstractmethod


class DatabaseAccess(ABC):
    @abstractmethod
    def get_employee_by_id(self, employee_id: int):
        pass

    @abstractmethod
    def lookup_value(self, named_constant: str) -> float:
        pass


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
