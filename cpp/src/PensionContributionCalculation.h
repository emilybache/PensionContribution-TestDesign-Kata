#ifndef PENSION_CONTRIBUTION_CALCULATOR_H
#define PENSION_CONTRIBUTION_CALCULATOR_H

#include "DatabaseAccess.h"
#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"


class PensionContributionCalculator {
private:
    DatabaseAccess *databaseAccess;

public:
    explicit PensionContributionCalculator(DatabaseAccess *databaseAccess);

    [[nodiscard]] double calculatePensionContribution(int employeeId) const;

    static double calculatePensionContribution(double annualSalary,
                                               int tenureYears,
                                               const SeniorityLevel *seniority,
                                               const SalaryContributionPercentages &percentages);
};


#endif // PENSION_CONTRIBUTION_CALCULATOR_H
