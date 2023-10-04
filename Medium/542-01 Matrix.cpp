// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

/*
Approach:
    We can use the BFS for each eall that value is zero simultaneously.
*/

#include <vector>
#include <queue>
#include <utility>
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
        queue<pair<int, int>> q {};
        vector<vector<int>> directions {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        vector<vector<int>> result(m, vector<int>(n, INF));
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i=0; i<4; ++i)
            {
                int X = x + directions[i][0];
                int Y = y + directions[i][1];
                if (X >= 0 && Y >= 0 && X < m && Y < n)
                {
                    if (result[X][Y] > result[x][y] + 1)
                    {
                        result[X][Y] = result[x][y] + 1;
                        q.push(make_pair(X, Y));
                    }
                }
            }
        }
        return result;
    }
};