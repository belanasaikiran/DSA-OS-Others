#include<iostream>
#include <string>

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// The below is my way but not efficient - I tried it without taking any help. The issue is with stoi for larger numbers.
// Even though the time complexity is O(n) but it actually is 4 * O(n); we can do better with digit by digit addition
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string l1String = "", l2String = "";

        ListNode* temp = l1;
        while(temp) {
            l1String = to_string(temp->val) + l1String;
            temp = temp->next;
        }
        cout << "L1String: " << l1String << endl;

        temp = l2;
        while(temp) {
            l2String = to_string(temp->val) + l2String;
            temp = temp->next;
        }
        cout << "L2String: " << l2String << endl;

        // convert string to int
        int num1 = stoi(l1String);
        int num2 = stoi(l2String);

        int result = num1 + num2;
        string resultString = to_string(result);

        cout << "Res: " << resultString << endl;

        ListNode* resultList = new ListNode(resultString.back() - '0');
        ListNode* tempRes = resultList;
        cout << resultList->val << endl;

        for(int i = resultString.length() - 2; i >= 0; i--){
            tempRes->next = new ListNode(resultString[i] - '0');
            cout << i << ": " <<  resultString[i] << endl;
            tempRes = tempRes->next;
        }

        ListNode* printer = resultList;
        cout << printer->val << endl;
        while(printer->next){
            printer = printer->next;
            cout << printer->val << endl;

        }

        return resultList;

    }
};


int main(){

    Solution* newSol = new Solution;

    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    newSol->addTwoNumbers(l1, l2);


    return 0;
}
