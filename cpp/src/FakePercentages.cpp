#include "FakePercentages.h"


FakePercentages FakePercentages::getStandardValues() {
    std::unordered_map<std::string, double> salaryPercentages;
    salaryPercentages["LONG_TENURE_PERCENTAGE"] = 3.5;
    salaryPercentages["MEDIUM_TENURE_PERCENTAGE"] = 2.0;
    salaryPercentages["NO_TENURE_PERCENTAGE"] = 0.0;
    salaryPercentages["LEADERSHIP_TEAM_PERCENTAGE"] = 2.5;
    salaryPercentages["MID_SENIORITY_PERCENTAGE"] = 3.0;
    salaryPercentages["BASE_CONTRIBUTION_RATE"] = 5.0;

    return FakePercentages(salaryPercentages);
}

FakePercentages::FakePercentages(const std::unordered_map<std::string, double> &salaryPercentages)
    : SalaryContributionPercentages(nullptr), // Passing nullptr (like Java's null)
      salaryPercentages(salaryPercentages) {
}

double FakePercentages::lookupValue(const std::string &namedConstant) const {
    return salaryPercentages.at(namedConstant);
}
