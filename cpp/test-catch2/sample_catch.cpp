#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

#include "FakePercentages.h"
#include "JuniorEmployee.h"
#include "LeadershipTeam.h"
#include "MidLevel.h"
#include "PensionContributionCalculation.h"


TEST_CASE("belowZeroSalary_fails", "[SalaryPensionContributionCalculationTest]") {
    auto fakePercentages = FakePercentages::getStandardValues();
    REQUIRE_THROWS_AS(
        PensionContributionCalculator::calculatePensionContribution(-1.0, -1, nullptr, fakePercentages),
        std::invalid_argument
    );
}

TEST_CASE("juniorEmployeeWithNoTenure_BasicContribution", "[SalaryPensionContributionCalculationTest]") {
    auto fakePercentages = FakePercentages::getStandardValues();
    
    double annualSalary = 60000.0;
    int tenure = 0;
    JuniorEmployee junior;
    
    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &junior, fakePercentages);
    
    // Expected: Base (5.0) + no-tenure bonus (0.0) + junior bonus (0.0)
    // Correct percentage should be divided by 100, i.e., 60000 * 5 / 100 = 3000.
    REQUIRE(actualContribution == Approx(3000.0).epsilon(0.001));
}

TEST_CASE("midLevelRecentHire_MediumContribution", "[SalaryPensionContributionCalculationTest]") {
    auto fakePercentages = FakePercentages::getStandardValues();
    
    double annualSalary = 60000.0;
    int tenure = 0;
    // MidLevel returns a mid-seniority bonus (3.0).
    MidLevel midLevel;
    
    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &midLevel, fakePercentages);
    
    // Expected: Base (5.0) + no tenure bonus (0.0) + mid-seniority bonus (3.0)
    // Total percent = 8.0, so contribution = 60000 * 8 / 100 = 4800.
    REQUIRE(actualContribution == Approx(4800.0).epsilon(0.001));
}

TEST_CASE("midLevelMediumTenure_MediumLargeContribution", "[SalaryPensionContributionCalculationTest]") {
    auto fakePercentages = FakePercentages::getStandardValues();
    
    double annualSalary = 60000.0;
    int tenure = 5; // Triggers medium tenure bonus.
    MidLevel midLevel;
    
    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &midLevel, fakePercentages);
    
    // Expected: Base (5.0) + medium tenure bonus (2.0) + mid-seniority bonus (3.0)
    // Total = 10.0, so contribution = 60000 * 10 / 100 = 6000.
    REQUIRE(actualContribution == Approx(6000.0).epsilon(0.001));
}

TEST_CASE("leadershipWithLongTenure_MaximumContribution", "[SalaryPensionContributionCalculationTest]") {
    auto fakePercentages = FakePercentages::getStandardValues();
    
    double annualSalary = 60000.0;
    int tenure = 25; // Triggers long tenure bonus.
    LeadershipTeam leader;
    
    double actualContribution = PensionContributionCalculator::calculatePensionContribution(annualSalary, tenure, &leader, fakePercentages);
    
    // Expected: Base (5.0) + long tenure bonus (3.5) + leadership bonus (2.5)
    // Total = 11.0, so contribution = 60000 * 11 / 100 = 6600.
    REQUIRE(actualContribution == Approx(6600.0).epsilon(0.001));
}

