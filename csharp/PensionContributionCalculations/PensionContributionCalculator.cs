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
        double tenureBonus = percentages.LookupValue(SalaryContributionPercentages.NO_TENURE_PERCENTAGE);
        if (tenureYears >= 10)
        {
            tenureBonus = percentages.LookupValue(SalaryContributionPercentages.LONG_TENURE_PERCENTAGE);
        }
        else if (tenureYears >= 5)
        {
            tenureBonus = percentages.LookupValue(SalaryContributionPercentages.MEDIUM_TENURE_PERCENTAGE);
        }

        double seniorityBonus = seniority.GetPensionContributionBonus(percentages);
        double totalContributionPercentage = percentages.LookupValue(SalaryContributionPercentages.BASE_CONTRIBUTION_RATE) + tenureBonus + seniorityBonus;

        return annualSalary
            * (decimal)totalContributionPercentage
            / 10;
    }
}
