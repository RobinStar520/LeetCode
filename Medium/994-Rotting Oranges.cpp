// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

/*
Approach:
    We can use a BFS or DFS to judge whether we can reach a cell based on the condition.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int count = 0;
        int result = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> directions {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        queue<pair<int, int>> q {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    count += 1;
                }
                else if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty() && count > 0)
        {
            int size = q.size();
            while (size --)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int i=0; i<4; ++i)
                {
                    int X = x + directions[i][0];
                    int Y = y + directions[i][1];
                    if (X >= 0 && X < m && Y >= 0 && Y < n && grid[X][Y] == 1)
                    {
                        q.push(make_pair(X, Y));
                        grid[X][Y] = 2;
                        count -= 1;
                    }
                }
            }
            result += 1;
            
        }
        return count == 0 ? result : -1;
    }
};