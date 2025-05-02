import {ContributionPercentages} from "../src/SalaryContributionPercentages";

export class FakePercentages implements ContributionPercentages {
  private readonly salaryPercentages: Map<string, number>;

  static getStandardValues(): FakePercentages {
    const salaryPercentages = new Map<string, number>([
      ["LONG_TENURE_PERCENTAGE", 3.5],
      ["MEDIUM_TENURE_PERCENTAGE", 2.0],
      ["NO_TENURE_PERCENTAGE", 0.0],
      ["LEADERSHIP_TEAM_PERCENTAGE", 2.5],
      ["MID_SENIORITY_PERCENTAGE", 3.0],
      ["BASE_CONTRIBUTION_RATE", 5.0]
    ]);

    return new FakePercentages(salaryPercentages);
  }

  constructor(salaryPercentages: Map<string, number>) {
    this.salaryPercentages = salaryPercentages;
  }

  lookupValue(namedConstant: string): number {
    return this.salaryPercentages.get(namedConstant) ?? 0.0;
  }
}
