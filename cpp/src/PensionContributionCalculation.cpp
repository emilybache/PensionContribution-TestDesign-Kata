#include "PensionContributionCalculation.h"
#include "DatabaseAccess.h"
#include "Employee.h"
#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"
#include <stdexcept>


PensionContributionCalculator::PensionContributionCalculator(DatabaseAccess *databaseAccess)
    : databaseAccess(databaseAccess) {
}

double PensionContributionCalculator::calculatePensionContribution(int employeeId) const {
    Employee *employee = databaseAccess->getEmployeeById(employeeId);
    if (!employee) {
        throw std::runtime_error("Employee not found");
    }

    double annualSalary = employee->getAnnualSalary();
    int tenureYears = employee->getTenure();
    SeniorityLevel *seniority = employee->getSeniority();

    SalaryContributionPercentages percentages(databaseAccess);

    return calculatePensionContribution(annualSalary, tenureYears, seniority, percentages);
}

double PensionContributionCalculator::calculatePensionContribution(const double annualSalary,
                                                                   const int tenureYears,
                                                                   const SeniorityLevel *seniority,
                                                                   const SalaryContributionPercentages &percentages) {
    // BUG: Should throw an std::invalid_argument if annualSalary is zero or below.

    double tenureBonus = percentages.lookupValue(SalaryContributionPercentages::NO_TENURE_PERCENTAGE);

    // BUG: Should be a long tenure bonus for 15 years or more.
    if (tenureYears >= 10) {
        tenureBonus = percentages.lookupValue(SalaryContributionPercentages::LONG_TENURE_PERCENTAGE);
    } else if (tenureYears >= 5) {
        tenureBonus = percentages.lookupValue(SalaryContributionPercentages::MEDIUM_TENURE_PERCENTAGE);
    }

    // BUG: One of the seniority bonuses is wrong – see the relevant classes for details.
    double seniorityBonus = seniority->getPensionContributionBonus(percentages);

    double totalContributionPercentage = percentages.lookupValue(SalaryContributionPercentages::BASE_CONTRIBUTION_RATE)
                                         + tenureBonus + seniorityBonus;

    // BUG: should divide by 100 (not 10) to get a percentage of annual salary.
    double contribution = (annualSalary * totalContributionPercentage) / 10.0;

    return contribution;
}

