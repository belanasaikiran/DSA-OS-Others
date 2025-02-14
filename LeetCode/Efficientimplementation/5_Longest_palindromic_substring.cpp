#include<iostream>
#include <string>
using namespace std;

// Solving this problem in O(n^2) instead of O(n^3) which uses brute force method.

class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int resLength = 0;
        if(s.empty()) return result;


        for(int i =0; i < s.length(); i++){
            // Odd length Palindrome
            int left = i, right = i;
            while(right < s.length() && left >= 0 && s[left] == s[right]){
                if((right - left + 1) > resLength){
                    resLength = right - left + 1;
                    result = s.substr(left, resLength);
                }
                right++;
                left--;
            }

            // Even length Palindrome
            left = i, right = i + 1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if((right - left + 1) > resLength){
                    resLength = right - left + 1;
                    result = s.substr(left, resLength);
                }
                right++;
                left--;
            }
        }
        return result;
    }
};


int main(){
    Solution* mySol = new Solution;

    string s = "ababa";
    cout << "Given: "<< s << endl;

    string answer = mySol->longestPalindrome(s);
    cout << "answer: " << answer << endl;

    return 0;

}
