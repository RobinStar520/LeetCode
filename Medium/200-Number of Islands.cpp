// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

/*
Approach:
    BFS
*/

#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        const int rows= grid.size();
        const int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int result = 0;
        for (int i=0; i<rows; ++i)
        {
            for (int j=0; j<cols; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    result += 1;
                    this->bfs(i, j, grid, visited);
                }
            }
        } 
        return result;
    }

private:
    vector<vector<int>> direction {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };

    void bfs(int startX, int startY, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(startX, startY));
        visited[startX][startY] = 1;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int i=0; i<4; ++i)
            {
                int nextX = cur.first + this->direction[i][0];
                int nextY = cur.second + this->direction[i][1];
                if (nextX >= grid.size() || nextX < 0 || nextY < 0 || nextY >= grid[0].size())
                {
                    continue;
                }
                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1')
                {
                    q.push(make_pair(nextX, nextY));
                    visited[nextX][nextY] = 1;
                }
            }
        }
    }
};