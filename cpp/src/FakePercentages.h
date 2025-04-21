#ifndef FAKE_PERCENTAGES_H
#define FAKE_PERCENTAGES_H

#include <unordered_map>
#include <string>
#include "SalaryContributionPercentages.h"

/*
 * This is a useful class for testing purposes, it's not part of the production system
 */
class FakePercentages : public SalaryContributionPercentages {
private:
    std::unordered_map<std::string, double> salaryPercentages;

public:
    static FakePercentages getStandardValues();

    FakePercentages(const std::unordered_map<std::string, double> &salaryPercentages);

    virtual double lookupValue(const std::string &namedConstant) const;
};


#endif // FAKE_PERCENTAGES_H
