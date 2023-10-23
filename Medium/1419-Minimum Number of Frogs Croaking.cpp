// You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.

// Return the minimum number of different frogs to finish all the croaks in the given string.

// A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.

 

// Example 1:

// Input: croakOfFrogs = "croakcroak"
// Output: 1 
// Explanation: One frog yelling "croak" twice.
// Example 2:

// Input: croakOfFrogs = "crcoakroak"
// Output: 2 
// Explanation: The minimum number of frogs is two. 
// The first frog could yell "crcoakroak".
// The second frog could yell later "crcoakroak".
// Example 3:

// Input: croakOfFrogs = "croakcrook"
// Output: -1
// Explanation: The given string is an invalid combination of "croak" from different frogs.
 

// Constraints:

// 1 <= croakOfFrogs.length <= 105
// croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.

/*
Approach:
    We can keep track of the frequency of each letter in the pattern string. Try to match characters as many as possible. 
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        int result = -1;
        // If you don't like using so many variables, you can use a hashmap instead.
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        for (const auto& ch: croakOfFrogs)
        {
            switch (ch)
            {
                case 'c':
                    c += 1;
                    result = std::max(c, result);
                    break;
                case 'r':
                    r += 1;
                    if (r > c)
                    {
                        return -1;
                    }
                    break;
                case 'o':
                    o += 1;
                    if (o > c || o > r)
                    {
                        return -1;
                    }
                    break;
                case 'a':
                    a += 1;
                    if (a > o || a > r || a > c)
                    {
                        return -1;
                    }
                    break;
                case 'k':
                    a -= 1;
                    o -= 1;
                    r -= 1;
                    c -= 1;
                    if (a < 0 || o < 0 || r < 0 || c < 0)
                    {
                        return -1;
                    }
                    break;
                default:
                    break;
            }
        }
        // Inspect validation.
        if (c != 0 || r != 0 || o != 0 || a != 0 || k != 0)
        {
            return -1;
        }
        return result;
    }
};