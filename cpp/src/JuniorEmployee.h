#ifndef JUNIOR_EMPLOYEE_H
#define JUNIOR_EMPLOYEE_H

#include "SalaryContributionPercentages.h"
#include "SeniorityLevel.h"

class JuniorEmployee : public SeniorityLevel {
public:
    virtual double getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const override;
};

inline double JuniorEmployee::getPensionContributionBonus(const SalaryContributionPercentages &databaseAccess) const {
    return 0.0;
}

#endif // JUNIOR_EMPLOYEE_H
