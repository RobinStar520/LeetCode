// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

/*
Approach:
    We can use bracktracking to solve this problem.
*/
#include <vector>

using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtracking(board);
        return ;
    }

private:
    bool backtracking(vector<vector<char>>& board)
    {
        for (int i=0; i<board.size(); ++i)
        {
            for (int j=0; j<board[0].size(); ++j)
            {
                if (board[i][j] == '.')
                {
                    for (char k='1'; k<='9'; ++k)
                    {
                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (backtracking(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                        
                    }
                    return false;
                }

            }
        }

        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int column, char ch)
    {
        for (int i=0; i<9; ++i)
        {
            if (board[row][i] == ch)
            {
                return false;
            }
        }

        for (int i=0; i<9; ++i)
        {
            if (board[i][column] == ch)
            {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (column / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) 
        { 
            for (int j = startCol; j < startCol + 3; j++) 
            {
                if (board[i][j] == ch ) 
                {
                    return false;
                }
            }
        }
        return true;
    }
};