#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(std::vector<int> &a, std::vector<int> &b) {
        // Your code here

        // Using UnOrdered-Map:
        // Easiest way is to store elements of a in an unordered-map which takes O(n)
        // and we can just check each element of b in the map where each
        // element check takes O(1) and with m elements it takes O(m).
        // So, in total it takes O(n) if n > m or vice versa

        // init unordered map
        std::unordered_map<int, int> mp;
        // we store all values of a in the map
        for(int i =0; i < a.size(); i++){
            mp[a[i]] = i;
          
        }
        
        // now, we can check if each element of b is in map. 
        for(int i = 0; i < b.size(); i++){
            if(mp.find(b[i]) == mp.end()){
                return false;
            }
        }

        return true;
    }
};


bool unitTest(std::vector<int> &a, std::vector<int> &b){
    Solution* object = new Solution;

    bool out = object->isSubset(a, b);
    delete object;
    return out;
}


int main(){

    std::vector<int> a = {1, 2, 4,6, 78, 96};
    std::vector<int> b = {1, 2, 6, 96};

    assert(unitTest(a, b) == true);


    std::vector<int> c = {1, 2, 3, 4, 4, 5, 6};
    std::vector<int> d = {1,2, 4};

    assert(unitTest(c, d) == true);

    std::vector<int> e = {10, 5, 2, 23, 19};
    std::vector<int> f = {19, 5, 3};

    assert(unitTest(e, f) == false);


    return 0;


}