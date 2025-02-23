#include <functional>
#include <iostream>

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
  Node *head;
  Node *tail;
  int length;

public:
  // Creation of Double Linked List
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  void printList() {
    Node *temp = head;
    while (temp) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }

  void append(int value) {
    Node *newNode = new Node(value);

    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  void deleteLast() {
    if (length == 0)
      return;
    Node *temp = tail;

    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = temp->prev;
      tail->next = nullptr;
    }

    delete temp;
    length--;
  }

  void prepend(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
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
      head->prev = nullptr;
    }
    delete temp;
    length--;
  }

  Node *Get(int index) {
    if (index < 0 || index >= length) {
      return nullptr;
    }
    Node *temp = head;
    if (index < length / 2) {
      for (int i = 0; i < index; i++) {
        temp = temp->next;
      }
      return temp;
    } else {
      // but if we want to get 3rd, it's efficient to come from tail
      temp = tail;
      for (int i = length - 1; i > index; i--)
        temp = temp->prev;
    }

    return temp;
  }

  bool Set(int index, int value) {
    Node *temp = Get(index);
    if (temp == nullptr) {
      return false;
    } else {
      temp->value = value;
    }
    return true;
  }

  bool insert(int index, int value) {

    if (index < 0 || index > length)
      return false;
    if (index == 0) {
      prepend(value);
      return true;
    }
    if (index == length) {
      append(value);
    }
    Node *before = Get(index - 1);
    Node *after = before->next;
    Node *newNode = new Node(value);
    newNode->next = after;
    newNode->prev = before;
    before->next = newNode;
    after->prev = newNode;
    length++;
    return true;
  }


  void deleteNode(int index){
      if (index < 0 || index >= length)
        return;

      if(index == 0){
         deleteFirst();
         return;
      }
      if(index == length-1){
          deleteLast();
          return;
      }

      Node* temp = Get(index);
      // The below
      // Node* before = temp->prev;
      // Node* after = temp->next;
      // before->next = after;
      // after->prev = before;
      // or the below
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      delete temp;
      length--;
  }
};

int main() {
  DoublyLinkedList *myDoubleLinkedList = new DoublyLinkedList(1);
  myDoubleLinkedList->append(2);
  myDoubleLinkedList->append(3);
  myDoubleLinkedList->prepend(0);
  // cout << "got: " << myDoubleLinkedList->Get(1)->value << endl;
  // cout << "Set: " << myDoubleLinkedList->Set(1, 4) << endl;
  myDoubleLinkedList->insert(1, 4);
  // myDoubleLinkedList->deleteLast();
  // myDoubleLinkedList->deleteFirst();
  myDoubleLinkedList->printList();
  myDoubleLinkedList->deleteNode(3);
  cout << endl << endl;
  myDoubleLinkedList->printList();

  return 0;
}
