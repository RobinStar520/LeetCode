// You are given an m x n grid rooms initialized with these three possible values.

// -1 A wall or an obstacle.
// 0 A gate.
// INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 

// Example 1:


// Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
// Example 2:

// Input: rooms = [[-1]]
// Output: [[-1]]
 

// Constraints:

// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j] is -1, 0, or 231 - 1.

/*
Approach:
    We can use BFS starting from each cell representing gate.
*/

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        const int m = rooms.size();
        const int n = rooms[0].size();
        const int INF = 2147483647;
        vector<vector<int>> visited(m, vector<int>(n));
        // pair -> [(row, column), level]
        queue<pair<pair<int, int>, int>> q {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (rooms[i][j] == 0)
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
                auto [coor, level] = q.front();
                q.pop();
                auto [cur_x, cur_y] = coor;
                rooms[cur_x][cur_y] = std::min(level, rooms[cur_x][cur_y]);

                for (int i=0; i<4; ++i)
                {
                    int next_x = cur_x + dx[i];
                    int next_y = cur_y + dy[i];
                    if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && rooms[next_x][next_y] == INF)
                    {
                        q.push(make_pair(make_pair(next_x, next_y), level + 1));
                    }
                }
            }
        }
    }


private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};