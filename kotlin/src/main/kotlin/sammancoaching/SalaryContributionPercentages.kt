package sammancoaching

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
open class SalaryContributionPercentages(private val databaseAccess: DatabaseAccess) {

    companion object {
        const val NO_TENURE_PERCENTAGE = "NO_TENURE_PERCENTAGE"
        const val MEDIUM_TENURE_PERCENTAGE = "MEDIUM_TENURE_PERCENTAGE"
        const val LONG_TENURE_PERCENTAGE = "LONG_TENURE_PERCENTAGE"
        const val LEADERSHIP_TEAM_PERCENTAGE = "LEADERSHIP_TEAM_PERCENTAGE"
        const val MID_SENIORITY_PERCENTAGE = "MID_SENIORITY_PERCENTAGE"
        const val BASE_CONTRIBUTION_RATE = "BASE_CONTRIBUTION_RATE"
    }

    open fun lookupValue(namedConstant: String): Double {
        return databaseAccess.lookupValue(namedConstant)
    }
}