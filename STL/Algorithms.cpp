#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    if(p1.second == p2.second) {
        if(p1.first > p2.second){
            return true;
        }
    }
    return false;
}

void explainExtraSTL(){
    int a[] = {1, 2, 3, 4};
    int n = 2;
    // ***************
    // **** SORT: ****
    // ***************
    sort(a, a+n); // start, end (sort-> array a to a + 2)

    //  Can use SORT on all containers
    sort(a+2, a+4); // sort from 2 to 4

    // sort in descending order
    //  std::sort(nums.begin(), nums.end(), std::greater<int>());
    sort(a, a+n, greater<int>()); // sort in descnending order

    // EXAMPLE
    pair<int, int> a2[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending order
    sort(a2, a2+n, comp);// comp is a self written comparator

    // **************
    //  ** BINARY COUNT of 1s for a given number
    // **************
    //  EXAMPLE
    // {4, 1}, {2, 1}, {1, 2}
    int num = 7; // in binary - 111
    int count = __builtin_popcount(num); // returns how many 1s for the number in binary

    long long num1 = 165786578456;
    int cnt = __builtin_popcountll(num1); // for long long, use ll

    // ********************************************
    // ** NEXT PERMUTATION - `next_permutation`
    // ********************************************
    //  EXAMPLE
    string s = "123";

    do{
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    //  what if the string is
    s = "231";
    // next_permutation(s.begin(), s.end());  in do-while,
    // only prints {3, 1, 2}, {3,2,1} - not the {1, 2, 3}, etc...
    // make sure to sort the list first before doing permuations
    //
    // -> sort
    sort(s.begin(), s.end());
    // -> now use do-while and it prints all permutations

    // ******************
    //  ** MAX ELEMENT **
    // ******************
    // Example: {1, 10, 5, 6}
    int maxi = *max_element(a, a+n); // {start iterator, end iterator} to get max element

    // *******************
    //  ** MIN ELEMENT: **
    // *******************
    int mini = *min_element(a, a+n);

}
