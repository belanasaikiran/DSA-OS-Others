#include <iostream>
using namespace std;


bool isPalindrome(string s){

    int left, right;

    for(int i = 0; i < s.length()/2; i++){
        left = i;
        right = (s.length() - 1) - left;
        // cout << "left : " << left << ", right: " << right << endl;
        // cout << "left : " << s[left] << ", right: " << s[right] << endl;
        if(s[left] != s[right])
            return false;
    }
    return true;

};

int main(){
    string s1 = "madam";
    string s2 = "smkdsnstar";

    cout << "s1: " << isPalindrome(s1) << endl;
    cout << "s2: " << isPalindrome(s2) << endl;

    return 0;
}
