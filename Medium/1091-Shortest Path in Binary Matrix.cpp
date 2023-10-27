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

/*
Modified Log:
    26/10/23 optimise the solution, which reduces the runtime.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        vector<vector<int>> visited(m, vector<int>(m, 0));
        queue<pair<int, int>> q {};
        if (grid[0][0] == 1)
        {
            return -1;
        }
        q.push(make_pair(0, 0));
        visited[0][0] = 1;
        int result = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                if (cur_x == m - 1 && cur_y == m - 1)
                {
                    return result;
                }
                for (int i=0; i<8; ++i)
                {
                    int next_x = cur_x + dx[i];
                    int next_y = cur_y + dy[i];
                    if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < m && !visited[next_x][next_y] && grid[next_x][next_y] == 0)
                    {
                        q.push(make_pair(next_x, next_y));
                        visited[next_x][next_y] = 1;
                    }
                }
            }
            result += 1;
        }
        return -1;
    }

private:
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
};