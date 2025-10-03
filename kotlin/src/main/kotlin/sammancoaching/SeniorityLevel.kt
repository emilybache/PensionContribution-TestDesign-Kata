package sammancoaching

interface SeniorityLevel {
    fun getPensionContributionBonus(databaseAccess: SalaryContributionPercentages): Double
}