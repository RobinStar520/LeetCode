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

/*
Modify Log:
    28/10/23 Modify some parts of the code but didn't change the whole algorithm(still BFS). 
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
        const int m = grid.size();
        const int n = grid[0].size();
        queue<pair<int, int>> q {};
        int count = 0;
        int result = 0;
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
                    int next_x = x + dx[i];
                    int next_y = y + dy[i];
                    if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] == 1)
                    {
                        q.push(make_pair(next_x, next_y));
                        grid[next_x][next_y] = 2;
                        count -= 1;
                    }
                }
            }
            result += 1;
        }
        return count == 0 ? result : -1;
    }

private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};