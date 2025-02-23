#include <climits>
#include <iostream>
using namespace std;



class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Queue{
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void printQueue(){
            Node* temp = first;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getFirst(){
            cout << "First: " << first->value << endl;
        }

        void getLast(){
            cout << "Last: " << last->value << endl;
        }

        void getLength(){
            cout << "length: " << length << endl;
        }

        void enqueue(int value){
            Node* newNode = new Node(value);
            if(length==0){
                first = newNode;
                last = newNode;
            } else{
                // it is efficient to add node at end and remove at first - O(1). Otherway is not.
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int dequeue(){
            if(length==0) return INT_MIN;
            Node* temp = first;
            int dequeuedValue = temp->value;
            if(length == 1){
                first = nullptr;
                last = nullptr;
            } else {
                first = first->next;
            }
            delete temp;
            length--;
            return dequeuedValue;
        }

};


int main(){

    Queue* myQueue = new Queue(1);

    // myQueue->getFirst();
    // myQueue->getLast();
    // myQueue->getLength();
    //
    myQueue->enqueue(2);
    myQueue->dequeue();
    myQueue->printQueue();

    return 0;
}
