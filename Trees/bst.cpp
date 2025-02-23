#include <iostream>
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

//  Head is a requirement but tail isn't for BST
// Head is root here

class BinarySearchTree {
public:
  Node *root;

public:
  BinarySearchTree() {
    // We can have nullptr to root in constructor if we want an empty BST.
    root = nullptr; // same format as LinkedList
  }

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

  bool contains(int value) {
    Node *temp = root; // if root is null, whilw won't execute. Clean Code to skip an other check.
    while (temp) {
      if (value < temp->value) {
        temp = temp->left;
      } else if (value > temp->value) {
        temp = temp->right;
      } else { // if found
        return true;
      }
    }

    return false;
  }
};

int main() {
  BinarySearchTree *myBST = new BinarySearchTree();

  myBST->insert(47);
  myBST->insert(18);
  myBST->insert(76);
  myBST->insert(18);
  myBST->insert(52);
  myBST->insert(82);

  myBST->insert(27);

  cout << myBST->root->left->right->value << endl;

  cout << "Contains 18 ? " << myBST->contains(18) << endl;
}
