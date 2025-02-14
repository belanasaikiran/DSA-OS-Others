#include <iostream>
#include <vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's.

/*

Input: matrix = [[1,1,1]
                ,[1,0,1],
                 [1,1,1]]
Output: [[1,0,1],
         [0,0,0],
         [1,0,1]]

---
Input:
[[0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]]


Output:
[[0,0,0,0],
 [0,4,5,2],
 [0,3,1,5]]

*/

class Solution {
public:
  // This algorithm reduces the space.
  void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int col0 = 1; // a variable used for tracking the zeros in cols

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0; // 1st column and ith row to zero.

          if (j != 0) {
            matrix[0][j] = 0; // first row and jth column to zero
          } else {
            col0 = 0; // if it is first column, then set this variable to zero
                      // so we can check it later to update
          }
        }
      }
    }

    // Step 2: Mark with 0  from (1,1) to (n-1, m-1)
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] != 0) {
          // if the row or col starting element is set to zero, we
          // set the entire row/col to zero.
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }
    }

    // step 3: Mark the first row and col to zero
    //
    // ROW:
    if (matrix[0][0] == 0) {
      for (int i = 0; i < cols; i++) {
        matrix[0][i] = 0;
      }
    }

    // Column
    if (col0 == 0) {
      for (int i = 0; i < rows; i++) {
        matrix[i][0] = 0;
      }
    }
  }

  void printer(vector<vector<int>> &matrix) {

    for (auto it : matrix) {
        for (auto element : it) {
        cout << element << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Solution *mySol = new Solution;

  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  mySol->printer(matrix);
  cout << endl;
  mySol->setZeroes(matrix);
  mySol->printer(matrix);

  return 0;
}
