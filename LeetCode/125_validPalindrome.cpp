class Solution {
public:
    bool isPalindrome(string s) {

        vector<char> store;

        for (char c: s){
            c = tolower(c);
            if((c > 96 && c < 123) || (c > 47 && c < 58) ){
                store.push_back(tolower(c));
            }
        }

        if(store.size() <= 1){
            return true;
        }


        // init 2 pointers
        for(int i = 0; i < store.size()/2; i++ ){
            if(store[i] != store[store.size() - 1 - i]){
                return false;
            }
        }

        return true;
    }
};
