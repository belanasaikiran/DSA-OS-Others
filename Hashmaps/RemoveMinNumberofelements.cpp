// Given two arrays arr1[] and arr2[], the task is to find the minimum number of elements to remove from each array such that no common elements exist between the two arrays.

// Examples:

// Input: arr1[] = [2, 3, 4, 5, 8], arr2[] = [1, 2, 3, 4]
// Output: 3
// Explanation: To remove all common elements, we need to delete 2, 3, and 4 from either array.

// Input: arr1[] = [1, 2, 3, 4], arr2[] = [5, 6, 7]
// Output: 0
// Explanation: There are no common elements between the arrays.

// Expected Time Complexity: O(n + m)
// Expected Auxiliary Space: O(n + m)

#include<iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>


class Solution {
  public:
    int minRemove(std::vector<int> &arr1, std::vector<int> &arr2) {
        // code here
        //
        // int counter = 0;
        // for(int i = 0; i < arr1.size(); i++){
        //     for(int j = 0; j < arr2.size(); j++){
        //         if(arr1[i] == arr2[j]){
        //             counter++;
        //             break;
        //         }
        //     }
        // }
        //
        //
        std::unordered_map<int, int> countA, countB;

        // store frequency
        for(int i =0; i < arr1.size(); i++){
            countA[arr1[i]]++;
        }

        for(int i =0; i < arr2.size(); i++){
            countB[arr2[i]]++;
        }

        int ans = 0;

        for(auto it: countA){
            if(countB.find(it.first) != countB.end()){ // element is available
                ans += std::min(it.second, countB[it.first]); // it.second is value and it.first is key
            }
        }

        return  ans;

    };
};
