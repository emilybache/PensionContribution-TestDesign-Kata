namespace PensionContributionCalculations;

public class MidLevel : ISeniorityLevel
{
    public double GetPensionContributionBonus(ISalaryContributionPercentages databaseAccess)
    {
        return databaseAccess.LookupValue(SalaryContributionPercentages.MID_SENIORITY_PERCENTAGE);
    }
}
