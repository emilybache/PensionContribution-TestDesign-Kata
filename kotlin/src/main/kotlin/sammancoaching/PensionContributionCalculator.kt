package sammancoaching

import java.math.BigDecimal
import java.math.RoundingMode

class PensionContributionCalculator(private val databaseAccess: DatabaseAccess) {

    fun calculatePensionContribution(employeeId: Int): BigDecimal {
        val employee = databaseAccess.getEmployeeById(employeeId)
        val annualSalary = employee.annualSalary
        val tenureYears = employee.tenure
        val seniority = employee.seniority
        val contributionPercentages = SalaryContributionPercentages(databaseAccess)
        return calculatePensionContribution(annualSalary, tenureYears, seniority, contributionPercentages)
    }

    companion object {
        fun calculatePensionContribution(
            annualSalary: BigDecimal,
            tenureYears: Int,
            seniority: SeniorityLevel,
            percentages: SalaryContributionPercentages
        ): BigDecimal {
            // BUG: Should throw an IllegalArgumentException if annualSalary is zero or below

            var tenureBonus = percentages.lookupValue(SalaryContributionPercentages.NO_TENURE_PERCENTAGE)
            // BUG: Should be a long tenure bonus for 15 years or more
            if (tenureYears >= 10) {
                tenureBonus = percentages.lookupValue(SalaryContributionPercentages.LONG_TENURE_PERCENTAGE)
            } else if (tenureYears >= 5) {
                tenureBonus = percentages.lookupValue(SalaryContributionPercentages.MEDIUM_TENURE_PERCENTAGE)
            }

            // BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
            val seniorityBonus = seniority.getPensionContributionBonus(percentages)
            val totalContributionPercentage = percentages.lookupValue(SalaryContributionPercentages.BASE_CONTRIBUTION_RATE) + tenureBonus + seniorityBonus

            // BUG: should divide by 100 (not 10) to get a percentage of annual salary
            return annualSalary
                .multiply(BigDecimal.valueOf(totalContributionPercentage))
                .divide(BigDecimal("10"), RoundingMode.HALF_UP)
        }
    }
}