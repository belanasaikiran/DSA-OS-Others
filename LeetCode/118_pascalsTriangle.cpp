#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {

    vector<vector<int>> pascalTriangle;
    vector<int> row;
    for (int i = 0; i < numRows; i++) {
      int j = 0;
      while (j <= i) {
        int adder = 1;
        if(j >= 1 && j < i){
              adder = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }

        row.push_back(adder);
        j++;
      }
      pascalTriangle.push_back(row);
      row.clear();
    }

    // Print the triangle
    for (int i = 0; i < numRows; i++) {
      for (int space = 0; space < numRows - i; space++)
        cout << "  ";

      for (int j = 0; j <= i; j++) {
        cout << pascalTriangle[i][j] << "   ";
      }
      cout << endl;
    }

    return pascalTriangle;
  }
};

int main() {
  Solution S;
  S.generate(5);
}
