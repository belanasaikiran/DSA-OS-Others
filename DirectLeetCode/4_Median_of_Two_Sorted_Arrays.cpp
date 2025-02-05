#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// This is
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // now sort the elements in vector nums1
        std::sort(nums1.begin(), nums1.end());

        // now nums1 has all the elements
        // checker
        // for(auto& it : nums1){
        //      cout << it << endl;
        // };

        int numssize = nums1.size();
        // cout << "size: "<<  numssize << endl;

        if((numssize % 2) == 0){
            // it's even
            int a = nums1[nums1.size()/2  - 1];
            int b = nums1[nums1.size()/2];
            return (double) (a + b)/2;
        } else{
            return nums1[(numssize/2)];
        }

    };
};


int main(){

    Solution* mySol = new Solution;

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3, 4};

    double answer = mySol->findMedianSortedArrays(nums1, nums2);
    cout << "Answer: " << answer << endl;
    return 0;
}
