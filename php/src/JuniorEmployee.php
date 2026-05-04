<?php

declare(strict_types=1);

namespace PensionContribution;

final class JuniorEmployee implements SeniorityLevelInterface
{
    public function getPensionContributionBonus(SalaryContributionPercentages $databaseAccess): float
    {
        return 0.0;
    }
}
