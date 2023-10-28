// You are given an integer num. You will apply the following steps exactly two times:

// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// The new integer cannot have any leading zeros, also the new integer cannot be 0.
// Let a and b be the results of applying the operations to num the first and second times, respectively.

// Return the max difference between a and b.

 

// Example 1:

// Input: num = 555
// Output: 888
// Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
// The second time pick x = 5 and y = 1 and store the new integer in b.
// We have now a = 999 and b = 111 and max difference = 888
// Example 2:

// Input: num = 9
// Output: 8
// Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
// The second time pick x = 9 and y = 1 and store the new integer in b.
// We have now a = 9 and b = 1 and max difference = 8
 

// Constraints:

// 1 <= num <= 108

/*
Approach:
    We can use a brute force algortithm to solve it as the constraint is small.
*/

#include <string>
#include <queue>
#include <limits>

using namespace std;

class Solution 
{
public:
    int maxDiff(int num) 
    {
        string str = to_string(num);
        const int n = str.length();
        int minval = numeric_limits<int>::max();
        int maxval = numeric_limits<int>::min();

        // Peplace digits one by one from 0 to 9.
        for (char i='0'; i<='9'; ++i)
        {
            for (char j='0'; j<='9'; ++j)
            {
                string copy = str;
                for (auto& ch: copy)
                {
                    if (ch == j)
                    {
                        ch = i;
                    }
                }
                if (copy.front() == '0')
                {
                    continue;
                }
                minval = std::min(minval, stoi(copy));
                maxval = std::max(maxval, stoi(copy));
            }
        }


        return maxval - minval;
    }
};