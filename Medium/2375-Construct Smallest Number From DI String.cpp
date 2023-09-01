// You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

// A 0-indexed string num of length n + 1 is created using the following conditions:

// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
// Return the lexicographically smallest possible string num that meets the conditions.

 

// Example 1:

// Input: pattern = "IIIDIDDD"
// Output: "123549876"
// Explanation:
// At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
// At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
// Some possible values of num are "245639871", "135749862", and "123849765".
// It can be proven that "123549876" is the smallest possible num that meets the conditions.
// Note that "123414321" is not possible because the digit '1' is used more than once.
// Example 2:

// Input: pattern = "DDD"
// Output: "4321"
// Explanation:
// Some possible values of num are "9876", "7321", and "8742".
// It can be proven that "4321" is the smallest possible num that meets the conditions.
 

// Constraints:

// 1 <= pattern.length <= 8
// pattern consists of only the letters 'I' and 'D'.


/*
Approach:
    There are several approaches to solving this problem. Here, I chose to use the backtracking algorithm due to the small constraints. Enumerate all the
possibilities and check whether satisfied the conditions individually.
*/

#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution 
{
public:
    string smallestNumber(string pattern) 
    {
        const int n = pattern.length() + 1;
        string str {};
        // Use a priority queue to get the smallest string. 
        priority_queue<string, vector<string>, greater<string>> pq {};
        for (int i=1; i<=n; ++i)
        {
            str += to_string(i);
        }
        // We should sort the sequence first when we are using "next_permutation" in principle, but it's unnecessary here due to how we constructed
        // the str.
        do
        {
            if (isValid(pattern, str))
            {
                pq.push(str);
            }
        }
        while (next_permutation(str.begin(), str.end()));

        // while (!pq.empty())
        // {
        //     cout << pq.top() << endl;
        //     pq.pop();
        // }
        return pq.top();
    }

private:
    // This method is to check the string satisfying the conditions.
    bool isValid(string& pattern, string& str)
    {
        const int n = pattern.length();
        for (int i=0; i<n; ++i)
        {
            if (pattern[i] == 'I')
            {
                if (str[i] >= str[i + 1])
                {
                    return false;
                }
            }
            else if (pattern[i] == 'D')
            {
                if (str[i] <= str[i + 1])
                {
                    return false;
                }
            }

        }
        return true;
    }
};