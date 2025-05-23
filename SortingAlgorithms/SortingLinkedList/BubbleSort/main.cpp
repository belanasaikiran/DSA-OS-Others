#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~LinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "empty";
    } else {
      while (temp != nullptr) {
        cout << temp->value;
        temp = temp->next;
        if (temp != nullptr) {
          cout << " -> ";
        }
      }
    }
    cout << endl;
  }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  int getLength() { return length; }

  void append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }

  void deleteFirst() {
    if (length == 0)
      return;
    Node *temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
    length--;
  }

  //   +=====================================================+
  //   |                WRITE YOUR CODE HERE                 |
  //   | Description:                                        |
  //   | - This method sorts the linked list using the       |
  //   |   Bubble Sort algorithm.                            |
  //   | - Starts at the head node and iteratively swaps     |
  //   |   adjacent nodes if they are in the wrong order.    |
  //   |                                                     |
  //   | Return type: void                                   |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Uses two nested while loops for iteration.        |
  //   | - Utilizes a 'sortedUntil' node to optimize.        |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  void bubbleSort() {
    if (length < 2)
      return;

    Node *sortedUntil = nullptr;

    while (sortedUntil != head->next) {
      Node *current = head;
      while (current->next != sortedUntil) {
        Node *nextNode = current->next;
        if (current->value > nextNode->value) {
          int temp = current->value;
          current->value = nextNode->value;
          nextNode->value = temp;
        }
        current = current->next;
      }
      sortedUntil = current;
    }
  }
};
