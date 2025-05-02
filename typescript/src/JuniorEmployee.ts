import {SeniorityLevel} from "./SeniorityLevel";
import {ContributionPercentages} from "./SalaryContributionPercentages";

export class JuniorEmployee implements SeniorityLevel {
  getPensionContributionBonus(databaseAccess: ContributionPercentages): number {
    return 0.0;
  }
}
