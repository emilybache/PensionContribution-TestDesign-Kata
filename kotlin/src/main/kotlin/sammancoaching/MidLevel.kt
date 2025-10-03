package sammancoaching

class MidLevel : SeniorityLevel {
    override fun getPensionContributionBonus(databaseAccess: SalaryContributionPercentages): Double {
        return databaseAccess.lookupValue(SalaryContributionPercentages.MID_SENIORITY_PERCENTAGE)
    }
}