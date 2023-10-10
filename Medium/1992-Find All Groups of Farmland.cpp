// You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

// To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

// land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

// Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

 

// Example 1:


// Input: land = [[1,0,0],[0,1,1],[0,1,1]]
// Output: [[0,0,0,0],[1,1,2,2]]
// Explanation:
// The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
// The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
// Example 2:


// Input: land = [[1,1],[1,1]]
// Output: [[0,0,1,1]]
// Explanation:
// The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
// Example 3:


// Input: land = [[0]]
// Output: []
// Explanation:
// There are no groups of farmland.

/*
Approach:
    An easy question using BFA to find the last valid cell.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        const int m = land.size();
        const int n = land[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        vector<vector<int>> result {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (!visited[i][j] && land[i][j] == 1)
                {
                    dfs(land, visited, result, i, j);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& visited, vector<vector<int>>& result, int x, int y)
    {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> area {x, y};
        int des_x = x, des_y = y;
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        
        while (!q.empty())
        {
            auto [cur_x, cur_y] = q.front();
            q.pop();
            des_x = std::max(des_x, cur_x);
            des_y = std::max(des_y, cur_y);
            for (int i=0; i<4; ++i)
            {
                int X = dx[i] + cur_x;
                int Y = dy[i] + cur_y;
                if (X >= 0 && X < m && Y >= 0 && Y < n && !visited[X][Y] && mat[X][Y] != 0)
                {
                    q.push(make_pair(X, Y));
                    visited[X][Y] = 1;
                }
            }
        }
        // Append the last cell coordinite to the area vector.
        area.push_back(des_x);
        area.push_back(des_y);
        result.push_back(area);
    }

    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};
};