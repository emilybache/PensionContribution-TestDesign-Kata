namespace PensionContributionCalculations;

public interface ISeniorityLevel
{
    double GetPensionContributionBonus(ISalaryContributionPercentages databaseAccess);
}