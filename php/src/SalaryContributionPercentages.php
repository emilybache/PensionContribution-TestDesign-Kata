<?php

declare(strict_types=1);

namespace PensionContribution;

/**
 * This class lets you look up the actual percentages for specific tenure and seniority.
 * Typical values for these percentages:
 *
 * "NO_TENURE_PERCENTAGE" = 0.0
 * "MEDIUM_TENURE_PERCENTAGE" = 2.0
 * "LONG_TENURE_PERCENTAGE" = 3.5
 * "LEADERSHIP_TEAM_PERCENTAGE" = 2.5
 * "MID_SENIORITY_PERCENTAGE" = 3.0
 * "BASE_CONTRIBUTION_RATE" = 5.0
 */
class SalaryContributionPercentages
{
    public const NO_TENURE_PERCENTAGE = 'NO_TENURE_PERCENTAGE';

    public const MEDIUM_TENURE_PERCENTAGE = 'MEDIUM_TENURE_PERCENTAGE';

    public const LONG_TENURE_PERCENTAGE = 'LONG_TENURE_PERCENTAGE';

    public const LEADERSHIP_TEAM_PERCENTAGE = 'LEADERSHIP_TEAM_PERCENTAGE';

    public const MID_SENIORITY_PERCENTAGE = 'MID_SENIORITY_PERCENTAGE';

    public const BASE_CONTRIBUTION_RATE = 'BASE_CONTRIBUTION_RATE';

    public function __construct(
        private DatabaseAccessInterface $databaseAccess,
    ) {
    }

    public function lookupValue(string $nameConstant): float
    {
        return $this->databaseAccess->lookupValue($nameConstant);
    }
}
