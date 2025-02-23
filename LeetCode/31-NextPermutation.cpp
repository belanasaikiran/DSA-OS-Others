#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {





    }


    void swap(int index, int j, vector<int>&nums){
        int temp = nums[index];
        nums[index] = nums[j];
        nums[j] = temp;
    }


};

int main(){

    Solution S;
    vector<int> caller = {1, 2, 3};

    return 0;
}
