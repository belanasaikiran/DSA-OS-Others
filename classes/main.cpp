#include<iostream>

using namespace std;

class Cookie{
	
	// attribute
	private:
		string color;

	public:
	// constructor: has smae name as class name and is the default function called when instance is created. So it needs color argument 
		Cookie(string color){
			this->color = color;
			cout << "Cookie created with Color: " << this->color << endl;
		}

		string getColor(){
			return color;
		}

		void setColor (string color){
			this->color = color;
		}
};

int main(){


// to create new cookie of the class. Needs to have pointer for the object -> Object is a cookie.
Cookie* cookieOne = new Cookie("green");

Cookie* cookieTwo = new Cookie("blue");


cout << "C1: " << cookieOne->getColor() << endl;
cout << "C2: " << cookieTwo->getColor() << endl;

//updating the color value for cookie one 
cout << "Updating the cookie one value to yellow" << endl;
cookieOne->setColor("Yellow");

cout << "C1: " << cookieOne->getColor() << endl;
};



// NOTE: Classes help in creating Linked List also.
// LinkedList: The class has default constructor to take first value, has functions to append, prepend, insert, delete, remove Last
