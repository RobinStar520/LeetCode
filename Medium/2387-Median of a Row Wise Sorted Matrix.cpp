// Given an m x n matrix grid containing an odd number of integers where each row is sorted in non-decreasing order, return the median of the matrix.

// You must solve the problem in less than O(m * n) time complexity.

 

// Example 1:

// Input: grid = [[1,1,2],[2,3,3],[1,3,4]]
// Output: 2
// Explanation: The elements of the matrix in sorted order are 1,1,1,2,2,3,3,3,4. The median is 2.
// Example 2:

// Input: grid = [[1,1,3,3,4]]
// Output: 3
// Explanation: The elements of the matrix in sorted order are 1,1,3,3,4. The median is 3.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// m and n are both odd.
// 1 <= grid[i][j] <= 106
// grid[i] is sorted in non-decreasing order.

/*
Approach:
    We can use a multiset to sort the elements in the matrix effectively, then get the median value.
*/

#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
    int matrixMedian(vector<vector<int>>& grid) 
    {
        multiset<int> _set {};
        for (const auto& v: grid)
        {
            for (const auto& i: v)
            {
                _set.insert(i);
            }
        }
        auto iter = _set.begin();
        // The number of elements of the matrix is a odd number, so we don't consider the even length.
        for (int i=0; i<_set.size() / 2; ++i)
        {
            iter = std::next(iter);
        }
        
        return *iter;
    }
};