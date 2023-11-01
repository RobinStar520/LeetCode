// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

/*
Approach:
    We can use the BFS for each eall that value is zero simultaneously.
*/

/*
Modified Log:
    31/10/23 Modified the BFS code, and now looks more logical.
*/

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        const int INF = numeric_limits<int>::max();
        const int m = mat.size();
        const int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q {};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> result(m, vector<int>(n, INF));
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {-1, 1, 0, 0};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    q.push(make_pair(make_pair(i, j), 0));
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            while (size --)
            {
                auto [coordinate, level] = q.front();
                q.pop();
                auto [x, y] = coordinate;
                result[x][y] = std::min(result[x][y], level);
                for (int i=0; i<4; ++i)
                {
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if (X >= 0 && X < m && Y >= 0 && Y < n && !visited[X][Y])
                    {
                        visited[X][Y] = 1;
                        q.push(make_pair(make_pair(X, Y), level + 1));
                        result[X][Y] = level + 1;
                    }
                }
            }
        }

        return result;
    }

};