// Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

// A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

 

// Example 1:


// Input: picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
// Output: 3
// Explanation: All the three 'B's are black lonely pixels.
// Example 2:


// Input: picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
// Output: 0

/*
Approach:
    We can use two hashmaps to store how many pixels does a row and column have to reduce the time complexity.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int findLonelyPixel(vector<vector<char>>& picture) 
    {
        int result = 0;
        unordered_map<int, vector<int>> rows {}, columns {};
        for (int i=0; i<picture.size(); ++i)
        {
            for (int j=0; j<picture[i].size(); ++j)
            {
                if (picture[i][j] == 'B')
                {
                    rows[i].push_back(j);
                    columns[j].push_back(i);
                    
                }
            }
        }
        for (const auto& [row, v]: rows)
        {
            for (const auto& i: v)
            {
                if (columns[i].size() == 1 && v.size() == 1)
                {
                    result += 1;
                }

            }
        }
        return result;
    }
};