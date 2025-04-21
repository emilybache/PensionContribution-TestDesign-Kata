#include <gtest/gtest.h>

using namespace std;

#include "FakePercentages.h"
#include "JuniorEmployee.h"
#include "LeadershipTeam.h"
#include "MidLevel.h"
#include "PensionContributionCalculation.h"

TEST(SalaryPensionContributionCalculation, Below_Zero_Salary_Fails) {
    JuniorEmployee junior;
    auto fakePercentages = FakePercentages::getStandardValues();
    EXPECT_THROW(
        PensionContributionCalculator::calculatePensionContribution(-1.0, -1, &junior, fakePercentages),
        std::invalid_argument
    );
}

TEST(SalaryPensionContributionCalculation, Junior_Employee_With_No_Tenure_Basic_Contribution) {
    auto fakePercentages = FakePercentages::getStandardValues();

    double annualSalary = 60000.0;
    int tenure = 0;
    JuniorEmployee junior;

    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &junior, fakePercentages);

    // Expected: Base (5.0) + no-tenure bonus (0.0) + junior bonus (0.0)
    // Contribution = 60000 * 5% = 3000.
    EXPECT_NEAR(actualContribution, 3000.0, 0.001);
}

TEST(SalaryPensionContributionCalculation, Mid_Level_Recent_Hire_Medium_Contribution) {
    auto fakePercentages = FakePercentages::getStandardValues();

    double annualSalary = 60000.0;
    int tenure = 0;
    // MidLevel returns a mid-seniority bonus (3.0).
    MidLevel midLevel;

    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &midLevel, fakePercentages);

    // Expected: Base (5.0) + no-tenure bonus (0.0) + mid-seniority bonus (3.0)
    // Total percent = 8.0, so contribution = 60000 * 8/100 = 4800.
    EXPECT_NEAR(actualContribution, 4800.0, 0.001);
}

TEST(SalaryPensionContributionCalculation, Mid_Level_Medium_Tenure_Medium_Large_Contribution) {
    auto fakePercentages = FakePercentages::getStandardValues();

    double annualSalary = 60000.0;
    int tenure = 5;  // Triggers medium tenure bonus.
    MidLevel midLevel;

    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &midLevel, fakePercentages);

    // Expected: Base (5.0) + medium tenure bonus (2.0) + mid-seniority bonus (3.0)
    // Total = 10.0, so contribution = 60000 * 10/100 = 6000.
    EXPECT_NEAR(actualContribution, 6000.0, 0.001);
}

TEST(SalaryPensionContributionCalculation, Leadership_With_Long_Tenure_Maximum_Contribution) {
    auto fakePercentages = FakePercentages::getStandardValues();

    double annualSalary = 60000.0;
    int tenure = 25;  // Triggers long tenure bonus.
    LeadershipTeam leader;

    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &leader, fakePercentages);

    // Expected: Base (5.0) + long tenure bonus (3.5) + leadership bonus (2.5)
    // Total = 11.0, so contribution = 60000 * 11/100 = 6600.
    EXPECT_NEAR(actualContribution, 6600.0, 0.001);
}
