#ifndef SENIORITY_LEVEL_H
#define SENIORITY_LEVEL_H

#include "SalaryContributionPercentages.h"

class SeniorityLevel {
public:
    // This method calculates the pension bonus using a lookup from the given database-access object.
    virtual double getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const = 0;
    virtual ~SeniorityLevel() {}
};

#endif // SENIORITY_LEVEL_H
