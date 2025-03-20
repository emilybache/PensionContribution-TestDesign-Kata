package sammancoaching;

import java.util.HashMap;

public class FakePercentages extends SalaryContributionPercentages {
    private final HashMap<String, Double> salaryPercentages;

    public static FakePercentages getStandardValues() {
        var salaryPercentages = new HashMap<String, Double>();
        salaryPercentages.put("LONG_TENURE_PERCENTAGE", 3.5);
        salaryPercentages.put("MEDIUM_TENURE_PERCENTAGE", 2.0);
        salaryPercentages.put("NO_TENURE_PERCENTAGE", 0.0);
        salaryPercentages.put("LEADERSHIP_TEAM_PERCENTAGE", 2.5);
        salaryPercentages.put("MID_SENIORITY_PERCENTAGE", 3.0);
        salaryPercentages.put("BASE_CONTRIBUTION_RATE", 5.0);

        return new FakePercentages(salaryPercentages);
    }

    public FakePercentages(HashMap<String, Double> salaryPercentages) {
        super(null);
        this.salaryPercentages = salaryPercentages;
    }

    @Override
    public double lookupValue(String namedConstant) {
        return salaryPercentages.get(namedConstant);
    }
}
