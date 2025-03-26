#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int value;
  Node *left;
  Node *right;

  Node(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

class TreeTraversal {

public:
  Node *root;

  bool insert(int value) {
    Node *newNode = new Node(value);
    if (root == nullptr) {
      root = newNode;
      return true;
    };

    Node *temp = root;
    while (true) {
      if (newNode->value == temp->value) {
        return false; // This is where the loop breaks.
      }

      // Going LEFT
      if (newNode->value < temp->value) {
        if (temp->left == nullptr) { // if there is not left node, add this node
                                     // to it's left pointer
          temp->left = newNode;
          return true;
        }
        temp = temp->left;
      } else { // GOING RIGHT
        if (temp->right ==
            nullptr) { // if no right pointer, add this node as the right child
          temp->right = newNode;
          return true;
        }
        temp = temp->right;
      }
    }
  }

  void BFS() {
    queue<Node *> myQueue;
    myQueue.push(root);
    while (myQueue.size() > 0) { // As long as I have some element in the Queue,
                                 // I keep running this loop
      Node* currentNode = myQueue.front();
      myQueue.pop(); // remove that node from here
      cout << currentNode->value
           << " "; // this is where we print all the nodes level by level.
      if (currentNode->left != nullptr) {
        myQueue.push(currentNode->left);
      }
      if (currentNode->right != nullptr) {
        myQueue.push(currentNode->right);
      }
    }
  }
};

int main() {
  TreeTraversal *myBFS = new TreeTraversal;
  myBFS->insert(47);
  myBFS->insert(21);
  myBFS->insert(12);
  myBFS->insert(76);
  myBFS->insert(14);
  myBFS->insert(27);
  myBFS->insert(52);
  myBFS->insert(82);


  myBFS->BFS();
}
