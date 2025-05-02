import {SeniorityLevel} from "./SeniorityLevel";

export class Employee {
  private readonly annualSalary: number;
  private readonly tenure: number;
  private readonly seniority: SeniorityLevel;

  constructor(annualSalary: number, tenure: number, seniority: SeniorityLevel) {
    this.annualSalary = annualSalary;
    this.tenure = tenure;
    this.seniority = seniority;
  }

  getAnnualSalary(): number {
    return this.annualSalary;
  }

  getTenure(): number {
    return this.tenure;
  }

  getSeniority(): SeniorityLevel {
    return this.seniority;
  }
}
