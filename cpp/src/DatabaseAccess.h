#ifndef DATABASE_ACCESS_H
#define DATABASE_ACCESS_H

#include <string>
// Forward declaration to avoid circular dependency
class Employee;

class DatabaseAccess {
public:
    virtual Employee* getEmployeeById(int employeeId) = 0;
    [[nodiscard]] virtual double lookupValue(const std::string &namedConstant) const = 0;
    virtual ~DatabaseAccess() {}
};

#endif // DATABASE_ACCESS_H
