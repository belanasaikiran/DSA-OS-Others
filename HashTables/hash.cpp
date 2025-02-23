// Making the size of memory is a prime number  to avoid collisions

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
  string key;
  int value;
  Node *next;

  Node(string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
  }
};

class HashTable {
private:
  static const int SIZE = 7;
  Node *dataMap[SIZE];

public:
  void printTable() {
    for (int i = 0; i < SIZE; i++) {
      cout << i << ":" << endl;
      if (dataMap[i]) {
        Node *temp = dataMap[i];
        while (temp) {
          cout << "  {" << temp->key << ", " << temp->value << "}" << endl;
          temp = temp->next;
        }
      }
    }
  }

  int hash(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      int asciiValue =
          int(key[i]); // this int converts the char to an ASCII int value;
      hash = (hash + asciiValue * 23) %
             SIZE; // 23 because its a random prime number which gives more
                   // randomness. It can be any prime number. and we can do
                   // modulo which returns the remainder of the operation.
    }

    return hash;
  }

  void set(string key, int value) {
    int index = hash(key); // we get the address where this key to store.
    Node *newNode = new Node(key, value);
    if (dataMap[index] == nullptr) { // if node not existing at the index
      dataMap[index] = newNode;
    } else { // if node already exists, we traverse from that node and find the
             // next available slot and insert this node over there.
      Node *temp = dataMap[index];
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  int get(string key) {
    int index = hash(key);

    Node *temp = dataMap[index];
    while (temp) { // if multiple key values exist at the index, we traverse
                   // through the nodes and find the key that is matching the
                   // node's key and return it.
      if (temp->key == key)
        return temp->value;
      temp = temp->next;
    }

    return 0;
  }

  vector<string> keys(){
      vector<string> allKeys;
      for(int i = 0; i < SIZE; i++){
          Node* temp = dataMap[i];
          while(temp){
            allKeys.push_back(temp->key);
            temp = temp->next;
          }
      }
      return allKeys;
  }

};

int main() {
  HashTable *myHashTable = new HashTable();

  myHashTable->set("nails", 100);
  myHashTable->set("tile", 59);
  myHashTable->set("lumber", 80);

  myHashTable->set("bolts", 200);
  myHashTable->set("screws", 140);

  myHashTable->printTable();

  cout << "Lumber: " << myHashTable->get("lumber") << endl;
  cout << "driver: " << myHashTable->get("driver") << endl;

  cout << "\nAll Keys: ";
  vector<string> myKeys = myHashTable->keys();
  for(auto key: myKeys){
      cout << key << " ";
  }
  cout << endl;

  return 0;
}
