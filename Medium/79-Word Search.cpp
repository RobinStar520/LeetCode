// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?

/*
Approach:
    This is a graph problem. We need to search for four directions simultaneously.
*/

#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int i=0; i<board.size(); ++i)
        {
            for (int j=0; j<board[i].size(); ++j)
            {
                if (board[i][j] == word.front() && this->dfs(i, j, 0, word, board))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // DFS uses the backtracking algorithm
    bool dfs(int row, int col, int count, string word, vector<vector<char>>& board)
    {
        if (word.length() == count)
        {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[count])
        {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = ' ';
        // Search for four directions simultaneously.
        bool result = this->dfs(row - 1, col, count+1, word, board)
        || this->dfs(row + 1, col, count+1, word, board)
        || this->dfs(row, col-1, count+1, word, board)
        || this->dfs(row, col+1, count+1, word, board);
        board[row][col] = temp;
        return result;
    }
};