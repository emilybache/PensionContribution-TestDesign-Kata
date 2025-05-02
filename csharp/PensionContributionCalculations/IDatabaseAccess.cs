namespace PensionContributionCalculations;

using System;

public interface IDatabaseAccess
{
    Employee GetEmployeeById(int employeeId);

    double LookupValue(string namedConstant);
}





