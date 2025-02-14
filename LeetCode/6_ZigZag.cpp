#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  Zig Zag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= 1) return s;

        vector<vector<char>> rows(numRows);
        int j = 0;
        int k = 0;
        int i = 0;
        while(i < s.length()){
            for(j = 0; j < numRows; j++){
                rows[j][k] = s[i];
                i++;
            }
            k++;

            int l = 1;
            while((numRows-l) > 1){
                rows[numRows-l-1][k] = s[i];
                l++;
                k++;
                i++;
            }
        }

        string result = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < rows[i].size(); j++){
                result += rows[i][j];
            }
        }

        return result;

    }
};


int main(){
    Solution s;
    string result = s.convert("PAYPALISHIRING", 3);
    cout << result << endl;
    return 0;
}
