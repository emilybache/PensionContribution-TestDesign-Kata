package sammancoaching;

import java.math.BigDecimal;
import java.math.RoundingMode;

public class PensionContributionCalculator {

    private final DatabaseAccess databaseAccess;

    public PensionContributionCalculator(DatabaseAccess databaseAccess) {
        this.databaseAccess = databaseAccess;
    }

    public BigDecimal calculatePensionContribution(int employeeId) {
        Employee employee = databaseAccess.getEmployeeById(employeeId);
        BigDecimal annualSalary = employee.getAnnualSalary();
        int tenureYears = employee.getTenure();
        SeniorityLevel seniority = employee.getSeniority();
        SalaryContributionPercentages contributionPercentages = new SalaryContributionPercentages(databaseAccess);
        return calculatePensionContribution(annualSalary, tenureYears, seniority, contributionPercentages);
    }

    public static BigDecimal calculatePensionContribution(BigDecimal annualSalary, int tenureYears, SeniorityLevel seniority, SalaryContributionPercentages percentages) {
        // BUG: Should throw an IllegalArgumentException if annualSalary is zero or below
        if (annualSalary.compareTo(BigDecimal.ZERO) <= 0) {
            throw new IllegalArgumentException("Salary must be positive.");
        }

        double tenureBonus = percentages.lookupValue(SalaryContributionPercentages.NO_TENURE_PERCENTAGE);
        // BUG: Should be a long tenure bonus for 15 years or more
        if (tenureYears >= 15) {
            tenureBonus = percentages.lookupValue(SalaryContributionPercentages.LONG_TENURE_PERCENTAGE);
        } else if (tenureYears >= 5) {
            tenureBonus = percentages.lookupValue(SalaryContributionPercentages.MEDIUM_TENURE_PERCENTAGE);
        }

        // BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
        double seniorityBonus = seniority.getPensionContributionBonus(percentages);
        double totalContributionPercentage = percentages.lookupValue(SalaryContributionPercentages.BASE_CONTRIBUTION_RATE) + tenureBonus + seniorityBonus;

        // BUG: should divide by 100 (not 10) to get a percentage of annual salary
        return annualSalary
                .multiply(BigDecimal.valueOf(totalContributionPercentage))
                .divide(new BigDecimal("100"), RoundingMode.HALF_UP);
    }


}

