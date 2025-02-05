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
#include <string>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;



class Solution {
private:

public:

    int myMax(const int &a, const int &b){
        if(a>b){
            return  a;
        } else {
            return b;
        }
    }

    // Using Sliding Window and Set.
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return  0;
        }
        if(s.length() == 1){
            return 1;
        }
        int maxLength = 0;
        int left = 0;
        unordered_set<char> set;
        for(int i = 0; i < s.length(); i++){ // i can be right
            // duplicate found.
            // Here, you check if the value is present in set and if yes, we remove the left most element and incremnt left
            // and we keep checking until the while condition is not satisfied.
           while(set.find(s[i]) != set.end()){
               set.erase(s[left]);
               left++;
           }
           set.insert(s[i]);
           maxLength = myMax(maxLength, i - left + 1);
        };
        return maxLength;
    };


    int lengthOfLongestSubstringUsingHashMap(string s){
        if(s.empty()){
            return  0;
        }
        if(s.length() == 1){
            return 1;
        }

        int maxLength =0;
        int left = 0;

        unordered_map<char, int> map;
        // element = `right`
        for(int element = 0; element < s.length(); element++ ){
            if(map.find(s[element]) != map.end()){ // found
                /// moving left to avaoid duplicate values
                left = myMax(left,map[s[element]] + 1); // gives me the integer value of key
            }

            map[s[element]] = element; // store/update the last seen index
            maxLength = myMax(maxLength, element - left + 1);
        }

        return maxLength;



    }
};




// Unit Test helper
int unitTest( string str){
    Solution* object = new Solution;
    // cout << "Output: " << object->lengthOfLongestSubstring(str) << endl;

    int count = object->lengthOfLongestSubstringUsingHashMap(str);
    cout << "count: " << count << endl;

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
    assert(unitTest("dvdf") == 3);
    assert(unitTest("pwwkew") == 3);

}
