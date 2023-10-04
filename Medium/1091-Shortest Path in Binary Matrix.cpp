// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

 

// Example 1:


// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:


// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

/*
Approach:
    We can use BFS to solve this problem. Notice that there is a bit different than common BFS approach since we can move to eight directions in this
question.
*/

#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        const int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; // If the start or end cell is blocked, there is no clear path.
        }

        vector<vector<int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        queue<pair<int, int>> q {};
        q.push(make_pair(0, 0));
        grid[0][0] = 1; // Mark the start cell as visited.
        int pathLength = 1;

        while (!q.empty()) 
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) 
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1) 
                {
                    return pathLength; 
                }

                for (const auto& dir : directions) 
                {
                    int next_x = x + dir[0];
                    int next_y = y + dir[1];

                    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y] == 0) 
                    {
                        q.push(make_pair(next_x, next_y));
                        grid[next_x][next_y] = 1; 
                    }
                }
            }
            pathLength++;
        }

        return -1; 
    }
};