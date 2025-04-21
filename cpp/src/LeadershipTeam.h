#ifndef LEADERSHIP_TEAM_H
#define LEADERSHIP_TEAM_H

#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"


class LeadershipTeam : public SeniorityLevel {
public:
    virtual double getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const override;
};

inline double LeadershipTeam::getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const {
    // BUG: Should be SalaryContributionPercentages::LEADERSHIP_TEAM_PERCENTAGE
    return databaseAccess.lookupValue(SalaryContributionPercentages::MID_SENIORITY_PERCENTAGE);
}

#endif // LEADERSHIP_TEAM_H
