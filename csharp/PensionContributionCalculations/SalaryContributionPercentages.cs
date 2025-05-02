namespace PensionContributionCalculations;

using System;

/**
 * This class lets you look up the actual percentages for specific tenure and seniority.
 * Typical values for these percentages:
 *
 * "NO_TENURE_PERCENTAGE" = 0.0
 * "MEDIUM_TENURE_PERCENTAGE" = 2.0
 * "LONG_TENURE_PERCENTAGE" = 3.5
 * "LEADERSHIP_TEAM_PERCENTAGE" = 2.5
 * "MID_SENIORITY_PERCENTAGE" = 3.0
 * "BASE_CONTRIBUTION_RATE" = 5.0
 */
public class SalaryContributionPercentages : ISalaryContributionPercentages
{
    public const string NO_TENURE_PERCENTAGE = "NO_TENURE_PERCENTAGE";
    public const string MEDIUM_TENURE_PERCENTAGE = "MEDIUM_TENURE_PERCENTAGE";
    public const string LONG_TENURE_PERCENTAGE = "LONG_TENURE_PERCENTAGE";
    public const string LEADERSHIP_TEAM_PERCENTAGE = "LEADERSHIP_TEAM_PERCENTAGE";
    public const string MID_SENIORITY_PERCENTAGE = "MID_SENIORITY_PERCENTAGE";
    public const string BASE_CONTRIBUTION_RATE = "BASE_CONTRIBUTION_RATE";

    private readonly IDatabaseAccess _databaseAccess;

    public SalaryContributionPercentages(IDatabaseAccess databaseAccess)
    {
        _databaseAccess = databaseAccess;
    }

    public double LookupValue(string namedConstant)
    {
        return _databaseAccess.LookupValue(namedConstant);
    }
}
