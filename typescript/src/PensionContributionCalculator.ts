import {DatabaseAccess} from "./DatabaseAccess";
import {ContributionPercentages, SalaryContributionPercentages} from "./SalaryContributionPercentages";
import {SeniorityLevel} from "./SeniorityLevel";

export class PensionContributionCalculator {
  private readonly databaseAccess: DatabaseAccess;

  constructor(databaseAccess: DatabaseAccess) {
    this.databaseAccess = databaseAccess;
  }

  calculatePensionContribution(employeeId: number): number {
    const employee = this.databaseAccess.getEmployeeById(employeeId);
    const annualSalary = employee.getAnnualSalary();
    const tenureYears = employee.getTenure();
    const seniority = employee.getSeniority();
    const contributionPercentages = new SalaryContributionPercentages(this.databaseAccess);
    return PensionContributionCalculator.calculatePensionContribution(annualSalary, tenureYears, seniority, contributionPercentages);
  }

  static calculatePensionContribution(annualSalary: number, tenureYears: number, seniority: SeniorityLevel, percentages: ContributionPercentages): number {
    // BUG: Should throw an Error if annualSalary is zero or below

    let tenureBonus = percentages.lookupValue(SalaryContributionPercentages.NO_TENURE_PERCENTAGE);
    // BUG: Should be a long tenure bonus for 15 years or more
    if (tenureYears >= 10) {
      tenureBonus = percentages.lookupValue(SalaryContributionPercentages.LONG_TENURE_PERCENTAGE);
    } else if (tenureYears >= 5) {
      tenureBonus = percentages.lookupValue(SalaryContributionPercentages.MEDIUM_TENURE_PERCENTAGE);
    }

    // BUG: one of the seniority bonuses is wrong - look in the relevant classes to find it
    const seniorityBonus = seniority.getPensionContributionBonus(percentages);
    const totalContributionPercentage = percentages.lookupValue(SalaryContributionPercentages.BASE_CONTRIBUTION_RATE) + tenureBonus + seniorityBonus;

    // BUG: should divide by 100 (not 10) to get a percentage of annual salary
    return (annualSalary * totalContributionPercentage) / 10;
  }
}
