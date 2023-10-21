// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

/*
Approach:
    For this question, we can't check the cell individually since the algorithm will gose to O(m ^ 2 * n ^ 2). We can think about it the other way 
around, going upstream from the nodes on the Pacific Ocean and marking all the nodes we have traversed. The nodes on the edge of the Atlantic Ocean 
go upstream, and the nodes that have been traversed are also marked. Then the node marked by both parties is the node that can flow to both the 
Pacific Ocean and the Atlantic Ocean.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        const int m = heights.size();
        const int n = heights[0].size();
        vector<vector<int>> visited_Atlantic(m, vector<int>(n, 0));
        vector<vector<int>> visited_Pacific(m, vector<int>(n, 0));
        vector<vector<int>> result {};

        for (int i=0; i<m; ++i)
        {
            dfs(heights, visited_Pacific, i, 0);
            dfs(heights, visited_Atlantic, i, n-1);
        }

        for (int j=0; j<n; ++j)
        {
            dfs(heights, visited_Pacific, 0, j);
            dfs(heights, visited_Atlantic, m-1, j);
        }
        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (visited_Pacific[i][j] && visited_Atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y)
    {
        
        visited[x][y] = 1;
        for (int i=0; i<4; ++i)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size() || visited[next_x][next_y])
            {
                continue;
            }
            if (heights[x][y] > heights[next_x][next_y])
            {
                continue;
            }
            dfs(heights, visited, next_x, next_y);
        }
    }

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};