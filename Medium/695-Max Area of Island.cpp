// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

/*
Approach:
    BFS or DFS in graph problems.
*/

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        const int rows = grid.size();
        const int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int result = 0;
        for (int i=0; i<rows; ++i)
        {
            for (int j=0; j<cols; ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    this->bfs(i, j, grid, visited, result);
                }
            }
        }
        return result;
    }

private:
    vector<vector<int>> directions 
    {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };

    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, int& result)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        int count = 1;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int i=0; i<4; ++i)
            {
                int nextX = cur.first + this->directions[i][0];
                int nextY = cur.second + this->directions[i][1];
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                {
                    continue;
                }
                if (!visited[nextX][nextY] && grid[nextX][nextY] == 1)
                {
                    count += 1;
                    visited[nextX][nextY] = 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
            result = std::max(result, count);
        }
    }
};