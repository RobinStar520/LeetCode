// Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

 

// Example 1:


// Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
// Output: [[7,0,0],[-7,0,3]]
// Example 2:

// Input: mat1 = [[0]], mat2 = [[0]]
// Output: [[0]]
 

// Constraints:

// m == mat1.length
// k == mat1[i].length == mat2.length
// n == mat2[i].length
// 1 <= m, n, k <= 100
// -100 <= mat1[i][j], mat2[i][j] <= 100

/*
Approach:
    This is an easy question since the brute force algorithm can pass all the test cases. Calculate according to the calculation method of matrix 
multiplication.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) 
    {
        int m = mat1.size();  // Number of rows in mat1
        int k = mat1[0].size();  // Number of columns in mat1 and rows in mat2
        int n = mat2[0].size();  // Number of columns in mat2

        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                for (int x = 0; x < k; x++) 
                {
                    result[i][j] += mat1[i][x] * mat2[x][j];
                }
            }
        }

        return result;
    }
};