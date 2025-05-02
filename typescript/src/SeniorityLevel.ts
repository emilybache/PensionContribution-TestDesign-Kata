import {ContributionPercentages} from "./SalaryContributionPercentages";

export interface SeniorityLevel {
  getPensionContributionBonus(databaseAccess: ContributionPercentages): number;
}
