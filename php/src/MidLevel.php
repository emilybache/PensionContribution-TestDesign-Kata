<?php

declare(strict_types=1);

namespace PensionContribution;

final class MidLevel implements SeniorityLevelInterface
{
    public function getPensionContributionBonus(SalaryContributionPercentages $databaseAccess): float
    {
        return $databaseAccess->lookupValue(SalaryContributionPercentages::MID_SENIORITY_PERCENTAGE);
    }
}
