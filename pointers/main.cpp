#include <iostream>

using namespace std;

int main(){
	int* num1 = new int(11);
	int* num2 = num1;

	// dereference gives the value 
	cout << "num1 = " << *num1 << endl;
	
	// no dereference gives address
	cout << "address of num1 = " << num1 << endl;

	cout << "num2 = " << *num2 << endl;
	cout << "address of num2 = " << num2 << endl;


	cout << "updating num2 and calling num1" << endl;

	*num2 = 22;

	cout << "num1 = " << *num1 << endl;

	return 0;
}
