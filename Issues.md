Current Issues
==============

1. Calculations are off by a wide margin
----------------------------------------
Unfortunately, the latest release seems to have a glitch that returns values that are way higher than expected. The values we are getting for pension contributions generally seem to be ten times larger than they should be, sometimes even more than 100% of the annual salary. 

With a normal base salary of 60 000 EUR and no bonuses, the pension contribution should be set to the base contribution rate of 5%, ie 3000 EUR.  

2. Salary Ranges with negative contributions
--------------------------------------------
We have an overnight batch job that calculates the pension contributions. It gets records from another system, but sometimes the other system has a glitch and supplies negative values for the annual salary for certain employees. The pension contribution system consequently calculates a negative contribution. It should instead reject the bad record - salaries below zero should not be accepted.

3. Tenure is being interpreted too generously
---------------------------------------------
When calculating pension contributions, employees get an additional bonus if they have been with the company for a long time. The highest bonus level seems to be being given to employees with only ten years of tenure, which is too generous. The highest bonus should only be paid to those with 15 or more years of tenure.

With a normal base salary of 60 000 EUR and 15 or more years of tenure, the total bonus should be 8.5% or 5100 EUR.

4. Senior Leadership is unhappy with their compensation
-------------------------------------------------------
Managers get a more generous pension contribution than ordinary employees. Recently it was decided that the leadership team should be given an even larger pension contribution percentage, but they have complained that this hasn't shown up in their salary statements yet. We have added this higher level in the database, but they haven't received it. Leadership team members should receive a higher level of benefit than mid-level employees. 

With a normal base salary of 60 000 EUR, managers in the leadership team should receive a total bonus of 7.5%, ie 4500 EUR (assuming no tenure bonus).

5. New compensation rules for Hourly wage employees
---------------------------------------------------
Some employees are paid an hourly wage instead of an annual salary. The calculation currently doesn't include them, but we would like to change the rules and give them a pension contribution of half the usual base rate. These employees should not receive bonuses for tenure or seniority. We will need to add support for these employees both in the database and the calculation rules.

With an hourly wage of 30 EUR these employees are eligible for a pension contribution of 2.5% or 0.75 EUR per hour.
