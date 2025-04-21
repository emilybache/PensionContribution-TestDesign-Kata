

#include "Employee.h"

#include "SeniorityLevel.h"

Employee::Employee(double annualSalary, int tenure, SeniorityLevel* seniority)
    : annualSalary(annualSalary), tenure(tenure), seniority(seniority) {}

double Employee::getAnnualSalary() const {
    return annualSalary;
}

int Employee::getTenure() const {
    return tenure;
}

SeniorityLevel* Employee::getSeniority() const {
    return seniority;
}