// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

 

// Example 1:



// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// Example 2:



// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// Example 3:

// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
 

// Constraints:

// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1

/*
Approach:
    We can start searching from the edges since an island on the edge can't be surrounded by water in four directions. Use BFS or DFS.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int result = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 0 && (i == 0 || i == m-1 || j == 0 || j == n-1))
                {
                    bfs(grid, visited, i, j, 0);
                }
            }
        }
        visited = vector<vector<int>>(m, vector<int>(n));
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    bfs(grid, visited, i, j, 0);
                    result += 1;
                }
            }
        }
        return result;
    }

private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int target)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                grid[cur_x][cur_y] = -1;
                for (int k=0; k<4; ++k)
                {
                    int next_x = cur_x + directions[k][0];
                    int next_y = cur_y + directions[k][1];
                    if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || grid[next_x][next_y] != target || visited[next_x][next_y])
                    {
                        continue;
                    }
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                }

            }
            
        }
        return;
    }

    vector<vector<int>> directions {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
};