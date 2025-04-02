// # Given a sorted doubly linked list of positive distinct elements, the task
// is to find pairs in a doubly-linked list whose sum is equal to the given
// value x in sorted order.

// 1<-> 2 <-> 3 <->  4 <->  5

// X

#include <assert.h>
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Node {

public:
  int value;

  Node *next;

  Node *prev;

  Node(int value) {

    this->value = value;

    next = nullptr;

    prev = nullptr;
  }
};

class DoublyLinkedList {

private:
  int length;

  Node *head;

  Node *tail;

public:
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  };

  void append(int value) {

    Node *temp = head;
    Node *prevNode = nullptr;
    while (temp->next != nullptr) {
      prevNode = temp;
      temp = temp->next;
    }

    // last node
    Node *newNode = new Node(value);
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
    length++;
  }

  vector<pair<int, int>> answer(int x) {

    vector<pair<int, int>> returnFoundValues;

    Node *left = head;
    Node *right = tail;

    while (left != nullptr && right != nullptr) {

      // cout << "left: " << left->value << endl;
      // cout << "right: " << right->value << endl;

      int sum = left->value + right->value;
      // cout << "sum: " << sum << endl;

      if (sum > x) {
        right = right->prev;
      } else if (sum < x) {
        left = left->next;
      }
      if (left == right) { // skip the case if left == right
        right = right->prev;
        left = left->next;
      } else {
        pair<int, int> pairValues;
        pairValues.first = left->value;
        pairValues.second = right->value;
        returnFoundValues.push_back(pairValues);
        // cout << "pairs are: \n";
        // cout << left->value << ", " << right->value << endl;
        right = right->prev;
        left = left->next;
      }
    }
    return returnFoundValues;
  }
};

bool testCaseChecker(int x, DoublyLinkedList *DLL,
                     vector<pair<int, int>> *comparePair) {
  //  Call the class here.
  vector<pair<int, int>> answers = DLL->answer(x);
  cout << "Pairs matching " << x << ": \n";
  for (auto eachpair : answers) {
    cout << "[" << eachpair.first << ", " << eachpair.second << "] \n";
  }

  if (answers == *comparePair) {
    return true;
  }

  return false;
}

int main() {
  DoublyLinkedList *DLL = new DoublyLinkedList(1);
  DLL->append(2);
  DLL->append(3);
  DLL->append(4);
  DLL->append(5);
  vector<pair<int, int>> comparePair5 = {{1, 4}, {2, 3}, {3, 2}, {4, 1}};
  vector<pair<int, int>> comparePair6 = {{1, 5}, {2, 4}, {4, 2}, {5, 1}};

  cout << "Test Case for " << 5 << ": \n"
       << (testCaseChecker(5, DLL, &comparePair5) ? "PASSED : )" : "FAILED : (")
       << endl;
  cout << "Test Case for " << 6 << " - "
       << (testCaseChecker(6, DLL, &comparePair6) ? "PASSED : )" : "FAILED : (")
       << endl;
  // assert(comparePair5 ==  DLL->answer(5));
  // assert(comparePair6 ==  DLL->answer(6));

  return 0;
}
