#ifndef PENSION_CONTRIBUTION_CALCULATOR_H
#define PENSION_CONTRIBUTION_CALCULATOR_H

#include "DatabaseAccess.h"
#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"


class PensionContributionCalculator {
private:
    DatabaseAccess *databaseAccess;

public:
    PensionContributionCalculator(DatabaseAccess *databaseAccess);

    double calculatePensionContribution(int employeeId) const;

    static double calculatePensionContribution(double annualSalary,
                                               int tenureYears,
                                               SeniorityLevel *seniority,
                                               const SalaryContributionPercentages &percentages);
};


#endif // PENSION_CONTRIBUTION_CALCULATOR_H
