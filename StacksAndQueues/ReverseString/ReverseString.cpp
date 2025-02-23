#include "ReverseString.h"

string reverseString(const string& str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+

    stack<char> ourstack;

    // int lengthofString = str.length();
    // for(int i = 0; i < str.length(); i++){
    //     ourstack.push(str[i]);
    // }
    //
    for(char c : str){
            ourstack.push(c);
    }
    string reverse;
    while(!ourstack.empty()){
        reverse.push_back(ourstack.top());
        ourstack.pop();
    }

    return reverse;
}
