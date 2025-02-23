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
  int length;

public:
  LinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
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

  int getLength() { return length; }

  void makeEmpty() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
    length = 0;
  }

  void append(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *currentNode = head;
      while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
    length++;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Partition list around value x                      |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Create two dummy nodes for two new lists           |
  //   | - One list for nodes less than x                     |
  //   | - Another list for nodes greater or equal to x       |
  //   | - Loop through original list                         |
  //   | - Assign nodes to new lists based on value           |
  //   | - Merge the two new lists                            |
  //   | - Update the original list's head                    |
  //   +======================================================+

  void partitionList(int x) {
    if (head == nullptr)
      return;

    Node List1(0);
    Node *prev1 = &List1;
    Node List2(0);
    Node *prev2 = &List2;

    Node *temp = head;
    while (temp) {
      if (temp->value < x) {
        prev1->next = temp;
        prev1 = temp;
      } else {
        prev2->next = temp;
        prev2 = temp;
      }
      temp = temp->next;
    }

    prev2->next = nullptr; // for last node of right list(greater numbers)
    prev1->next = List2.next;
    head = List1.next;
  }
};

int main() {
  LinkedList *list = new LinkedList(3);
  list->append(8);
  list->append(5);
  list->append(10);
  list->append(2);
  list->append(1);

  list->partitionList(5);
  list->printList();

  return 0;
}
