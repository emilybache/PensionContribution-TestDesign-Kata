#ifndef DATABASE_ACCESS_H
#define DATABASE_ACCESS_H

#include <string>
// Forward declaration to avoid circular dependency
class Employee;

// The implementation of this class is not included since it can't be used in a unit test.
class DatabaseAccess {
public:
    virtual Employee* getEmployeeById(int employeeId) = 0;
    virtual double lookupValue(const std::string &namedConstant) const = 0;
    virtual ~DatabaseAccess() {}
};

#endif // DATABASE_ACCESS_H
