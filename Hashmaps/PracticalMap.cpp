#include <iostream>
#include <map>
#include <string>
using namespace std;


// number of times a char occurs
int main(){
    string test = "hello world, my name is sanju! ttthhhaaa";

    //  we can loop through the string once with a map
    map<char, int> freq;
    for(int i =0;  test.length(); ++i){
        char letter = test[i];
        // cout << letter <<endl;
        //
        // check if letter exist in map, if yes, we can increment the key by one. so the map has all the frequencies
        // if not existsing, we add the freq and element to map.
        if(freq.find(letter) == freq.end()){
            freq[letter] = 0;
        }
        freq[letter]++; // increment the number
        cout << freq[letter] << ", " <<  letter << endl;
    }

    for(auto itr = freq.begin(); itr != freq.end(); ++itr){
        cout << itr->first << ": " << itr->second << endl;
    }
}
