namespace PensionContributionCalculations;

public class PensionContributionCalculator
{
    private readonly IDatabaseAccess _databaseAccess;

    public PensionContributionCalculator(IDatabaseAccess databaseAccess)
    {
        _databaseAccess = databaseAccess;
    }

    public decimal CalculatePensionContribution(int employeeId)
    {
        Employee employee = _databaseAccess.GetEmployeeById(employeeId);
        decimal annualSalary = employee.AnnualSalary;
        int tenureYears = employee.Tenure;
        ISeniorityLevel seniority = employee.Seniority;
        SalaryContributionPercentages contributionPercentages = new SalaryContributionPercentages(_databaseAccess);
        return CalculatePensionContribution(annualSalary, tenureYears, seniority, contributionPercentages);
    }

    public static decimal CalculatePensionContribution(decimal annualSalary, int tenureYears, ISeniorityLevel seniority, ISalaryContributionPercentages percentages)
    {
        // BUG: Should throw an ArgumentException if annualSalary is zero or below

        double tenureBonus = percentages.LookupValue(SalaryContributionPercentages.NO_TENURE_PERCENTAGE);
        // BUG: Should be a long tenure bonus for 15 years or more
        if (tenureYears >= 10)
        {
            tenureBonus = percentages.LookupValue(SalaryContributionPercentages.LONG_TENURE_PERCENTAGE);
        }
        else if (tenureYears >= 5)
        {
            tenureBonus = percentages.LookupValue(SalaryContributionPercentages.MEDIUM_TENURE_PERCENTAGE);
        }

        // BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
        double seniorityBonus = seniority.GetPensionContributionBonus(percentages);
        double totalContributionPercentage = percentages.LookupValue(SalaryContributionPercentages.BASE_CONTRIBUTION_RATE) + tenureBonus + seniorityBonus;

        // BUG: should divide by 100 (not 10) to get a percentage of annual salary
        return annualSalary
            * (decimal)totalContributionPercentage
            / 10;
    }
}
