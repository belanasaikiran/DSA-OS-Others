// Stack: Push for a Stack That Uses a Vector ( ** Interview Question)

// In the Stack: Intro video we discussed how stacks are commonly implemented using a vector instead of a Linked List.

// Write the push() method to add an item onto a stack that is implemented with a vector.

// Input:
// The function is a member of the Stack class, which has a private member stackVector, a vector<int> representing the stack.


// Output:
// The function should not return any value, but it should add the given value to the top of the stack.


// Constraints:
// The push() function should work correctly for stacks of any size, including empty stacks.


// Examples:

// Consider the following stack:

//     Stack:
//     5
//     4
//     3
//     2
//     1


// After calling push(6) with the Stack object, the stack should look like this:

//     Stack:
//     6
//     5
//     4
//     3
//     2
//     1



// Consider an empty stack:

//     Stack:


// After calling push(1) with the Stack object, the stack should look like this:

//     Stack:
//     1



#include <iostream>
#include <vector>

using namespace std;

class Stack {
    private:
        vector<int> stackVector;

    public:
        vector<int>& getStackVector() {
            return stackVector;
        }

        void printStack() {
            for (int i = stackVector.size() - 1; i >= 0; i--) {
                cout << stackVector[i] << endl;
            }
        }

        bool isEmpty() {
            return stackVector.size() == 0;
        }

        int peek() {
            if (isEmpty()) {
                return int();
            } else {
                return stackVector[stackVector.size() - 1];
            }
        }

        int size() {
            return stackVector.size();
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This method adds a new element to the top         |
        //   |   of the stack (push).                              |
        //   | - Inserts 'value' to the end of 'stackVector'.      |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Use vector's push_back() method to add            |
        //   |   the value to the end of the vector.               |
        //   | - No return value is needed.                        |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+

        void push(int value){
            stackVector.push_back(value);
        }

        void pop(){
            if(isEmpty()) return;
            stackVector.pop_back();
        }
};


int main(){

    Stack* newStack = new Stack;
    newStack->push(1);
    newStack->push(2);
    newStack->push(3);
    newStack->pop();
    newStack->printStack();


    return 0;
}
