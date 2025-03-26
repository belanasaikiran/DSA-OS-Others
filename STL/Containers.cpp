#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;


//  We cover:
//
// 1. Vectors
// 2. Lists
// 3. Deque
// 4. Stack
// 5. Queue
// 6. Priority
// 7. Set
// 8. Eraser
// 9. Multi-Set
// 10. UnOrdered-Set
// 11. Map
// 12. Multi-Map

//  Vectors
void explainVectors() {
  // Vector is a container that stores elements of the same type in a contiguous
  // memory location. It provides dynamic resizing and efficient element access.
  vector<int> v;
  v.push_back(1); // add element 1 to the vector

  v.emplace_back(2); // dynamically increases the size. Faster than push_back.

  vector<pair<int, int>> vec;
  vec.push_back({1, 2});
  vec.emplace_back(1, 2);

  vector<int> v1(5, 100); // 5 instances of values 100
  vector<int> v2(5);      // creates an array v2 of size 5 elements.

  vector<int> v3(5, 20);
  vector<int> v4(v1); // copies v3 to v3

  // ************** Iterator *********
  // Iterators point to the memory,


// 1. Begin
    vector<int>::iterator it = v.begin(); // it points to the memory address
    //  WE cant simply write it to print, so we need to de-reference it
    cout << *it << endl;

    //  to shift position in mrmoty
    it++;
    // ot
    it = it + 2;


// 2. End - v.end()
    //  NOTE: end doesn't point to the last element, it would point to last + 1. It points to memory location right after last element.
    it = v.end(); // it points to the memory address

// 3. rend() - reverse end - v.rend()
    // NOTE: it will be point to the position before begin
    //  It moves in reverse way.
    vector<int>::reverse_iterator rit = v.rend(); // NOTE: needs a different namespace.

// 4. rbeing() - in reverse order
 rit = v.rbegin();


 // 5. v.back()
    cout << v.back() << endl; // it prints the last element in the vector.


//  Iterate through the vector using iterator
for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    cout << *it << endl; // you need to de-reference it since it only has memory location of the element.
}

//  other way - recommended
for(auto it = v.begin(); it != v.end(); it++){
    cout << *it << endl;
}

// or even simple
for(auto it: v){
    cout << it << endl; // no need to de-reference with this method of looping
}

// ERASE:
// {10, 20, 12, 23}
v.erase(v.begin()+1); // deletes 20
// to delete multiple in sequence
// v.erase(start, end) but it deletes at memory locations
v.erase(v.begin() + 2, v.begin()+4); // deletes from 2nd element to 4th.


//  INSERT:
vector<int> vin(2, 100);
v.insert(v.begin(), 300); // insert 300 at first position.
// Given: {300, 100, 100}
v.insert(v.begin()+1, 2, 10);  // outputs by adding 2 10s after 1st element -> {300, 10, 10, 100, 100}

// COPY
vector<int> copy(2, 50); // {50, 50}
v.insert(v.begin(), copy.begin(), copy.end()); // at beginning, copies copy array to v array -> {50,50,300,10,10,100,100}

// if v has{10, 20}
cout << v.size();  // 2

// {10,20}
v.pop_back(); // pops last element -> {10}

// SWAP
// v1 -> {10, 20}
// v2 -> {30, 40}
v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}

v.clear(); // erases the entire vector

cout << v.empty();// returns true or false for empty vector.

}



void explainLists(){
    list<int> ls;

    //  also we have push_front and emplace_front
    // {2}
    ls.push_back(2); // uses a Doubly Linked List - easy
    ls.emplace_back(4); // {2, 4}

    ls.push_back(5); // {5, 2, 4}
    ls.emplace_front(); // {2, 4}

    // Same functions from vector are available
    // begin, end, rbegin, rend, clear, insert, size, swap

}


void explainDeQueue(){
    deque<int> dq;
    dq.push_back(1); // 1
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4);  // {4, 1, 2}
    dq.emplace_back(3); // {3, 4, 1, 2}

    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}

    dq.back();

    dq.front();

    // rest of the function are same as vector
    // begin, end, rbegin, rend, clea, insert, size, swap
}

void explainStack(){
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1
    st.push(3); // {3, 2, 1};
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // 5 ----;  NOTE: st[2] is invalid

    st.pop(); // st looks like {3, 3, 2, 1}

    cout << st.top(); // 3
    cout << st.size(); // 4

    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
};

void explainQueue(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(3); // {1, 2, 3}

    q.back() += 5; // {1, 2, 8 } 5+3 = 8

    cout << q.back(); // prints 8

    // Q is {1, 2, 8}
    cout << q.front(); // prints 1

    q.pop(); // 1 is out and we are left with {2, 8}

    cout << q.front(); // prints 2

    // size, swap, empty are same as swap
}



void priorityQueue(){
    // Uses Tree Data Structure inside
    // By default, Priority queue has largest element in the top. It actually used `MAX HEAP`.
    // **** MAX HEAP: default ****
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // prints 10 - since its the largest element in MAX Heap

    pq.pop(); // {8, 5, 2} - popped 10

    cout << pq.top(); // prints 8

    // Size, swap, empty functions are same as other data structures

    // ****** MIN HEAP *****
    // We can also use Min Heap to store in the order of minimum element first
    // use below definition format
    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(5); // {5}
    pqm.push(2); // {2, 5}
    pqm.push(8);  // {2, 5, 8}
    pqm.push(10); // {2, 5, 8, 10}

    cout << pqm.top(); // prints 2
}

void explainSet(){
    // Set has elements:
    // 1. Sorted
    // 2. Unique
    //
    // Even Set uses a tree data structure
    // **** LOG N - In set, everything takes O(log n) time. ****

    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    // Functionality of insert in vector can
    // be used also, that only increases efficiency

    // begin(), end(),rbegin(), rend(), size(), empty()
    // and swap() are same as above

    //  {1, 2, 3, 4, 5}
    auto it = st.find(3);

    // {1, 2, 3, 4, 5}
    it = st.find(6); // if element is not in the set, it will always return the location right after end. It points to memory at location after 5

    st.erase(5); // {1, 2, 3, 4} // deletes 5 // takes logarithmic time


    int count = st.count(1); // returns true or false if 1 exists or not

    it = st.find(3);
    st.erase(it); // takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2); // returns true
    auto it2 = st.find(4);  // returns true
    st.erase(it1, it2); // after erease -> { 1, 4, 5} [from first, to last] (deleted from 2 to 3)


    // ALos has:
    // lower_bound()
    // upper_bound()
    //  works similar to vectors
    //
    auto it3 = st.lower_bound(2);
    auto it4 = st.upper_bound(3);

}

void explainMultiSet(){
    // evertthing is same as a set
    // also stores duplicate elements
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}
    ms.erase(1); // all 1's are erased

    // let's say re-inserted
    int count = ms.count(1); // all 1's are counted

    // delete one occurence of 1
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);

    // rest of the operations are same as set
}


void unOrderedSet(){
    unordered_set<int> st;
    // same as set but not sorted. it is in randomized order
    // compared to set, it has better complexity in most cases, except some collisions can happen
    //But it will only have UNIQUE elements.
    // Time Complexity:
    // O(1) - All Operations are O(1)
    // only lower_bound() and upper_bound() do not work here.
    // ONly once in a blue moon, the time complexity goes to O(n) at worst worst case
}


void explainMap(){
    //  in Map, keys are unique
    // Stores everthing in container as {key, value} pairs
    // NOTE: Everthing is stored in a sorted order.
    map<int, int> mp;
    map<int, pair<int, int>> mp_pair;
    map<pair<int, int>, int> mp_pair2;

    mp[1] = 2;
    mp.emplace({3, 1}); // 3 is key, 1 is value
    mp.insert({2, 4}); // same

    // for pair based
    mp_pair[{2,3}] = 10;

    for(auto it: mp){
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[1];
    cout << mp[5]; // if element doesn't exists, it outputs 0

    auto it = mp.find(3);
    cout << *(it).second << endl;

    // lower bound
    it = mp.lower_bound(2);
    it = mp.upper_bound(3);

    // erase, swap, size, empty are same as above.
}

void explainMultiMa(){
    // everything same as map, but it can store duplicate keys
    // only mp[key] cannot be used
}

void explainUnOrderedMap(){
    // randomized for storage
    // has unique keys but not sorted
    // almost works - O(1) compared to maps (O(log n))
}
