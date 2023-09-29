// You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

// You are given an m x n character matrix, grid, of these different types of cells:

// '*' is your location. There is exactly one '*' cell.
// '#' is a food cell. There may be multiple food cells.
// 'O' is free space, and you can travel through these cells.
// 'X' is an obstacle, and you cannot travel through these cells.
// You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

// Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

 

// Example 1:


// Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
// Output: 3
// Explanation: It takes 3 steps to reach the food.
// Example 2:


// Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
// Output: -1
// Explanation: It is not possible to reach the food.
// Example 3:


// Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
// Output: 6
// Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// grid[row][col] is '*', 'X', 'O', or '#'.
// The grid contains exactly one '*'.

/*
Approach:
    We can use the BFS to find the shortest path.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int getFood(vector<vector<char>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n));
        int x = 0, y = 0;
        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid[i].size(); ++j)
            {
                if (grid[i][j] == '*')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int result = bfs(grid, visited, x, y);
        return result;
    }

private:
    int bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y)
    {
        int result = 0;
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                auto p = q.front();
                q.pop();
                int cur_x = p.first, cur_y = p.second;
                for (int i=0; i<4; ++i)
                {
                    int next_x = cur_x + direction[i][0];
                    int next_y = cur_y + direction[i][1];
                    // Note the obstacle.
                    if (next_x >= 0 && next_x < grid.size() && next_y >= 0 && next_y < grid[0].size() && !visited[next_x][next_y] && grid[next_x][next_y] != 'X')
                    {
                        // If we find a food, which means the shortest path we have found, return the distance+1.
                        if (grid[next_x][next_y] == '#')
                        {
                            return 1 + result;
                        }
                        q.push(make_pair(next_x, next_y));
                        visited[next_x][next_y] = 1;
                    }
                }
            }
            result += 1;
        }
        return -1;
    }

    vector<vector<int>> direction {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
};