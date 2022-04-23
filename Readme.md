# CppUnitTest

A very basic unittester framework for C++.

## Installation

Download the include folder and you are ready to go.

## Usage

You can check the Example folder for examples.

You include the UnitTest.hpp header file. 
```cpp
#include "include/UnitTest.hpp"
```
Create a class
```cpp
class ExampleTester: public UnitTest{
    // Code
};
```
You need to set the title, essentially telling what do we test.
```cpp
//Constructor of ExampleTester
ExampleTester(){
    this->SetTitle("Example tester");
    //...
}
```
After this you can add test functions
```cpp
    //For example in the constructor
    this->AddTestFunction("This is a test function", [this]() {
            // The function body
            // Notice that when we create the lambda function 
            // we want to capture this
            // so we can acces the class member fields
        });
```
Additionally there is two functions which runs before and after each test function respectively, which you can override
```cpp
// The function headers look like this
void Before();
void After();
```
After this you can run all the tests, with the RunAll function
```cpp
int main(int argc, char const* argv[]) {
    ExampleTester Tester;
    Tester.RunAll(); // Runs all the test functions
    return 0;
}
```