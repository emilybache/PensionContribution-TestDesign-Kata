from domain import JuniorEmployee, LeadershipTeam, MidLevel
from pension_calculator import *
import pytest
from decimal import Decimal

from tests.fake_contribution_percentages import FakePercentages

NORMAL_BASE_SALARY = 60000.0

@pytest.fixture
def fake_percentages():
    return FakePercentages.get_standard_values()

def test_below_zero_salary_fails(fake_percentages):
    with pytest.raises(ValueError):
        PensionContributionCalculator.calculate_pension_contribution_static(
            Decimal(-1), -1, None, fake_percentages
        )

def test_junior_employee_with_no_tenure_basic_contribution(fake_percentages):
    annual_salary = Decimal(NORMAL_BASE_SALARY)
    tenure = 0
    seniority = JuniorEmployee()

    actual_contribution = PensionContributionCalculator.calculate_pension_contribution_static(
        annual_salary, tenure, seniority, fake_percentages
    )

    assert pytest.approx(actual_contribution, 0.001) == 3000.0

def test_mid_level_recent_hire_medium_contribution(fake_percentages):
    annual_salary = Decimal(NORMAL_BASE_SALARY)
    tenure = 0
    seniority = MidLevel()

    actual_contribution = PensionContributionCalculator.calculate_pension_contribution_static(
        annual_salary, tenure, seniority, fake_percentages
    )

    assert pytest.approx(actual_contribution, 0.001) == 4800.0

def test_mid_level_medium_tenure_medium_large_contribution(fake_percentages):
    annual_salary = Decimal(NORMAL_BASE_SALARY)
    tenure = 5
    seniority = MidLevel()

    actual_contribution = PensionContributionCalculator.calculate_pension_contribution_static(
        annual_salary, tenure, seniority, fake_percentages
    )

    assert pytest.approx(actual_contribution, 0.001) == 6000.0

def test_leadership_with_long_tenure_maximum_contribution(fake_percentages):
    annual_salary = Decimal(NORMAL_BASE_SALARY)
    tenure = 25
    seniority = LeadershipTeam()

    actual_contribution = PensionContributionCalculator.calculate_pension_contribution_static(
        annual_salary, tenure, seniority, fake_percentages
    )

    assert pytest.approx(actual_contribution, 0.001) == 6600.0
