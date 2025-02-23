#include <iostream>
#include <limits.h>
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

class Stack {
private:
  Node *top; // equivalent of head in LL
  int height;

public:
  Stack(int value) {
    Node *newNode = new Node(value);
    top = newNode;
    height = 1;
  }

  ~Stack(){
      Node* temp = top;
      while(temp){
          Node* te = temp;
          temp = temp->next;
          te->next = nullptr;
          delete te;
      }
  }

  void printStack() {
    Node *temp = top;
    while (temp) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }

  void getTop() { cout << "Top: " << top->value << endl; }

  void getHeight() { cout << "Height: " << height << endl; }

  void push(int value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
  }

  int pop() {
    if (height == 0)
      return INT_MIN;
    Node *temp = top;
    int poppedValue = temp->value;
    top = top->next;
    delete temp;
    height--;
    return poppedValue;
  }
};

int main() {
  Stack *myStack = new Stack(1);
  // myStack->getTop();
  // myStack->getHeight();
  // PUSH
  // myStack->push(0);
  // POP
  // cout << "Popped Value: " << myStack->pop() << endl;
  // cout << "Popped Value: " << myStack->pop() << endl;
  //
  //
  //

  myStack->printStack();

  return 0;
}
