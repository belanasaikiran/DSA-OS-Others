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

private:
  Node *root;

public:
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

  //  DFS Pre-order with a specific node and traverse down - treat the argument
  //  as the root node
  void PreOrder(Node *currentNode) {
    cout << currentNode->value << " ";
    if (currentNode->left) {
      PreOrder(currentNode->left);
    }
    if (currentNode->right) {
      PreOrder(currentNode->right);
    }
  }

  //  Function overloading without a root node
  void PreOrder() {
    // we pick the Root node and traverse through the entire tree
    PreOrder(root); // takes root here - NOTE: root is private here.
  }

  // We visit the Root Node only afte it's children are visited. Good for bottom
  // top traversal.
  void PostOrder(Node *currentNode) {

    if (currentNode->left) {
      PostOrder(currentNode->left);
    }
    if (currentNode->right) {
      PostOrder(currentNode->right);
    }
    cout << currentNode->value << " "; // moved down compared to pre-order
  }

  void PostOrder() {
    // we pick the Root node and traverse through the entire tree
    PostOrder(root); // takes root here - NOTE: root is private here.
  }

  void InOrder(Node *currentNode) {

    if (currentNode->left) {
      InOrder(currentNode->left);
    }
    cout << currentNode->value << " "; // moved down compared to pre-order

    if (currentNode->right) {
      InOrder(currentNode->right);
    }
  }

  void InOrder() {
    InOrder(root); // takes root here - NOTE: root is private here.
  }
};

int main() {
  TreeTraversal *myDFS = new TreeTraversal;
  myDFS->insert(47);
  myDFS->insert(21);
  myDFS->insert(76);
  myDFS->insert(18);
  myDFS->insert(27);
  myDFS->insert(52);
  myDFS->insert(82);

  // Root -> Left -> Right
  cout << "Pre Order: " << endl;
  myDFS->PreOrder();
  cout << endl;

  // Left -> Right -> Root
  cout << "Post Order: " << endl;
  myDFS->PostOrder();
  cout << endl;

  // Left -> Root -> Right
  cout << "In Order: " << endl;
  myDFS->InOrder();
  cout << endl;
}
