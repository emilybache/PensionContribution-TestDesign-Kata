#ifndef MID_LEVEL_H
#define MID_LEVEL_H

#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"

class MidLevel : public SeniorityLevel {
public:
    virtual double getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const override;
};

inline double MidLevel::getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const {
    return databaseAccess.lookupValue(SalaryContributionPercentages::MID_SENIORITY_PERCENTAGE);
}

#endif // MID_LEVEL_H
