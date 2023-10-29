// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

// Example 1:



// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Example 2:



// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 500
// 1 <= mat[i][j] <= 105
// No two adjacent cells are equal.

/*
Approach:
    We can use a brute force algorithm to find a peak element.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        for (auto& v: mat)
        {
            v.push_back(-1);
            v.insert(v.begin(), -1);
        }
        vector<int> result {};
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> temp(n, -1);
        mat.insert(mat.begin(), temp);
        mat.push_back(temp);
        bool find = false;
        for (int i=1; i<mat.size()-1; ++i)
        {
            for (int j=1; j<mat[0].size()-1; ++j)
            {
                int val = mat[i][j];
                if (val > mat[i - 1][j] && val > mat[i + 1][j] && val > mat[i][j - 1] && val > mat[i][j + 1])
                {
                    result.push_back(i - 1);
                    result.push_back(j - 1);
                    find = true;
                    break;
                }
                
            }
            if (find)
            {
                break;
            }
        }
        return result;
    }
};