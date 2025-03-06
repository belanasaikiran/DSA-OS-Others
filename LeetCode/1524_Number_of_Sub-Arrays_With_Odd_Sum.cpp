#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    vector<int> AllSubArrays;

    int left = 0, right = 0;
    for (long long itr : arr) {
      int val = 0;
      right = left;
      while (right < arr.size()) {
        if (left == right) {
           val = itr;
        } else {
            val = val + arr[right];
        }
        if(val%2!=0) AllSubArrays.push_back(val);
        right++;
      }
      left++;
    }
    // std::cout << AllSubArrays.size() << endl;

    return AllSubArrays.size();
  }
};

// O(m * log n)

int main() {
  vector<int> arr = {1, 3, 5};
  vector<int> arr2 = {2,4,6};
  vector<int> arr3 = {1,2,3,4,5,6,7};

  Solution *mySol = new Solution;
  assert(mySol->numOfSubarrays(arr) == 4);
  assert(mySol->numOfSubarrays(arr2) == 0);
  assert(mySol->numOfSubarrays(arr3) == 16);

}
