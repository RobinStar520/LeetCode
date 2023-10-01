// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

// Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

// Example 1:


// Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
// Output: 2
// Example 2:

// Input: board = [["."]]
// Output: 0
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is either '.' or 'X'.
 

// Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?

/*
Approach:
    This is an easy graph problem. We can use DFS of BFS to solve it.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int result = 0;
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (board[i][j] == 'X' && !visited[i][j])
                {
                    result += 1;
                    bfs(board, visited, i, j);
                }
            }
        }
        return result;
    }

private:
    vector<vector<int>> directions {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                for (int i=0; i<4; ++i)
                {
                    int next_x = cur_x + directions[i][0];
                    int next_y = cur_y + directions[i][1];
                    if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size())
                    {
                        continue;
                    }
                    if (!visited[next_x][next_y] && board[next_x][next_y] == 'X')
                    {
                        q.push(make_pair(next_x, next_y));
                        visited[next_x][next_y] = 1;
                    }
                }

            }
            
        }
        return;
    }
};