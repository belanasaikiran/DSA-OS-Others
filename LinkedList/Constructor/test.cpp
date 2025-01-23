#include <iostream>
#include "LinkedList.cpp"

using namespace std;


//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+


static void test() {
    
    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test 1: InitializesHeadCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesHeadCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Head Value: 5\n";
        cout << "Actual Head Value: " << ll.getHead()->value << "\n";

        checkTestResult(ll.getHead()->value == 5);
    }

    // Test 2: InitializesTailCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesTailCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Tail Value: 5\n";
        cout << "Actual Tail Value: " << ll.getTail()->value << "\n";

        checkTestResult(ll.getTail()->value == 5);
    }

    // Test 3: InitializesLengthCorrectly
    {
        cout << "\n------ LinkedList Test: InitializesLengthCorrectly ------\n";
        
        LinkedList ll(5);
        
        cout << "Expected Length: 1\n";
        cout << "Actual Length: " << ll.getLength() << "\n";

        checkTestResult(ll.getLength() == 1);
    }

    // Test 4: HeadAndTailAreTheSameNode
    {
        cout << "\n------ LinkedList Test: HeadAndTailAreTheSameNode ------\n";
        
        LinkedList ll(5);
        
        cout << "Checking if head and tail point to the same node...\n";
        
        checkTestResult(ll.getHead() == ll.getTail());
    }
    
}

