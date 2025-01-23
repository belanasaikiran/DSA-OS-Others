/*Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6) - each is the range!!!!!!
*/



#include <iostream>
#include<unordered_map>
#include<assert.h>


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
      // Create an unordered map to store the frequency of prefix sums
      std::unordered_map<int, int> mp;
      // Initialize sum to 0
      int sum = 0;
      // Initialize answer to store the count of subarrays
      long long answer = 0;

      // Initialize the map with sum 0 having frequency 1
      mp[0] = 1;

      // Traverse through the array
      for(int i = 0; i < n; i++){
        // If the current element is 0, treat it as -1
        if(arr[i] == 0){
          sum -= 1;
        } else {
          // If the current element is 1, add 1 to sum
          sum += 1;
        }

        // Check if the current sum has been seen before
        if(mp.find(sum) != mp.end()){
          // If yes, add the frequency of the current sum to the answer
          answer += mp[sum];
          // Increment the frequency of the current sum
          mp[sum]++;
        } else {
          // If no, initialize the frequency of the current sum to 1
          mp[sum] = 1;
        }
      }

      // Return the total count of subarrays with equal number of 0s and 1s
      return answer;
    }


        // WE can use Hash maps
        
        
  };


// Unit Test helper
int unitTest(int arr[], int n){
    Solution* object = new Solution;

    int maxDist = object->countSubarrWithEqualZeroAndOne(arr, n);
    delete object;
    return maxDist;
}


  int main(){

    int arr[] = {1,0,0,1,0,1,1};
    int n = 7;

    assert(unitTest(arr, n) == 8);

    std::cout << "Done\n";
  
    return 0;
  }