#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Solution{
    public:

    void BFS(vector<vector<int>>& grid, int startRow, int startCol){
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols

        // Directions to go -> Up, Down, Left, Right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        // BFS
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            cout << "Visiting: (" << row << ", " << col  << ") -> Value: " << grid[row][col] << endl;

            // explore all directions
            for(auto [dR, dC] : directions){
                int newRow = row + dR;
                int newCol = col + dC;

                // check the bounds and visited
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]){
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

};

int main(){
    vector<vector<int>> grid  = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    sol.BFS(grid, 0, 0); // start at top left corner
    return 0;
}
