// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

// Example 1:


// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
// Example 2:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// Output: 1
// Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// 0 <= grid[i][j] <= 10

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int findMaxFish(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int result = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (visited[i][j] == 1 || grid[i][j] == 0)
                {
                    continue;
                }
                int val = bfs(grid, visited, i, j);
                result = std::max(result, val);
            }
        }
        return result;
    }

private:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y)
    {
        int result = 0;
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q.empty())
        {
            auto [cur_x, cur_y] = q.front();
            q.pop();
            result += grid[cur_x][cur_y];
            for (int i=0; i<4; ++i)
            {
                int next_x = cur_x + directions[i][0];
                int next_y = cur_y + directions[i][1];
                // Note the loop here: if "next_x" or "next_y" doesn't satisfy the condition, the loop should continue instead of breaking.
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size() || grid[next_x][next_y] == 0 || visited[next_x][next_y] == 1)
                {
                    continue;
                }
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y] = 1;
            }
        }
        return result;
    }

    vector<vector<int>> directions {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
};