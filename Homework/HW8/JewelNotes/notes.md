In order to understand the fundamentals of the homework task this outline will provide clearer points on what is required. The outlines have been provided using Chat GPT to quickly summarize main points of the task into a more concise and easy to read manner.
If any other issues pop up or coding notes arise they will be put here.

### Solution Outline for Exercise A - Program: Counting Words

#### 1. **Understanding the Task**
   - **Objective**: Write a C++ program to count distinct words in a file.
   - **Input**: Filename from the user.
   - **Output**: Number of distinct words and a list of words with their frequencies.

#### 2. **Setting Up the Program Structure**
   - **File**: `wordcount.cpp`
   - **Main Components**:
     - `main()` function: To handle user input and control program flow.
     - Word counting mechanism: Utilizing STL Table (e.g., `std::map` or `std::unordered_map`).

#### 3. **Reading the Filename**
   - Use `std::getline(std::cin, filename)` to read the entire line as filename input.
   - Implement checks for empty or invalid filenames.

#### 4. **Opening and Reading the File**
   - Open the file using `std::ifstream`.
   - Implement error checking after each file operation.
   - Read the file word by word, or line by line followed by parsing.

#### 5. **Counting Words**
   - As you read words, insert them into an STL table (e.g., `std::map<string, int>`).
   - Increment the count for each occurrence of a word.

#### 6. **Handling Special Cases**
   - Check for end-of-file (EOF) and other potential reading errors.
   - Consider corner cases like an empty file, non-existent file, etc.

#### 7. **Displaying Results**
   - Print the total number of distinct words.
   - Iterate through the table to print each word and its count.
   - Format the output as shown in the example.

#### 8. **Testing**
   - Test with `wordcount_test.txt` and various other files.
   - Ensure the program handles errors gracefully and matches the expected output.

#### 9. **Robustness and Error Handling**
   - Ensure the program does not crash under any circumstances.
   - Implement thorough error checking for file operations and user inputs.
   - Test edge cases like unusual filenames, directory names, etc.

#### 10. **Coding Standards Compliance**
   - Follow good coding practices such as meaningful variable names, comments, consistent indentation, etc.

---

### Solution Outline for Exercise B - Writing a Test Suite

#### 1. **Understanding the Task**
   - **Objective**: Develop a test suite for the `Squarer` class using the doctest framework.
   - **Focus Areas**: Const and non-const objects, range of values, positive and negative inputs, integer and floating-point arguments, special cases.

#### 2. **Setting Up the Test Suite**
   - **File**: Modify `squarer_test.cpp`.
   - **Main Components**:
     - Include `doctest.h` and `squarer.h`.
     - Define test cases using doctest directives (`TEST_CASE`, `REQUIRE`, `INFO`, etc.).

#### 3. **Testing Const and Non-Const Objects**
   - Create test cases for both const and non-const `Squarer` objects.
   - Verify that both types of objects function correctly.

#### 4. **Testing a Range of Values**
   - Design test cases to check the squaring functionality for a wide range of values.
   - Include both typical and edge-case values in your tests.

#### 5. **Handling Positive and Negative Inputs**
   - Ensure test cases cover both positive and negative numbers.
   - Verify that `Squarer` handles negative numbers correctly.

#### 6. **Testing Integer and Floating-Point Arguments**
   - Create separate tests for integer and floating-point inputs.
   - Check for correctness in both cases, particularly the accuracy in floating-point calculations.

#### 7. **Special Cases: 0, 1, and -1**
   - Explicitly test the squaring of 0, 1, and -1, as these are significant edge cases.

#### 8. **Verifying Error Messages**
   - Use `REQUIRE` and `REQUIRE_FALSE` directives to assert conditions.
   - Utilize `INFO` directives to provide useful information for each test, especially for failing cases.

#### 9. **Compilation Requirement Compliance**
   - Ensure your test suite compiles with doctest.h version 2 and a correctly written `squarer.h`.
   - Avoid including `doctest.h` or `squarer.h` in your submission.

#### 10. **Iterative Testing and Refinement**
   - Initially test with a correct implementation of `squarer.h` to ensure all tests pass.
   - Intentionally introduce errors in `squarer.h` to verify that your test suite catches these issues.
   - Refine your tests based on the results to cover any missed scenarios.

#### 11. **Coding Standards and Documentation**
   - Follow good coding practices with meaningful test case names and clear, concise code.
   - Document your test cases, explaining what each test is checking for.
output test 1:
```bash
Number of distinct words: 45

2023: 1
2023-11-28: 1
311: 1
8,: 1
A: 1
And: 1
Assignment: 1
CS: 1
Can: 2
Chappell: 1
Exercise: 1
Fall: 1
For: 1
G.: 1
Glenn: 1
Next: 1
Test: 1
What: 1
a: 3
again.: 1
change: 2
correctly: 2
count: 2
ending: 1
file: 2
for: 1
if: 1
input: 1
is: 2
it: 1
line-ending: 1
line.: 1
line?: 1
long: 2
marker?: 1
newline?: 1
no: 1
the: 1
there: 1
we: 2
when: 1
with: 1
word: 100000
wordcount_test.txt: 1
you: 2
```


Correct Implentation of squarer to test:
```cpp
// squarer.h - Correct version
// A simple class to square numeric values

#ifndef SQUARER_H
#define SQUARER_H

class Squarer {
public:
    // Function call operator to square a numeric value
    template<typename T>
    T operator()(const T & value) const {
        return value * value;
    }
};

#endif // SQUARER_H
```
Incorrect Implementation of squarer to test:
```cpp
// squarer.h - Incorrect version
// A simple class to square numeric values with intentional errors

#ifndef SQUARER_H
#define SQUARER_H

class Squarer {
public:
    // Function call operator with intentional errors
    template<typename T>
    T operator()(const T & value) const {
        // Error 1: Squaring is incorrectly implemented
        return value + value;

        // Error 2: Handling for negative values is incorrect (uncomment to test)
        // if (value < 0) return -value * value;

        // Error 3: Floating-point handling is incorrect (uncomment to test)
        // if (std::is_floating_point<T>::value) return value * value * value;
    }
};

#endif // SQUARER_H

```