namespace PensionContributionCalculations;

public class JuniorEmployee : ISeniorityLevel
{
    public double GetPensionContributionBonus(ISalaryContributionPercentages databaseAccess)
    {
        return 0.0;
    }
}