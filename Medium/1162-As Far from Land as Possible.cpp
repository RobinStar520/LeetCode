// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

// Example 1:


// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:


// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

/*
Approach:
    We can use a BFS, start from each cell that value is one, and record the distance simultaneously.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {-1, 1, 0, 0 };
        queue<pair<pair<int, int>, int>> q {};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int result = -1;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }
        if (q.empty())
        {
            return result;
        }

        while (!q.empty())
        {
            int size= q.size();
            
            while (size --)
            {
                auto [coordinate, level] = q.front();
                q.pop();
                auto [x, y] = coordinate;
                visited[x][y] = 1;
                result = std::max(level, result);

                for (int i=0; i<4; ++i)
                {
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if (X >= 0 && X < m && Y >= 0 && Y < n && grid[X][Y] == 0 && !visited[X][Y])
                    {
                        q.push(make_pair(make_pair(X, Y), level + 1));
                        visited[X][Y] = 1;
                    }
                }
            }
        }

        return result == 0 ? -1 : result;

    }


};