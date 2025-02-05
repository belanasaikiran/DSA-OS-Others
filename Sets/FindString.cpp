#include <iostream>
#include <set>
using namespace std;

int main(){
    string test = "THis is a test iil hdh";
    // Check if below `find` string present in `test` string
    string find = "hello";
    set<char> findLetters;


    for(int i=0; i < find.length(); i++){
        char letter = find[i];
        findLetters.insert(letter);
    }

    for(int i =0; i < test.length(); i++){
        char letter = test[i];
        findLetters.erase(letter);
    }

    if(findLetters.size()  > 0){
        cout << "No! IT does not have all letters\n";
    } else{
        cout << "YES! It does\n";
    }

}
