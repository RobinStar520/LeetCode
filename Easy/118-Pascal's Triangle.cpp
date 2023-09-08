// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30

/*
Approach:
    This is a purely mathmatical problem. If you know the Pascal's triangle, the question will become easy.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        // define a vector to store all the results
        vector<vector<int>> res {};
        for (int i=0; i<numRows; ++i)
        {
            res.push_back(vector<int>(i+1, 1));
        }


        for (int i=2; i<numRows; ++i)
        {
            vector<int> layer(i+1, 1);

            for (int j=1;j<layer.size()-1; ++j)
            {
                layer[j] = res[i-1][j-1] + res[i-1][j];
            }
            res[i] = layer;
        }
        return res;
    }
};