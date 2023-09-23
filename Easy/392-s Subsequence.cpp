// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false
 

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.
 

// Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

/*
Approach:
    If we use a common approach, the time complexity will be O(n ^ 2). We can use a hashmap to store the index of each letter to improve the searching
speed.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        unordered_map<char, vector<int>> _map {};
        for (int i=0; i<t.length(); ++i)
        {
            _map[t[i]].push_back(i);
        }
        int cur = -1;
        for (const auto& ch: s)
        {
            if (_map.find(ch) == _map.end())
            {
                return false;
            }
            auto iter = upper_bound(_map[ch].cbegin(), _map[ch].cend(), cur);
            if (iter == _map[ch].cend())
            {
                return false;
            }
            cur = *iter;
        }
        return true;
    }
};