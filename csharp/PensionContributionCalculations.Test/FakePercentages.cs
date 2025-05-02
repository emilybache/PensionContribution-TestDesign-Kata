namespace PensionContributionCalculations.Test;

using System.Collections.Generic;

public class FakePercentages : ISalaryContributionPercentages
{
    private readonly Dictionary<string, double> _salaryPercentages;

    public static FakePercentages GetStandardValues()
    {
        var salaryPercentages = new Dictionary<string, double>
        {
            { "LONG_TENURE_PERCENTAGE", 3.5 },
            { "MEDIUM_TENURE_PERCENTAGE", 2.0 },
            { "NO_TENURE_PERCENTAGE", 0.0 },
            { "LEADERSHIP_TEAM_PERCENTAGE", 2.5 },
            { "MID_SENIORITY_PERCENTAGE", 3.0 },
            { "BASE_CONTRIBUTION_RATE", 5.0 }
        };

        return new FakePercentages(salaryPercentages);
    }

    public FakePercentages(Dictionary<string, double> salaryPercentages)
    {
        _salaryPercentages = salaryPercentages;
    }

    public double LookupValue(string namedConstant)
    {
        return _salaryPercentages.TryGetValue(namedConstant, out var value) ? value : 0.0;
    }
}
