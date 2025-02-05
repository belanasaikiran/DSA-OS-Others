/*
 * Given a string s, find the length of the longest
substring
without repeating characters.


Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring
*/


// ##################################################################################
// THis file have naive implementation, helps me to learn writing unit tests in c++
// ##################################################################################



#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

// Probably, my solution could be a naive implementation - better implementation needs Hashmap
class Solution {

private:
      	vector<string> Returned_Arr;

public:
    int lengthOfLongestSubstring(string s) {
        vector<string> Returned_Arr;

        // Default Case when string is null or just 1
        if(s.length() == 0){
            return 0;
        } else if(s.length() == 1){
            return 1;
        }


        int k = 0;

        for(int i=0; i < s.length(); i++){
            Returned_Arr.push_back(""); // empty string for every iteration
            Returned_Arr[k] += s[i];

// pwwkew
            for(int j=i+1; j < s.length(); j++){

                if(Returned_Arr[k].find(s[j]) == string::npos){ // does not exist
                    Returned_Arr[k] += s[j];

                } else {  // if existing string has the letter, we skip it
                    // k++;
                    break;
                }
        }
        k++;
        }

        // for(int i = 0; i < Returned_Arr.size(); i++){
        //     cout << Returned_Arr[i] << endl;
        // }

        int returner = 0;

         for(int i = 0; i < Returned_Arr.size(); i++){
            if(returner < Returned_Arr[i].size()){
                returner = Returned_Arr[i].size();
            }
        }

        return returner;
    }
};




// Unit Test helper
int unitTest( string str){
    Solution* object = new Solution;
    // cout << "Output: " << object->lengthOfLongestSubstring(str) << endl;

    int count = object->lengthOfLongestSubstring(str);
    delete object;
    return count;
}

int main(){

//   string s = "abcabcbb";
//   std::cout << "s: " << s << endl;
//   Calling the function
//   Creating the instance before Calling
//   Solution* obj1 = new Solution;
//   int returner = obj1->lengthOfLongestSubstring(s);
//   std::cout << "Solution is " << returner << std::endl; 
//   Freeing the memory
//   delete obj1;



    //  unit tests caller
   
    assert(unitTest("abcabcbb") == 3);
    assert(unitTest("bbbb") == 1);
    assert(unitTest("pwwkew") == 3);

}


