
Part 1: Test names and intentions
==================================
There are several bugs in the production code, and a document that describes them [Bug Reports](Bug_Reports.md). Write unit test skeletons for each one, following the checklist below. You may write as many tests for each bug as you think is needed.

DO NOT WRITE THE TEST CODE YET, only comments. We want to be certain we have expressed our intent in words before we begin writing code.

1. Paste the appropriate template into the "GoodUnitTest" class/module:

```c++
    SECTION("Below Zero Salary - Fails") {
        // Irrelevant
        // Initial state
        // Action
        // Outcome
    }
```

```csharp
   [TestCase]
   public void ScenarioSummary()
   {
      // Irrelevant
      // Initial state
      // Action
      // Outcome
   }
```

```java
    @Test
    void scenarioSummary() {
        // Irrelevant
        // Initial state
        // Action
        // Outcome
    }
```

```kotlin
    @Test
    fun `Scenario Summary`() {
        // Irrelevant
        // Initial state
        // Action
        // Outcome
    }
```

```python
def test_scenario_summary():
    # Irrelevant
    # Initial state
    # Action
    # Outcome
    pass
```

```typescript
    test("Scenario Summary", () => {
        // Irrelevant
        // Initial state
        // Action
        // Outcome    
  });
```

2. Carefully read the code to understand the bug. Identify the desired outcome which does not happen because of the bug. In the comment under `Outcome` write a comment that specifies this desired outcome.
3. Identify one specific input that would be needed to trigger the bug. In the comment under `Initial State` write a new comment that specifies this input.
4. Identify the action that would case the outcome given the specific condition and write it in a comment under `Action`.
5. Do not add any comments under `Irrelevant`. We will use that in the next part.
6. Summarize the whole test scenario in a few words and use it as the test name. This name should express what is unique about this particular test without going into a lot of details.
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

1. Under each comment, write the equivalent code. If you find you need to add any code that is necessary for the test but isn't referred to in your comments, put it in an `Irrelevant` section.
2. Make sure the test fails because of the bug and that the test name helps you understand which behaviour is broken. Adjust the test name and test code until the failure message is good.
3. Fix the bug and ensure the test passes.
4. Remove any unnecessary comments (ones that duplicate the code) and commit with the message: `[completed] - new test for xxx` (write your test name instead of xxx).
5. (optional) Refactor the test to minimize the amount of code in the `Irrelevant` sections. Commit again with `[refactoring]`.


