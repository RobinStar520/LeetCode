// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9

/*
Approach:
    This is a famous question. I used a backtracking approach for this question to enumerate all the possible results.
*/

#include <vector>
#include <string>

using namespace std;


class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result {};
        vector<string> board(n, string(n, '.'));
        backtracking(n, 0, board, result);
        return result;
    }

private:
    void backtracking(int n, int row, vector<string>& board, vector<vector<string>>& result)
    {
        if (row == n) 
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) 
        {
            if (isValid(row, col, board, n)) 
            { 
                board[row][col] = 'Q'; 
                backtracking(n, row + 1, board, result);
                board[row][col] = '.';
            }
        }
    }

    // Check the validation of a specified coordinate (row, column).
    bool isValid(int row, int column, vector<string>& board, int n)
    {
        for (int i=0; i<row; ++i)
        {
            if (board[i][column] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = column - 1; i >=0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 'Q') 
            {
                return false;
            }
        }
        for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) 
        {
            if (board[i][j] == 'Q') 
            {
                return false;
            }
        }
        return true;
    }
};