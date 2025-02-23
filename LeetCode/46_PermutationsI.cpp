#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void swap(int index, int j, vector<int> &nums) {
    int temp = nums[index];
    nums[index] = nums[j];
    nums[j] = temp;
  }
  vector<vector<int>> permute(vector<int> &nums) {
    int p1 = 0;
    int p2 = 0;

    vector<vector<int>> returnAnswer;
    vector<int> temp = nums;
    returnAnswer.push_back(temp);
    for (p1 = 0; p1 < nums.size(); p1++) {
      for (p2 = 0; p2 < nums.size(); p2++) {
        temp = nums;
        int t = temp[p1];
        temp[p1] = temp[p2];
        temp[p2] = t;
        if (find(returnAnswer.begin(), returnAnswer.end(), temp) ==
            returnAnswer.end()) {
          returnAnswer.push_back(temp);
        }
      }
    }
  };

  int main() {

    Solution S;
    vector<int> caller = {1, 2, 3};

    return 0;
  }
