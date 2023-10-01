// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

// Return the number of distinct islands.

 

// Example 1:


// Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
// Output: 1
// Example 2:


// Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

/*
Approach:
    For this question, we need to find all the existing islands and judge their shape. If we use a BFS algorithm, it's easy to solve the first part, but
it's hard to simluate the shape of a island because DFS searchs four directions.. If we use a DFS approach, we can record the path that we visited clearly.
*/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        unordered_set<string> _set {};
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (visited[i][j] == 1 || grid[i][j] == 0)
                {
                    continue;
                }
                
                string hash_string {};
                string path {};
                dfs(grid, visited, i, j, path, hash_string);
                
                _set.insert(hash_string);
            }
        }
        
        return _set.size();
    }

private:
     vector<vector<int>> directions {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}
    };
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, string& path, string& hash_string)
    {
        visited[x][y] = 1;
        hash_string += path;
        
        for (int k = 0; k < 4; ++k)
        {
            int next_x = x + directions[k][0];
            int next_y = y + directions[k][1];
            
            if (next_x >= 0 && next_x < grid.size() && next_y >= 0 && next_y < grid[0].size() && !visited[next_x][next_y] && grid[next_x][next_y] != 0)
            {
                path += to_string(k);  // Record the path
                dfs(grid, visited, next_x, next_y, path, hash_string);
            }
        }
        
        path += '#';  // Use '#' to represent end of path
    }
};