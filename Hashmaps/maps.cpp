#include<iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> mp = {
        {'T', 4},
        {'b', 3},
        {'g', 7},
};

// mp['a']= 9;
// or
// mp.insert(pair<char, int> ('a', 9));
// or
pair<char, int> p1('a', 9);
mp.insert(p1);
cout << mp['a'] << endl;
cout << p1.first << endl;
cout << p1.second << endl;


// Size of map
cout <<mp.size()<< endl;

// loop through the map
// Below format of format gives an interator object. for (i = 0, i< .....) won't work
// If we have a collection data type, its better to use iterator and it loops throught the structure. Elements are not accessed based on indicies.
// We don't know the first pair is. When incremtned the itr, it will move to the next pair  but there is no order.
// The for loop structure works on other data collection types too like sets.
for(auto itr = mp.begin(); itr != mp.end(); itr++){
    // ITR will be a pointer to the first, second, etc...
    // cout << (*itr).second << " ";
    // or
    cout << itr->first << " ";
    // (*itr).second = itr->second; // LHS or RHS is same


    cout << (*itr).second << endl;

}


// empty the map.
mp.clear();
// check
cout << mp.empty() << endl; //returns 1 if true



}
