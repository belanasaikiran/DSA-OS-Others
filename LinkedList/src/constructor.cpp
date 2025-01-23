#include<iostream>

using namespace std;

// Node Creation
class Node {
  public: 
    int value;
    Node* next;

    Node(int value){
      this->value = value; // thi->value is the one we created above. Separates the argument passed in constructor from original variable
      this->next = nullptr;
    }
};

// Creating a new LinkedList with it's default constructor calling Node
class LinkedList{
  private: 
    Node* head;
    Node* tail;
    int length;


  public:
    // default constructor
    LinkedList(int value){
      Node* newNode = new Node(value);
      head = newNode;
      tail = newNode;
      length = 1; // by default, we only have one node. So both head and tail points to this node
    };
 
    void printList(){
      Node* temp = head;
      while(temp){ // continues until next is a nullptr
        cout << temp->value <<endl;
        temp = temp->next;
      }
    };


    void getHead(){
      cout << "head: " << head->value << endl;
    }


    void getTail(){
      cout << "Tail: " << tail->value << endl; 
    }


    void getLength(){
      cout << "Length: " << length << endl;
    }


    // Destructor
    ~LinkedList(){
      Node* temp = head;
      while(head){ // breaks when head points to a nullptr
          head = head->next;
          delete temp;
          temp = head;
      }
    }
};


/*class LinkedList{
	LinkedList(int value){...}
  void append(int value) {..}
  void prepend(int value){..}
  bool insert(int index, int value) {..}
};
*/


int main(){
  LinkedList* myLinkedList = new LinkedList(4); // we just created a new LinkedList with the first node having value '4'. 
                                                // NOTE: Head and Tail are pointed to this node


  myLinkedList->printList();
  myLinkedList->getHead();
  myLinkedList->getTail();
  myLinkedList->getLength();







  // delete LinkedList by calling the Destructor
  delete LinkedList;

  return 0;
}



















