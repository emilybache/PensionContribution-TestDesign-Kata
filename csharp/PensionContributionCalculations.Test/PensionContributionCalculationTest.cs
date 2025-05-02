namespace PensionContributionCalculations.Test;

using System;
using NUnit.Framework;

[TestFixture]
public class SalaryPensionContributionCalculationTest
{
    private const double NORMAL_BASE_SALARY = 60000.0;
    private readonly ISalaryContributionPercentages _fakePercentages = FakePercentages.GetStandardValues();

    [Test]
    public void BelowZeroSalary_Fails()
    {
        Assert.Throws<ArgumentException>(() => PensionContributionCalculator.CalculatePensionContribution(
            -1, -1, new JuniorEmployee(), _fakePercentages));
    }

    [Test]
    public void JuniorEmployeeWithNoTenure_BasicContribution()
    {
        decimal annualSalary = (decimal)NORMAL_BASE_SALARY;
        int tenure = 0;
        ISeniorityLevel seniority = new JuniorEmployee();

        var actualContribution = PensionContributionCalculator.CalculatePensionContribution(
            annualSalary, tenure, seniority, _fakePercentages);

        Assert.That((double)actualContribution, Is.EqualTo(3000.0).Within(0.001));
    }

    [Test]
    public void MidLevelRecentHire_MediumContribution()
    {
        decimal annualSalary = (decimal)NORMAL_BASE_SALARY;
        int tenure = 0;
        ISeniorityLevel seniority = new MidLevel();

        var actualContribution = PensionContributionCalculator.CalculatePensionContribution(
            annualSalary, tenure, seniority, _fakePercentages);

        Assert.That((double)actualContribution, Is.EqualTo(4800.0).Within(0.001));
    }

    [Test]
    public void MidLevelMediumTenure_MediumLargeContribution()
    {
        decimal annualSalary = (decimal)NORMAL_BASE_SALARY;
        int tenure = 5;
        ISeniorityLevel seniority = new MidLevel();

        var actualContribution = PensionContributionCalculator.CalculatePensionContribution(
            annualSalary, tenure, seniority, _fakePercentages);

        Assert.That((double)actualContribution, Is.EqualTo(6000.0).Within(0.001));
    }

    [Test]
    public void LeadershipWithLongTenure_MaximumContribution()
    {
        decimal annualSalary = (decimal)NORMAL_BASE_SALARY;
        int tenure = 25;
        ISeniorityLevel seniority = new LeadershipTeam();

        var actualContribution = PensionContributionCalculator.CalculatePensionContribution(
            annualSalary, tenure, seniority, _fakePercentages);

        Assert.That((double)actualContribution, Is.EqualTo(6600.0).Within(0.001));
    }
}
