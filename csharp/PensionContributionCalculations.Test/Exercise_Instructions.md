
Part 1: Test names and intentions
==================================
There are several bugs in the production code, all marked with the comment `// BUG:`
Find the bugs using your search tool. Write unit test skeletons for each one, following the checklist below. 

DO NOT WRITE THE TEST CODE YET, only comments. We want to be certain we have expressed our intent in words before we begin writing code.

1. Paste this template into the "GoodUnitTest" class:

```
   [TestCase]
   public void ActionUnderSpecificCondition_should_ProduceOutcome()
   {
      // Irrelevant
      // Initial state
      // Action
      // Outcome
   }
```

2. The test name has two parts - "ActionUnderSpecificCondition" and "ProduceOutcome". Carefully read the code to understand the bug. Identify the desired outcome which does not happen because of the bug and summarize it in a few words. Put that in the test name instead of "ProduceOutcome".
3. In the comment under "Outcome" write a // comment that specifies the details of this desired outcome.
4. Identify the input that would be needed to trigger the bug. Summarize this and replace the other part of the test name "ActionUnderSpecificCondition".
5. In the comment under "Initial State" write a new // comment that specifies the exact details of the conditions that would trigger the bug.
6. In the comment under "Action" write a new // comment specifying the action or method you will call to trigger the outcome.
7. Make a commit of these comments with the message: `[intent] - new test for xxx` (write your test name instead of xxx).

Part 2: Test Classes
====================
When you have followed the above checklist and created test skeletons for ALL the bugs, review the test class name `GoodUnitTest`. 

* What is the unit of behaviour that you are testing? 

Rename the class to reflect that. If you find that the tests are for more than one unit of behaviour, create new test classes as needed and move the relevant test cases to them.

Part 3: Test Code
==================
Now we will write the actual test code, using the skeleton to help us focus on intent and keep the test brief and to the point. 

You might find the class `FakePercentages` helpful to use instead of creating your own mocks for database access. Take a look at this class now.

1. Under each comment, write the equivalent code. If there is any code that is necessary for the test but isn't directly relevant for this particular test scenario, put it in the "Irrelevant" section.
2. Make sure the test fails because of the bug and that the test name helps you understand what is wrong. Adjust the test name and test code until the failure message is good.
3. Fix the bug and ensure the test passes.
4. Remove unnecessary comments and commit with the message: `[completed] - new test for xxx` (write your test name instead of xxx).


