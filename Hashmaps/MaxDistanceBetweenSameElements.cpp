#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>


/*
Given an array arr[], the task is to find the maximum distance between two occurrences of an element. 
If no element has two occurrences, then return 0.
*/
class Solution {
  public:
    int maxDistance(std::vector<int> &arr) {
        // Code here
        int maxDistance = 0;
        std::unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            //  check if element in map.
            // if doesn't exist, we can add the element to map
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            } else {
                maxDistance = std::max(maxDistance, i - mp[arr[i]]);
            }
        }

        return maxDistance;
    }
};



// Unit Test helper
int unitTest(std::vector<int> &arr){
    Solution* object = new Solution;

    int maxDist = object->maxDistance(arr);
    delete object;
    return maxDist;
}



int main(){

    std::vector<int> a = {1, 1, 2, 2, 2, 1};
    std::vector<int> b = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    std::vector<int> c = {1, 2, 3, 6, 5, 4};

    assert(unitTest(a) == 5);
    assert(unitTest(b) == 10);
    assert(unitTest(c) == 0);

    std::cout << "All Tests Done\n";

}