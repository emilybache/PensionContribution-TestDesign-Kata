import {ContributionPercentages, SalaryContributionPercentages} from "./SalaryContributionPercentages";
import {SeniorityLevel} from "./SeniorityLevel";

export class LeadershipTeam implements SeniorityLevel {
  getPensionContributionBonus(databaseAccess: ContributionPercentages): number {
    // BUG: Should be LEADERSHIP_TEAM_PERCENTAGE
    return databaseAccess.lookupValue(SalaryContributionPercentages.MID_SENIORITY_PERCENTAGE);
  }
}
