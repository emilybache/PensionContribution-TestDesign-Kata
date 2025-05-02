namespace PensionContributionCalculations;

public class LeadershipTeam : ISeniorityLevel
{
    public double GetPensionContributionBonus(ISalaryContributionPercentages databaseAccess)
    {
        // BUG: Should be LEADERSHIP_TEAM_PERCENTAGE
        return databaseAccess.LookupValue(SalaryContributionPercentages.LEADERSHIP_TEAM_PERCENTAGE);
    }
    
}
