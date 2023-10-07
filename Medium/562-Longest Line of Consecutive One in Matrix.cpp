// Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

// The line could be horizontal, vertical, diagonal, or anti-diagonal.

 

// Example 1:


// Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
// Output: 3
// Example 2:


// Input: mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
// Output: 4
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.

/*
Approach:
    We can use dynamic programming to solve this question. Define four vector repersents for direction, and then use DP.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int longestLine(vector<vector<int>>& mat) 
    {
        const int m = mat.size();
        const int n = mat[0].size();
        int result = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));
        vector<vector<int>> column(m, vector<int>(n, 0));
        vector<vector<int>> diagnoal(m, vector<int>(n, 0));
        vector<vector<int>> anti_diagnoal(m, vector<int>(n, 0));

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (mat[i][j] == 1)
                {
                    row[i][j] = (j > 0) ? row[i][j - 1] + 1 : 1;
                    column[i][j] = (i > 0) ? column[i - 1][j] + 1 : 1;
                    diagnoal[i][j] = (i > 0 && j > 0) ? diagnoal[i - 1][j - 1] + 1 : 1;
                    anti_diagnoal[i][j] = (i > 0 && j < n - 1) ? anti_diagnoal[i - 1][j + 1] + 1 : 1;
                    int val = std::max(std::max(diagnoal[i][j], anti_diagnoal[i][j]) ,std::max(row[i][j], column[i][j]));
                    result = std::max(result, val);
                }
            }
        }
        return result;
    }
};