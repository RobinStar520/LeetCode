// On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



// We may make the following moves:

// 'U' moves our position up one row, if the position exists on the board;
// 'D' moves our position down one row, if the position exists on the board;
// 'L' moves our position left one column, if the position exists on the board;
// 'R' moves our position right one column, if the position exists on the board;
// '!' adds the character board[r][c] at our current position (r, c) to the answer.
// (Here, the only positions that exist on the board are positions with letters on them.)

// Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

 

// Example 1:

// Input: target = "leet"
// Output: "DDR!UURRR!!DDD!"
// Example 2:

// Input: target = "code"
// Output: "RR!DDRR!UUL!R!"
 

// Constraints:

// 1 <= target.length <= 100
// target consists only of English lowercase letters.

/*
Approach:
    Using BFS in this question is not a optimal choice but it is possible. BFS gives the shortest path as it traverse level-wise. So, we can build a 
graph and use BFS to find the shortest path.
    1.First Store the board in a vector of string or 2D vector
    2.Call BFS for every charater in target string for the shortest path
    3.We need a visited array for every BFS call because we need to travel the matrix / grid multiple times
    4.Make a queue of current location...i.e (x, y) and current path string
    5.If we find the target char then update the values of (x,y) with current location and add the path string to total path string
*/

#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    string path;
};

class Solution 
{
public:
    string alphabetBoardPath(string target) 
    {
        string result {};
        vector<vector<char>> board {
            {'a', 'b', 'c', 'd', 'e'},
            {'f', 'g', 'h', 'i', 'j'},
            {'k', 'l', 'm', 'n', 'o'},
            {'p', 'q', 'r', 's', 't'},
            {'u', 'v', 'w', 'x', 'y'},
            {'z', '#', '#', '#', '#'}
        };
        int x = 0, y = 0;
        for (auto& ch: target)
        {
            bfs(board, x, y, ch, result);
        }
        return result;
    }

private:
    void bfs(vector<vector<char>>& board, int& x, int& y, char& ch, string& result)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size()));
        queue<Node> q {};
        q.push({x, y, ""});
        visited[x][y] = 1;
        while (!q.empty())
        {
            int cur_x = q.front().x;
            int cur_y = q.front().y;
            string str = q.front().path;
            q.pop();
            
            if (board[cur_x][cur_y] == ch)
            {
                str.push_back('!');
                result += str;
                x = cur_x;
                y = cur_y;
                return;
            }
            for (int i=0; i<4; ++i)
            {
                int next_x = cur_x + directions[i][0];
                int next_y = cur_y + directions[i][1];
                if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size() || board[next_x][next_y] == '#' || visited[next_x][next_y])
                {
                    continue;
                }
                visited[next_x][next_y] = 1;
                str += direction_string[i];
                q.push({next_x, next_y, str});
                str.pop_back();

            }
        }

    }
    // Pay attention to the order of each character in the string.
    string direction_string = "ULDR";
    vector<vector<int>> directions {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

};