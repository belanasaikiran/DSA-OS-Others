// 88. Merge Sorted Array

// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150

//link: https://leetcode.com/studyplan/top-interview-150/

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        // zero replacement
        for (auto& i : nums1){
            for( auto& j : nums2){
                if(i == 0){
                    i = j;
                    // remove j from nums2
                    nums2.erase(std::find(nums2.begin(), nums2.end(), j));
                    break;
                }
            }
        }

        // at this step, I should get the nums1 as m + n size
        // actual merge sort on the final array

        // For merge sort, you need two functions -> one for mergesort and one for merge step.

        




        int mid = nums1.size() // 2;
        int left = 

   }
};
