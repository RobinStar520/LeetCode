// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

/*
Approach:
    We can use a hash table to determine which line the current character belongs to. Note when "numRom" is one, the final result will not change.
*/

#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
        {
            return s;
        }
        map<int, vector<char>> _map {};
        string result {};
        const int n = s.length();
        int cur_level = 1;
        for (int i=0; i<n; ++i)
        {
            if (cur_level < numRows)
            {
                _map[cur_level].push_back(s[i]);
                cur_level ++;
            }
            else
            {
                int j {};
                for (j=i; j<n; ++j)
                {
                    
                    _map[cur_level].push_back(s[j]);
                    cur_level -= 1;
                    if (cur_level == 1)
                    {
                        break;
                    }
                }
                i = j;
                
            }
        }
        // Append the characters to the final result.
        for (const auto& [key, value]: _map)
        {
            for (const auto& ch: value)
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};