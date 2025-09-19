Bug Reports
===========

Salary Ranges are not checked properly
--------------------------------------
We have an overnight batch job that calculates the pension contributions. It gets records from another system, but sometimes the other system has a glitch and supplies negative values for the annual salary for certain employees. The pension contribution system consequently calculates a negative contribution. It should instead reject the bad record.

Calculations are off by a wide margin
-------------------------------------
Pension contributions are expressed as a percentage of salary rather than an absolute amount. Unfortunately, the latest release seems to have a glitch that returns values that are way higher than expected. The values we are getting for these percentages generally seem to be ten times larger than they should be, sometimes even more than 100%. 

Tenure is being interpreted too generously
------------------------------------------
When calculating pension contributions, employees get an additional bonus if they have been with the company for a long time. The highest bonus level seems to be being given to employees with only ten years of tenure, which is too generous. The highest bonus should only be paid to those with more than 15 years of tenure.

Senior Leadership is unhappy with their compensation
----------------------------------------------------
Managers get a more generous pension contribution than ordinary employees. Recently it was decided that the leadership team should be given an even larger pension contribution percentage, but they have complained that this hasn't shown up in their salary statements yet. We have added this higher level in the database, but they haven't received it. Leadership team members should receive a higher level of benefit than mid-level employees. 

New compensation rules for Hourly wage employees
------------------------------------------------
Some employees are paid an hourly wage instead of an annual salary. The calculation currently doesn't include them, but we would like to change the rules and give them a pension contribution of half the usual base rate. These employees should not receive bonuses for tenure or seniority. We will need to add support for these employees both in the database and the calculation rules.