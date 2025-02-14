#include<iostream>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
// Brute Force Method
    string longestPalindrome(string s) {
        if(s.empty())  return "";
        // for(auto i : s){
        //     cout << i << endl;
        // }
        for(int length = s.length(); length > 0; length--){
            for(int start = 0; start <= s.length() - length; start ++){
                if(isPalindrome(s, start, (start+length)-1)){
                    return s.substr(start, length);
                }
            }
        }
        return "";

    }

private:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
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
