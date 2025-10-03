package sammancoaching

class JuniorEmployee : SeniorityLevel {
    override fun getPensionContributionBonus(databaseAccess: SalaryContributionPercentages): Double {
        return 0.0
    }
}