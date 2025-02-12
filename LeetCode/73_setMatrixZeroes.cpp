#include <iostream>
#include <vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

class Solution
{
public:
    // Bruteforce
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = 0; k < rows; k++)
                    {
                        if(matrix[k][j] != 0) {
                            matrix[k][j] = -1;
                        }
                    }
                    for (int k = 0; k < cols; k++)
                    {
                        if(matrix[i][k] != 0){
                            matrix[i][k] = -1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // A better approach
    void betterApproach(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();

        int N[rows] = {0}; // to capture row numbers
        int M[cols] = {0}; // capture col numbers containing zero

        // Noting down the rows and cols which have zeros in given matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            { 
                if(matrix[i][j] == 0){
                    N[i] = 1;
                    M[j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            { 
               
                if(N[i] || M[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }







    void printer(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution *mySol = new Solution;

    vector<vector<int>> matrix = {{1,1,1}, 
                                  {1,0,1}, 
                                  {1,1,1}};

    mySol->printer(matrix);
    cout << endl;
    mySol->betterApproach(matrix);
    mySol->printer(matrix);

    return 0;
}


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