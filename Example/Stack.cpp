#include "../include/UnitTest.hpp"

template <class Data>
class Stack {
   private:
    class Node {
        friend class Stack;

       private:
        Node* Previous = nullptr;
        Data  Value;
    };

    Node*  Tail;
    size_t Size;

   public:
    Stack() {
        this->Tail = nullptr;
        this->Size = 0;
    }

    void push(Data Element) {
        this->Size++;

        Node* newNode = new Node;
        newNode->Value = Element;
        newNode->Previous = this->Tail;

        this->Tail = newNode;
    }

    Data top() {
        return this->Tail->Value;
    }
    Data pop() {
        if (this->size() <= 0) {
            throw std::out_of_range("Tried to pop empty Stack");
        }

        this->Size--;
        Data Value = this->Tail->Value;

        Node* BeforeLast = this->Tail->Previous;
        delete this->Tail;
        this->Tail = BeforeLast;

        return Value;
    }

    size_t size() {
        return this->Size;
    }

    bool isEmpty() {
        return this->Tail == nullptr;
    }
};

// Inherit from UnitTest
class StackTester : public UnitTest {
   private:
    Stack<int> theStack;

    // Runs before each test function
    void Before() override {
        this->theStack = Stack<int>();
    }

   public:
    StackTester() {
        // Sets the title to Stack
        this->SetTitle("Stack");

        // Adds the test function
        this->AddTestFunction("Create an empty Stack", [this]() {
            assert(this->theStack.isEmpty());
            assert(this->theStack.size() == 0);
        });

        // Adds the test function
        this->AddTestFunction("One push", [this]() {
            assert(this->theStack.isEmpty());
            this->theStack.push(1);
            assert(this->theStack.size() == 1);
            assert(!this->theStack.isEmpty());
            assert(this->theStack.top() == 1);
        });

        // Adds the test function
        this->AddTestFunction("Two pushes", [this]() {
            assert(this->theStack.isEmpty());
            this->theStack.push(1);
            this->theStack.push(2);

            assert(!this->theStack.isEmpty());
            assert(this->theStack.size() == 2);

            assert(this->theStack.pop() == 2);

            assert(this->theStack.size() == 1);

            assert(this->theStack.pop() == 1);

            assert(this->theStack.isEmpty());
            assert(this->theStack.size() == 0);
        });

        // Adds the test function
        this->AddTestFunction("Exception tests", [this]() {
            try {
                this->theStack.pop();
                assert(0);
            } catch (const std::exception& e) {
            }
        });
    }
};

int main(int argc, char const* argv[]) {
    // Instantiating the tester
    StackTester StackTest;

    // Running All tests
    StackTest.RunAll();

    /* Output:
    Running tests for Stack:
        Create an empty Stack -> Passed
        One push -> Passed
        Two pushes -> Passed
        Exception tests -> Passed
    */

    return 0;
}
