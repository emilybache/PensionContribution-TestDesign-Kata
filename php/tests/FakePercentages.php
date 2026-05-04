<?php

declare(strict_types=1);

namespace Test;

use PensionContribution\SalaryContributionPercentages;

final class FakePercentages extends SalaryContributionPercentages
{
    /**
     * @param array<string, float> $salaryPercentage
     */
    public function __construct(
        private array $salaryPercentage
    ) {
    }

    public static function getStandardValues(): self
    {
        return new self([
            'LONG_TENURE_PERCENTAGE' => 3.5,
            'MEDIUM_TENURE_PERCENTAGE' => 2.0,
            'NO_TENURE_PERCENTAGE' => 0.0,
            'LEADERSHIP_TEAM_PERCENTAGE' => 2.5,
            'MID_SENIORITY_PERCENTAGE' => 3.0,
            'BASE_CONTRIBUTION_RATE' => 5.0,
        ]);
    }

    public function lookupValue(string $value): float
    {
        return $this->salaryPercentage[$value];
    }
}
