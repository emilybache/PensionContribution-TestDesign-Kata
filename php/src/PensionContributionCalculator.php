<?php

declare(strict_types=1);

namespace PensionContribution;

final class PensionContributionCalculator
{
    public function __construct(
        private DatabaseAccessInterface $databaseAccess,
    ) {
    }

    public function calculatePensionContribution(int $employeeId): float
    {
        $employee = $this->databaseAccess->getEmployeeById($employeeId);
        return $this->calculatePensionContrib(
            $employee->getAnnualSalary(),
            $employee->getTenure(),
            $employee->getSeniority(),
            new SalaryContributionPercentages($this->databaseAccess)
        );
    }

    public static function calculatePensionContrib(
        float $annualSalary,
        int $tenureYears,
        SeniorityLevelInterface $seniority,
        SalaryContributionPercentages $percentages
    ): float {
        // BUG: Should throw an IllegalArgumentException if annualSalary is zero or below

        $tenureBonus = $percentages->lookupValue(SalaryContributionPercentages::NO_TENURE_PERCENTAGE);
        // BUG: Should be a long tenure bonus for 15 years or more
        if ($tenureYears >= 10) {
            $tenureBonus = $percentages->lookupValue(SalaryContributionPercentages::LONG_TENURE_PERCENTAGE);
        } elseif ($tenureYears >= 5) {
            $tenureBonus = $percentages->lookupValue(SalaryContributionPercentages::MEDIUM_TENURE_PERCENTAGE);
        }

        // BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
        $seniorityBonus = $seniority->getPensionContributionBonus($percentages);
        $totalContributionPercentage = $percentages->lookupValue(SalaryContributionPercentages::BASE_CONTRIBUTION_RATE) + $tenureBonus + $seniorityBonus;

        // BUG: should divide by 100 (not 10) to get a percentage of annual salary
        return ceil(($annualSalary * $totalContributionPercentage) / 10);
    }
}
