// 300. Longest Increasing Subsequence

/*
Given an integer array nums, return the length of the longest strictly increasing 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector <int> res;


        for(int n : nums){
            if(res.empty() || res.back() < n){ // if empty or last element is smaller than current one, we just add it to array
                res.push_back(n);
            } else{
                int index = binarySearch(res, n); // send that specific value to binary search to replace it
                res[index] = n;
            }
        }
        
        return res.size(); // returning the size of the array
    }

private:
    int binarySearch(const vector<int>& arr, int target){
        int left = 0;
        int right = arr.size() - 1; // last element location

        while (left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target){
                right = mid - 1; // seaching on left half
            } else {
                left = mid + 1; // search on right half
            }
        }

        return left;
    
}
};
