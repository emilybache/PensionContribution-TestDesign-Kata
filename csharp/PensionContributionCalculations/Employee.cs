namespace PensionContributionCalculations;

public class Employee
{
    public decimal AnnualSalary { get; }
    public int Tenure { get; }
    public ISeniorityLevel Seniority { get; }

    public Employee(decimal annualSalary, int tenure, ISeniorityLevel seniority)
    {
        AnnualSalary = annualSalary;
        Tenure = tenure;
        Seniority = seniority;
    }
}
