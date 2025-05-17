#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

       int i = 0;
       int j = s.length() - 1;
       while(i < j){

            char c = s[i];
            cout << "c is: " << c << endl;

            while((c < 'A' || (c > 'Z' && c < 'a') || c > 'z')){
                i++;
                c = s[i];
            }
            cout << "c is: " << c << endl;

            char d = s[j];
            while((d < 'A' || (d > 'Z' && d < 'a') || d > 'z')){
                i++;
                d = s[j];
            }

            cout << "C: " << c << "\n D: " << d << endl;

            if(d != c) return false;
            i++;
            j--;
       }

       return true;
    }
};

int main(){

  Solution* sol = new Solution;

  cout << "T/F: " << sol->isPalindrome("Was it a car or a cat I saw?") << endl;
}
