import { PensionContributionCalculator } from "../src/PensionContributionCalculator";
import { JuniorEmployee } from "../src/JuniorEmployee";
import { MidLevel } from "../src/MidLevel";
import { LeadershipTeam } from "../src/LeadershipTeam";
import {FakePercentages} from "./FakePercentages";

const NORMAL_BASE_SALARY = 60000.0;
const fakePercentages = FakePercentages.getStandardValues();

describe("SalaryPensionContributionCalculationTest", () => {
  test("belowZeroSalary_fails", () => {
    expect(() => PensionContributionCalculator.calculatePensionContribution(
      -1, -1, new JuniorEmployee(), fakePercentages
    )).toThrow(Error);
  });

  test("juniorEmployeeWithNoTenure_BasicContribution", () => {
    const annualSalary = NORMAL_BASE_SALARY;
    const tenure = 0;
    const seniority = new JuniorEmployee();

    const actualContribution = PensionContributionCalculator.calculatePensionContribution(
      annualSalary, tenure, seniority, fakePercentages
    );

    expect(actualContribution).toBeCloseTo(3000.0, 3);
  });

  test("midLevelRecentHire_MediumContribution", () => {
    const annualSalary = NORMAL_BASE_SALARY;
    const tenure = 0;
    const seniority = new MidLevel();

    const actualContribution = PensionContributionCalculator.calculatePensionContribution(
      annualSalary, tenure, seniority, fakePercentages
    );

    expect(actualContribution).toBeCloseTo(4800.0, 3);
  });

  test("midLevelMediumTenure_MediumLargeContribution", () => {
    const annualSalary = NORMAL_BASE_SALARY;
    const tenure = 5;
    const seniority = new MidLevel();

    const actualContribution = PensionContributionCalculator.calculatePensionContribution(
      annualSalary, tenure, seniority, fakePercentages
    );

    expect(actualContribution).toBeCloseTo(6000.0, 3);
  });

  test("leadershipWithLongTenure_MaximumContribution", () => {
    const annualSalary = NORMAL_BASE_SALARY;
    const tenure = 25;
    const seniority = new LeadershipTeam();

    const actualContribution = PensionContributionCalculator.calculatePensionContribution(
      annualSalary, tenure, seniority, fakePercentages
    );

    expect(actualContribution).toBeCloseTo(6600.0, 3);
  });
});
