// You are given a 0-indexed m x n binary matrix grid.

// A 0-indexed m x n difference matrix diff is created with the following procedure:

// Let the number of ones in the ith row be onesRowi.
// Let the number of ones in the jth column be onesColj.
// Let the number of zeros in the ith row be zerosRowi.
// Let the number of zeros in the jth column be zerosColj.
// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
// Return the difference matrix diff.

 

// Example 1:


// Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
// Output: [[0,0,4],[0,0,4],[-2,-2,2]]
// Explanation:
// - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
// - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
// - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
// - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0 
// - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0 
// - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4 
// - diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
// - diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
// - diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2
// Example 2:


// Input: grid = [[1,1,1],[1,1,1]]
// Output: [[5,5,5],[5,5,5]]
// Explanation:
// - diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
// - diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
// - diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
// - diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
// - diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
// - diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// grid[i][j] is either 0 or 1.

/*
Approach:
    For this question, we can use four hashmaps to count the number of ones and zeros in rows and columns.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        unordered_map<int, int> onesRow {}, onesCol {}, zerosRow {}, zerosCol {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    onesRow[i] += 1;
                    onesCol[j] += 1;
                }
                else
                {
                    zerosRow[i] += 1;
                    zerosCol[j] += 1;
                }
            }
        }

        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                result[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return result;
    }
};