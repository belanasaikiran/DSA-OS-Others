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


    // Append
    void append(int value){
      Node* newNode = new Node(value);
      if(length == 0){ // if LinkedList empty
        head = newNode;
        tail = newNode;
      }else {
        // take last node and append to it.
        tail->next = newNode;
        tail = newNode;
      }
      length++;

    }



    // Delete Last Node
    // Three cases:
    // 1. If lenght == 0
    // 2. If only one node exists - an edge case
    // 3. remove last item
    void deleteLast(){
        if(length == 0) return;
        // we have to traverse to the last element for linked list, we can't directly go to the last element, so start with head
        Node* temp = head;
        if(length == 1){ // if only one node exists - edge case
            head = nullptr;
            tail = nullptr;
        }else {
            Node* pre = head;
            while(temp->next){
                pre = temp;
                temp = temp->next;
            }
            tail = pre; // so now, tail will be the node before last
            tail->next = nullptr;
        }
        length--; // decrement the lenght
        delete temp;
    }



    // Prepend Node
    void prepend(int value){
        Node* newNode = new Node(value);
        if(length == 0){ // empty list
            head = newNode;
            tail= newNode;
        }else{
            newNode->next = head; // point the new node to the current head
            head = newNode; // update head
        }
        length++;
    }


    // Delete First Node
    void deleteFirst(){
        if(length == 0) return;
        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }else{ // if more than 1 node in list
            head = head->next;
        }
        length--;
        delete temp; // deleting the first node
    }

    // Get: here, we are returning Node, so we use Node* as datatype. We can also return a value if used as int instead of Node*, return would be temp->value.
    Node* Get(int index){

        if(index < 0 || index >= length)return nullptr; // if index out of range such as -1 or greater than length

        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }


    // Set: Setting value at given index
    bool Set(int index, int value){
        // WAY 1
        // if(index < 0 || index >= length) return false; // if index out of range such as -1 or greater than length
        // Node* temp = head;
        // for(int i = 0; i < index; i++){
        //     temp = temp->next;
        // }
        // temp->value = value;

        // WAY 2:
        // We can take advantage of Get here
        Node* temp = Get(index);
        if(temp){
            temp->value = value;
            return true;
        }
        return false;


    }

    // Insert: insert a new node at index
    bool Insert(int index, int value){

        if(index < 0 || index >= length) return false; // if index out of range such as -1 or greater than length
        if(index == 0){
            prepend(value);
            return  true;
        }

        // if index is last
        if(index == length){
            append(value);
            return true;
        }

        Node* temp = Get(index - 1);// we need to get the node before the index since it needs to point to the new node we create. it doesn't work with current index since the current index cannot know what's behind.
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;

    }

    // Delete Node at Index
    void DeleteNode(int index){
        if(index == 0) deleteFirst();
        if(index == length-1) deleteLast();

        // Else for other
        Node* prev = Get(index-1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }


    // Reverse
    void Reverse(){
        // point head to tail and viceversa.
       Node* temp = head;
       head = tail;
       tail = temp;

       // Now, reverse the next
       Node* after = temp->next;
       Node* before = nullptr;

       for(int i =0; i < length; i++){
           // The below needs to be exactly in an orders
           after = temp->next;
           temp->next = before; // set the next to before. Flips and points the other way
           before = temp;
           temp = after;
       }

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

  // append
  myLinkedList->append(5);
  myLinkedList->append(6);
  myLinkedList->append(7);

// Delete Last Node
  cout << "Before Delete Last Node\n";
  myLinkedList->printList();
  cout << "After Delete Last Node\n";
  myLinkedList->deleteLast();
  myLinkedList->printList();


  // Prepend Node
  cout << "After Prepend Node 3\n";
  myLinkedList->prepend(3);
  myLinkedList->printList();

  // Delete First
  cout << "Delete First(): \n";
  myLinkedList->deleteFirst();
  myLinkedList->printList();


  // Get
  cout << "Get value at index 2: ";
  int GetValue = myLinkedList->Get(2)->value;
  cout << GetValue << endl;

  // Set
  cout << "Set value at index 2 to 9: ";
  cout << myLinkedList->Set(2, 9) << endl;

  // Insert at index
  cout << "Insert new node at index 1 as 1:\n";
  myLinkedList->Insert(1, 1);


  cout << "Delete Node at index 2 \n";
  myLinkedList->DeleteNode(2);
  myLinkedList->printList();

  // Reverse the List
  cout << "Reversing the List\n";
  myLinkedList->Reverse();

  myLinkedList->printList();
  myLinkedList->getHead();
  myLinkedList->getTail();
  myLinkedList->getLength();



  // delete LinkedList by calling the Destructor
  delete myLinkedList;

  return 0;
}
