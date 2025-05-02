import {DatabaseAccess} from "./DatabaseAccess";

export interface ContributionPercentages {
  lookupValue(namedConstant: string): number;
}

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
export class SalaryContributionPercentages implements ContributionPercentages {
  static readonly NO_TENURE_PERCENTAGE = "NO_TENURE_PERCENTAGE";
  static readonly MEDIUM_TENURE_PERCENTAGE = "MEDIUM_TENURE_PERCENTAGE";
  static readonly LONG_TENURE_PERCENTAGE = "LONG_TENURE_PERCENTAGE";
  static readonly LEADERSHIP_TEAM_PERCENTAGE = "LEADERSHIP_TEAM_PERCENTAGE";
  static readonly MID_SENIORITY_PERCENTAGE = "MID_SENIORITY_PERCENTAGE";
  static readonly BASE_CONTRIBUTION_RATE = "BASE_CONTRIBUTION_RATE";

  private readonly databaseAccess: DatabaseAccess;

  constructor(databaseAccess: DatabaseAccess) {
    this.databaseAccess = databaseAccess;
  }

  lookupValue(namedConstant: string): number {
    return this.databaseAccess.lookupValue(namedConstant);
  }
}
