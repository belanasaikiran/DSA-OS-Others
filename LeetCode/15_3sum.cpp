#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

      // if dealing with same number - no need to check it.
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int left = i + 1;
      int right = nums.size() - 1; // come from last

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          answer.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;

          // if you find the left and the one before is the same, skip it
          while (left < right && nums[left] == nums[left - 1])
            left++;
        }
      }
    }

    return answer;
  }


  vector<vector<int>> BruteForce(vector<int>& nums) {
      set<vector<int>> uniqueTriplets;
      vector<vector<int>> answer;
      // Brute force
      for(int i = 0; i < nums.size(); i++){
          for(int j = i+1; j < nums.size(); j++){
              for(int k = j+1; k < nums.size(); k++){
                  int sum = nums[i] + nums[j] + nums[k];
                  if(sum == 0) {
                      vector<int> triplet = {nums[i], nums[j], nums[k]};
                      sort(triplet.begin(),triplet.end());
                      uniqueTriplets.insert(triplet);
                  }
              }
          }
      }

      for(const auto& eachTriplet : uniqueTriplets){
          answer.push_back(eachTriplet);
      }

      return answer;
  }
};
