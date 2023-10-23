// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

// Example 1:



// Input: isWater = [[0,1],[0,0]]
// Output: [[1,0],[2,1]]
// Explanation: The image shows the assigned heights of each cell.
// The blue cell is the water cell, and the green cells are the land cells.
// Example 2:



// Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
// Output: [[1,1,0],[0,1,1],[1,2,2]]
// Explanation: A height of 2 is the maximum possible height of any assignment.
// Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

// Constraints:

// m == isWater.length
// n == isWater[i].length
// 1 <= m, n <= 1000
// isWater[i][j] is 0 or 1.
// There is at least one water cell.

/*
Approach:
    This is a graph problem. Set each water cell to be 0. The height of each cell is limited by its closest water cell. Perform a multi-source BFS 
with all the water cells as sources. (Note: If we don't do so, we can't pass all the test cases due to the time limit exceeded).
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        const int m = isWater.size();
        const int n = isWater[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // We should modify the structure that we need to put into the queue.
        // The structure looks like this: [coordinate of each water cell, current level]
        queue<pair<pair<int, int>, int>> q {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                    isWater[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            auto [coordinate, level] = q.front();
            q.pop();
            auto [cur_x, cur_y] = coordinate;
            isWater[cur_x][cur_y] = level;
            for (int i=0; i<4; ++i)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y])
                {
                    continue;
                }
                q.push(make_pair(make_pair(next_x, next_y), level + 1));
                visited[next_x][next_y] = 1;
            }

        }

        return isWater;

    }

private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};