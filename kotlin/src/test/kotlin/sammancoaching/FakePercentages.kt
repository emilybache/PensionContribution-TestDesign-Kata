package sammancoaching

import io.mockk.mockk


class FakePercentages() : SalaryContributionPercentages(
    mockk()
) {
    companion object {
        fun getStandardValues(): FakePercentages {
            val salaryPercentages = HashMap<String, Double>()
            salaryPercentages["LONG_TENURE_PERCENTAGE"] = 3.5
            salaryPercentages["MEDIUM_TENURE_PERCENTAGE"] = 2.0
            salaryPercentages["NO_TENURE_PERCENTAGE"] = 0.0
            salaryPercentages["LEADERSHIP_TEAM_PERCENTAGE"] = 2.5
            salaryPercentages["MID_SENIORITY_PERCENTAGE"] = 3.0
            salaryPercentages["BASE_CONTRIBUTION_RATE"] = 5.0

            return FakePercentages(salaryPercentages)
        }
    }

    private lateinit var salaryPercentages: HashMap<String, Double>

    constructor(salaryPercentages: HashMap<String, Double>) : this() {
        this.salaryPercentages = salaryPercentages
    }


    public override fun lookupValue(namedConstant: String): Double {
        return salaryPercentages[namedConstant]!!
    }
}