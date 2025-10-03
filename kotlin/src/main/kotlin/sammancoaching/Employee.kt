package sammancoaching

import java.math.BigDecimal

data class Employee(
    val annualSalary: BigDecimal,
    val tenure: Int,
    val seniority: SeniorityLevel
)