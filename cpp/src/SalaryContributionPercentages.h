#ifndef SALARY_CONTRIBUTION_PERCENTAGES_H
#define SALARY_CONTRIBUTION_PERCENTAGES_H

#include <string>
#include "DatabaseAccess.h"


/*
 * This class lets you look up the actual percentages for specific tenure and seniority.
 * Typical values for these percentages:
 *
 * "NO_TENURE_PERCENTAGE" = 0.0
 * "MEDIUM_TENURE_PERCENTAGE" = 2.0
 * "LONG_TENURE_PERCENTAGE" = 3.5
 * "LEADERSHIP_TEAM_PERCENTAGE" = 2.5
 * "MID_SENIORITY_PERCENTAGE" = 3.0
 * "BASE_CONTRIBUTION_RATE" = 5.0
 */
class SalaryContributionPercentages {
public:
    static constexpr const char *NO_TENURE_PERCENTAGE = "NO_TENURE_PERCENTAGE";
    static constexpr const char *MEDIUM_TENURE_PERCENTAGE = "MEDIUM_TENURE_PERCENTAGE";
    static constexpr const char *LONG_TENURE_PERCENTAGE = "LONG_TENURE_PERCENTAGE";
    static constexpr const char *LEADERSHIP_TEAM_PERCENTAGE = "LEADERSHIP_TEAM_PERCENTAGE";
    static constexpr const char *MID_SENIORITY_PERCENTAGE = "MID_SENIORITY_PERCENTAGE";
    static constexpr const char *BASE_CONTRIBUTION_RATE = "BASE_CONTRIBUTION_RATE";

private:
    DatabaseAccess *databaseAccess; // Dependency injected from outside.

public:
    SalaryContributionPercentages(DatabaseAccess *databaseAccess);

    double lookupValue(const std::string &namedConstant) const;
};


#endif // SALARY_CONTRIBUTION_PERCENTAGES_H
