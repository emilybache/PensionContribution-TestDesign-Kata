Pension Contribution Test Design Kata
======================================

There are some bugs in the code (marked with comments). For each bug, write a unit test that fails with a good error message. Then fix the bug and make sure the test now passes. Repeat for other bugs.

When all the marked bugs are fixed, discuss:

* What general advice would you give for designing tests to ensure the failure messages are useful for finding bugs?
* Are there any kinds of bugs your unit tests will not be able to expose?


Sample solution
---------------

This branch contains some unit tests. Some notes on the test design:

* The class is named `SalaryPensionContributionCalculationTest` because the behaviour being tested is for salary pension contribution calculations. There is no need for a 1-1 mapping between test classes and production classes, it's more important to have domain language in the test name and to test a meaningful unit of behaviour.

* The tests all target the method `PensionContributionCalculator.calculatePensionContribution` because this entry point is easy to call from a unit test, and accesses all the main domain logic.

* There is no coverage of the data access layer because this is tested in other kinds of tests, not unit tests.

* The test names have two parts separated by an underscore. The first part is a summary of the scenario being tested, the second part is a summary of the expected outcome.

* The test code is divided with newlines into three sections corresponding to 'Arrange, Act, Assert'. This makes the test easier for the eye to follow and read.

You may disagree with some or all of these design decisions and there are many other ways to solve this exercise. Hopefully working on this code will have provoked some useful discussions.


