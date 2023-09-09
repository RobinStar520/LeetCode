// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
// Example 2:


// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.

/*
Approach:
    This is a funny but not difficult question with a trick: We only need to find the lands that are not enclaves and try to eliminate them. The rest
parts are what we want. You can use BFS or DFS. Here, I used BFS.
*/



#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    if (i == 0 || j == 0 || i == m-1 || j == n-1)
                    {
                        this->modify(i, j, grid, visited);
                    }
                }
            }
        }
        int result = 0;
        for (const auto& v: grid)
        {
            for (const auto& i: v)
            {
                if (i == 1)
                {
                    result += 1;
                }
                // cout << i << " ";
            }
            // cout << endl;
        }
        return result;
    }

private:
    void modify(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        // Eliminate the enclave part.
        grid[x][y] = 0;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int i=0; i<4; ++i)
            {
                int X = cur.first + directions[i][0];
                int Y = cur.second + directions[i][1];
                if (X < 0 || Y < 0 || X >= grid.size() || Y >= grid[0].size())
                {
                    continue;
                }
                if (!visited[X][Y] && grid[X][Y] == 1)
                {
                    q.push(make_pair(X, Y));
                    grid[X][Y] = 0;
                }
            }
        }
        return;
    }


    vector<vector<int>> directions {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
};
