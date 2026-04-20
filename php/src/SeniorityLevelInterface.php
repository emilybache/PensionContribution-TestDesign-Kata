<?php

declare(strict_types=1);

namespace PensionContribution;

interface SeniorityLevelInterface
{
    public function getPensionContributionBonus(SalaryContributionPercentages $databaseAccess): float;
}
