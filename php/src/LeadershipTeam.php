<?php

declare(strict_types=1);

namespace PensionContribution;

final class LeadershipTeam implements SeniorityLevelInterface
{
    public function getPensionContributionBonus(SalaryContributionPercentages $databaseAccess): float
    {
        // BUG: Should be LEADERSHIP_TEAM_PERCENTAGE
        return $databaseAccess->lookupValue(SalaryContributionPercentages::MID_SENIORITY_PERCENTAGE);
    }
}
