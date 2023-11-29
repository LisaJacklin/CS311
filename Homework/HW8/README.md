## Procedures
- Your answers should consist of two files: wordcount.cpp, from Exercise A, and squarer_test.cpp, from Exercise B.

### Exercise A — Program: Counting Words

#### _Purpose_
In this exercise, you will write a program that uses a C++ STL Table implementation. Your program will also read information from a file. Robustness and proper error checking are an important part of the assignment.
Background
For the purposes of this exercise, a word is a contiguous sequence of one or more non-space characters.
For example, consider the following.
```
xyz/ xyz123 xyz
xyz123 xyz abc
```
The words in the above text, in lexicographic order, are abc, xyz, xyz/, and xyz123.
#### Instructions
Write a complete C++ program (including function main!) that inputs a filename from the user, and reads the named file. The program should then print the number of distinct words that appear in the file, followed by a list giving, for each word appearing, the word itself and the number of times it appears in the file, as shown below. Be sure to follow the coding standards. All standards apply!
    - Store the source for your program in a single file: wordcount.cpp.
    - Your program must store its results, prior to printing, in an appropriate STL Table container.
    - See the Testing section, below, for an example of the kind of output I am looking for.
    - Your program should be robust. That is, it should never crash, no matter what the user types, and no matter what it finds in the file.
#### __Testing__
Since you are writing a complete program this time, there will be no test program. However, I have created a test input file: wordcount_test.txt. (This file is also in the Git repository.) If you run your program with this file as input, then it should output the following.

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
Do not turn in wordcount_test.txt.

#### _Hints_
Using “cin >> ...” is almost never appropriate when reading from the user, because this reads individual words while users mostly think in terms of lines. Instead, use std::getline to grab a whole line at a time; then read from the string it gives you. 
To check for errors when using C++ streams, first use the “!” operator on the stream; then use member function eof.For example, if you have an ifstream called infile, then after every operation on infile, you should do
```cpp
if (!infile)
{
    ...
```  
This is a check for an error on the last operation. If this test succeeds (that is, if there was an error), and the operation was a read, then check for EOF next:  
```cpp
    if (infile.eof())
    {
        ...
```  
If this is true, then the error was due to the end of the file, and so there is nothing wrong with the file; just stop reading. On the other hand, if you get an error that is not due to EOF, then there is something wrong with the file (or the device, or the connection with the device, or ...).
    - Robustness means that the user is allowed to do strange things, and files are allowed to contain strange data, but the program never behaves badly. 
Test the strange cases. For example, what if the user, when prompted for a filename, just hits ENTER? What if they type a bunch of blanks and then hit ENTER? What about a filename with a blank in the middle? What about the name of a file that does not exist? A file that exists but cannot be read? An empty file? An executable file? a directory? Etc.



### Exercise B — Writing a Test Suite
#### Purpose
In this exercise, you will write a test suite for a simple C++ class. You will use the doctest testing framework.

#### Background
Consider a class Squarer. Objects of this class are function objects that compute the square of a numeric argument.
An object of type Squarer might be used as follows.

```cpp
Squarer sq;
int n = sq(5);    // Computes 5 squared: 125
int d = sq(1.1);  // Computes 1.1 squared: 1.331
```

A complete, correct definition of class Squarer can be found in file squarer.h, (This is in the repo).

#### Instructions
Modify the posted file squarer_test.cpp so that it, along with doctest.h, forms a thorough test program for class Squarer, contained in header file squarer.h.
- Your tests must use the doctest testing framework.
    - Each `REQUIRE` directive (or other similar directive: REQUIRE_FALSE, etc.) must have one or more associated INFO directives that give the user information for each failing test.
- Your test suite must address all of the following issues.
	- Do both const & non-const Squarer objects work?
	- Does Squarer work properly for a wide range of values?
	- Does Squarer work properly for both positive and negative values?
    - Does Squarer work properly for both integer and floating-point arguments?
    - Special cases of interest: the squares of 0, 1, and -1 should be correct.
    - When a test fails, is the message printed both correct and helpful?
- The compilation requirement in the coding standards, as applied to this exercise, means that your code must compile with doctest.h version 2 and a correctly written version of squarer.h.  
Do not turn in files doctest.h or squarer.h.

#### Hints
- For the basics of writing a test suite using doctest.h, see the lecture slides from November 29.
- Write both correct and incorrect versions of file squarer.h, and try out your test program with these.
