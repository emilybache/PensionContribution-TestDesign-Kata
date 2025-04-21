#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "SeniorityLevel.h"

class Employee {
private:
    double annualSalary; 
    int tenure;
    SeniorityLevel* seniority;
public:
    Employee(double annualSalary, int tenure, SeniorityLevel* seniority);

    double getAnnualSalary() const;
    int getTenure() const;
    SeniorityLevel* getSeniority() const;
};



#endif // EMPLOYEE_H
