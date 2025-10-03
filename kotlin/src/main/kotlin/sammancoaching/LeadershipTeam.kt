package sammancoaching

class LeadershipTeam : SeniorityLevel {
    override fun getPensionContributionBonus(databaseAccess: SalaryContributionPercentages): Double {
        // BUG: Should be LEADERSHIP_TEAM_PERCENTAGE
        return databaseAccess.lookupValue(SalaryContributionPercentages.MID_SENIORITY_PERCENTAGE)
    }
}