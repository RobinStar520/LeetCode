// You are given an m x n integer matrix grid.

// We define an hourglass as a part of the matrix with the following form:


// Return the maximum sum of the elements of an hourglass.

// Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

 

// Example 1:


// Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
// Output: 30
// Explanation: The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.
// Example 2:


// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: 35
// Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 3 <= m, n <= 150
// 0 <= grid[i][j] <= 106

/*
Approach:
    We can use a prefix sum technique to avoid the duplicate calculation.
*/

#include <vector>
#include <limits>

using namespace std;

class Solution 
{
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        // Define the prefix sum vector.
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i)
        {
            prefixSum[i][0] = grid[i][0];
            for (int j=1; j<n; ++j)
            {
                prefixSum[i][j] = prefixSum[i][j - 1] + grid[i][j];
            }
        }
        int result = numeric_limits<int>::min();
        for (int i=0; i<m-2; ++i)
        {
            for (int j=0; j<n-2; ++j)
            {
                int cur = grid[i + 1][j + 1] + prefixSum[i][j + 2] - prefixSum[i][j] + grid[i][j] + prefixSum[i + 2][j + 2] - prefixSum[i + 2][j] + grid[i + 2][j];
                result = std::max(cur, result);
            }
        }
        return result;
    }
};