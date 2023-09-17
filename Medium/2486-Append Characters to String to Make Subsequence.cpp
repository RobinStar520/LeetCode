// You are given two strings s and t consisting of only lowercase English letters.

// Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

// Example 1:

// Input: s = "coaching", t = "coding"
// Output: 4
// Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
// Now, t is a subsequence of s ("coachingding").
// It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
// Example 2:

// Input: s = "abcde", t = "a"
// Output: 0
// Explanation: t is already a subsequence of s ("abcde").
// Example 3:

// Input: s = "z", t = "abcde"
// Output: 5
// Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
// Now, t is a subsequence of s ("zabcde").
// It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
 

// Constraints:

// 1 <= s.length, t.length <= 105
// s and t consist only of lowercase English letters.

/*
Approach:
    We can use a greedy algorithm: match the letter as many as possible. Find the longest prefix of t that is a subsequence of s. To reduce the time 
complexity, we can use the bianry search.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution 
{
public:
    int appendCharacters(string s, string t) 
    {
        // Record the indices of each letter.
        unordered_map<char, set<int>> _map {};
        const int n = s.length();
        for (int i=0; i<n; ++i)
        {
            _map[s[i]].insert(i);
        }
        int matched = 0;
        // The start position. It should be moved to the current position when we find a letter.
        int currentIndex = -1;
        for (const auto& ch: t)
        {
            auto iter = _map[ch].upper_bound(currentIndex);
            if (iter != _map[ch].end())
            {
                currentIndex = *iter;
                matched ++;
            }
            else
            {
                break;
            }
        }
        return static_cast<int>(t.length() - matched);
    }
};