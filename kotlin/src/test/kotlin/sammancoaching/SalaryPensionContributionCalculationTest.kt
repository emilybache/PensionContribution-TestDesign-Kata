package sammancoaching

import java.math.BigDecimal
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFailsWith

class SalaryPensionContributionCalculationTest {

    val NORMAL_BASE_SALARY: Double = 60000.0
    private val fakePercentages: SalaryContributionPercentages? = FakePercentages.getStandardValues()

    @Test
    fun belowZeroSalary_fails() {
        assertFailsWith(IllegalArgumentException::class, {
            PensionContributionCalculator.calculatePensionContribution(
                BigDecimal.valueOf(-1), -1, JuniorEmployee(), fakePercentages!!
            )
        })
    }

    @Test
    fun juniorEmployeeWithNoTenure_BasicContribution() {
        val annualSalary = BigDecimal.valueOf(NORMAL_BASE_SALARY)
        val tenure = 0
        val seniority: SeniorityLevel = JuniorEmployee()

        val actualContribution = PensionContributionCalculator.calculatePensionContribution(
            annualSalary, tenure, seniority, fakePercentages!!
        )

        assertEquals(
            3000.0,
            actualContribution.toDouble(), 0.001
        )
    }

    @Test
    fun midLevelRecentHire_MediumContribution() {
        val annualSalary = BigDecimal.valueOf(NORMAL_BASE_SALARY)
        val tenure = 0
        val seniority: SeniorityLevel = MidLevel()

        val actualContribution = PensionContributionCalculator.calculatePensionContribution(
            annualSalary, tenure, seniority, fakePercentages!!
        )

        assertEquals(
            4800.0,
            actualContribution.toDouble(), 0.001
        )
    }

    @Test
    fun midLevelMediumTenure_MediumLargeContribution() {
        val annualSalary = BigDecimal.valueOf(NORMAL_BASE_SALARY)
        val tenure = 5
        val seniority: SeniorityLevel = MidLevel()

        val actualContribution = PensionContributionCalculator.calculatePensionContribution(
            annualSalary, tenure, seniority, fakePercentages!!
        )

        assertEquals(
            6000.0,
            actualContribution.toDouble(), 0.001
        )
    }

    @Test
    fun leadershipWithLongTenure_MaximumContribution() {
        val annualSalary = BigDecimal.valueOf(NORMAL_BASE_SALARY)
        val tenure = 25
        val seniority: SeniorityLevel = LeadershipTeam()

        val actualContribution = PensionContributionCalculator.calculatePensionContribution(
            annualSalary, tenure, seniority, fakePercentages!!
        )

        assertEquals(
            6600.0,
            actualContribution.toDouble(), 0.001
        )
    }
}