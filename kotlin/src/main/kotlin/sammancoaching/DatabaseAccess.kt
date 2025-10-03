package sammancoaching

interface DatabaseAccess {
    fun getEmployeeById(employeeId: Int): Employee

    fun lookupValue(namedConstant: String): Double
}