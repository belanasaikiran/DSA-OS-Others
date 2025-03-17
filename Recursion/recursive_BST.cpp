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

  //  having two fucntions with same name but different paramaters - function overloading
  // Function Overloading: Two funcs have same name but different paramaters and different functionality
  bool rContains(Node* currentNode, int value){
      if(currentNode == nullptr) return false;

      if(currentNode->value == value ) return true;

      if(value < currentNode->value){
          return rContains(currentNode->left, value); // recursively call left
      } else{
          return rContains(currentNode->right, value);
      }
  }

  bool rContains(int value){
      return rContains(root, value); // Calls the top function - not recursive here
  }

  Node* rInsert(Node* currentNode, int value){
      if(currentNode == nullptr) return new Node(value);

      if(value < currentNode->value){
          currentNode->left = rInsert(currentNode->left, value);
      } else if(value > currentNode->value){
          currentNode->right = rInsert(currentNode->right, value);
      }
      return currentNode; // also for -> if equals, it just returns.
  }

  void rInsert(int value){
      if(root == nullptr) root = new Node(value);
      rInsert(root, value);
  }

  Node* deleteNode(Node* currentNode, int value){
      if(currentNode == nullptr) return nullptr;

      if(value < currentNode->value) {
          currentNode->left = deleteNode(currentNode->left, value);
      } else if (value > currentNode->value){
          currentNode->right = deleteNode(currentNode->right, value);
      } else {
          if(currentNode->left == nullptr && currentNode->right == nullptr){ // leaf Node
              delete(currentNode);
              return nullptr; // the parent would be pointed to same node even if deleted. so we return null.
          } else if(currentNode->left == nullptr){ // node on right
              Node* temp = currentNode->right;
              delete(currentNode);
              return temp; // points to right.
          } else if(currentNode->right == nullptr) { // node on left
              Node* temp = currentNode->left;
              delete(currentNode);
              return temp;
          } else {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
          }
      }
      return currentNode;
  }

  void deleteNode(int value){
      root = deleteNode(root, value);
  }

  int minValue(Node* currentNode) { // a helper function for delete Node
      while(currentNode->left != nullptr){
          currentNode = currentNode->left;
      }
      return currentNode->value;
  }

};

int main() {
  BinarySearchTree *myBST = new BinarySearchTree();

  myBST->rInsert(47);
  myBST->rInsert(18);
  myBST->rInsert(76);
  myBST->rInsert(18);
  myBST->rInsert(52);
  myBST->rInsert(82);

  myBST->rInsert(27);

  cout << myBST->root->left->right->value << endl;

  cout << "Contains 18 ? " << myBST->rContains(18) << endl;

  cout << "Min Value: " << myBST->minValue(myBST->root) << endl;
  cout << "Min Value: " << myBST->minValue(myBST->root->right) << endl;

}
