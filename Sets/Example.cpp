#include <iostream>
#include <set>
using namespace std;

int main(){
    string test = "THis is a test iil";
    set<char> exists;

    for(int i =0; i < test.length(); i++){
        char letter = test[i]; // good practice
        exists.insert(letter);
    }

    for(auto itr = exists.begin(); itr != exists.end(); itr++){
        cout << *itr << endl;
    }
}
