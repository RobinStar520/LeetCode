// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

/*
Approach:
    This question has a little trick. I divide the solution into two steps: 1.Use deep search or wide search to change all the 'O's around the map to 'A';
2.Traverse the map again, change all 'O's to 'X' (the 'O' in the middle of the map is changed to 'X'), change 'A' back to 'O' (retain the 'O's around the map.
*/

#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        const int m  = board.size();
        const int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> directions {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                // First step.
                if ((board[i][j] == 'O') && (i == 0 || i == m-1 || j == 0 || j == n-1))
                {
                    queue<pair<int, int>> q {};
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        board[x][y] = '#';
                        for (int k=0; k<4; ++k)
                        {
                            int next_x = x + directions[k][0];
                            int next_y = y + directions[k][1];
                            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y] || board[next_x][next_y] != 'O')
                            {
                                continue;
                            } 
                            q.push(make_pair(next_x, next_y));
                            visited[next_x][next_y] = 1;
                        }
                    }
                }
            }
        }
        // The second step.
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};