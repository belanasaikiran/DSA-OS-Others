
// How LinkedList can be implemented using Classes
class LinkedList{
	LinkedList(int value){
    // create new node
  }
  void append(int value) {
        // create new node
        // add node to end
  }
  void prepend(int value){
        // create new node
        // add node to beginning
  }
  bool insert(int index, int value) {
        // create new node
        // inset node
  }

  // All of them have the same 
  // arguments and they need a same operationg such as creating new node - common case
};


// other way using defined class - eliminate a 

// Separating creating new node
//

class Node {
  public: 
    int value;
    Node* next;

    Node(int value){
      this->value = value; // thi->value is the one we created above. Separates the argument passed in constructor from original variable
      this->next = nullptr;
    }
}


class LinkedList{
	LinkedList(int value){...}
  void append(int value) {..}
  void prepend(int value){..}
  bool insert(int index, int value) {..}

};
