// A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

// Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

// You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

// BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
// BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.
// Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

// For custom testing purposes, the input will be the entire binary matrix mat. You will not have access to the binary matrix directly.

 

// Example 1:


// Input: mat = [[0,0],[1,1]]
// Output: 0
// Example 2:


// Input: mat = [[0,0],[0,1]]
// Output: 1
// Example 3:


// Input: mat = [[0,0],[0,0]]
// Output: -1
 

// Constraints:

// rows == mat.length
// cols == mat[i].length
// 1 <= rows, cols <= 100
// mat[i][j] is either 0 or 1.
// mat[i] is sorted in non-decreasing order.

/*
Approach:
    This question has a very boring constraints: Making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer, so we must come up with an
algorithm less than O(n ^ 2). Binary is a good choise as the rows of matrix are sorted.
*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
#include <limits>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) 
    {
        const int m = binaryMatrix.dimensions().front();
        const int n = binaryMatrix.dimensions().back();
        int result = numeric_limits<int>::max();
        for (int i=0; i<m; ++i)
        {
            int low = 0, high = n - 1;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (binaryMatrix.get(i, mid) == 0)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
            if (binaryMatrix.get(i, low) == 1)
            {
                result = std::min(low, result);
            }
        }
        return result == numeric_limits<int>::max() ? -1 : result;
    }


};