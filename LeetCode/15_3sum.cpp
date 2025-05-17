#include <iostream>
#include <vector>
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
};
