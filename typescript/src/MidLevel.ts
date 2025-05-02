import {SeniorityLevel} from "./SeniorityLevel";
import {ContributionPercentages, SalaryContributionPercentages} from "./SalaryContributionPercentages";

export class MidLevel implements SeniorityLevel {
  getPensionContributionBonus(databaseAccess: ContributionPercentages): number {
    return databaseAccess.lookupValue(SalaryContributionPercentages.MID_SENIORITY_PERCENTAGE);
  }
}
