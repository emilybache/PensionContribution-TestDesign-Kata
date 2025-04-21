set(SRC_LIB_NAME src)
set(SOURCES
        DatabaseAccess.h
        Employee.cpp
        Employee.h
        SeniorityLevel.h
        SalaryContributionPercentages.h
        JuniorEmployee.h
        LeadershipTeam.h
        MidLevel.h
        PensionContributionCalculation.cpp
        PensionContributionCalculation.h
        FakePercentages.cpp
        FakePercentages.h)
add_library(${SRC_LIB_NAME} ${SOURCES})
target_sources(${SRC_LIB_NAME} PRIVATE ${SOURCES})
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
