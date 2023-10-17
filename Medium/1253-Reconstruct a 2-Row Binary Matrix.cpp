// Given the following details of a matrix with n columns and 2 rows :

// The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
// The sum of elements of the 0-th(upper) row is given as upper.
// The sum of elements of the 1-st(lower) row is given as lower.
// The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
// Your task is to reconstruct the matrix with upper, lower and colsum.

// Return it as a 2-D integer array.

// If there are more than one valid solution, any of them will be accepted.

// If no valid solution exists, return an empty 2-D array.

 

// Example 1:

// Input: upper = 2, lower = 1, colsum = [1,1,1]
// Output: [[1,1,0],[0,0,1]]
// Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
// Example 2:

// Input: upper = 2, lower = 3, colsum = [2,2,1,1]
// Output: []
// Example 3:

// Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
// Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
 

// Constraints:

// 1 <= colsum.length <= 10^5
// 0 <= upper, lower <= colsum.length
// 0 <= colsum[i] <= 2

/*
Approach:
    For this question, we can use a greedy approach: You cannot do anything about colsum[i] = 2 case or colsum[i] = 0 case. Then you put colsum[i] = 1 
case to the upper row until upper has reached. Then put the rest into lower row. Fill 0 and 2 first, then fill 1 in the upper row or lower row in turn 
but be careful about exhausting permitted 1s in each row.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) 
    {
        const int n = colsum.size();
        vector<int> upper_vector(n, 0), lower_vector(n, 0);
        for (int i=0; i<n; ++i)
        {
            if (colsum[i] == 2)
            {
                if (upper > 0 && lower > 0)
                {
                    upper_vector[i] = 1;
                    lower_vector[i] = 1;
                    upper -= 1;
                    lower -= 1;
                }
                else
                {
                    return {};
                }
            }
        }

        for (int i=0; i<n; ++i)
        {
            if (colsum[i] == 1)
            {
                if (upper >= lower)
                {
                    upper -= 1;
                    upper_vector[i] = 1;
                }
                else
                {
                    lower -= 1;
                    lower_vector[i] = 1;
                }
            }
        }
        vector<vector<int>> result {
            upper_vector, lower_vector
        };
        return (upper == 0 && lower == 0) ? result : vector<vector<int>>();
    }
};