// Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
 

// Example 1:

// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3
// Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
// Example 2:

// Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
// Output: 2
 

// Constraints:

// 1 <= s.length <= 5 * 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 50
// s and words[i] consist of only lowercase English letters.

/*
Approach:
    We can't use the traditional string matching in this question since the pattern strings are not consecutive. So we can use a hash table to record the
indices for the letters in the string. For example, the hash table of a string "dwacbcayubdga" may look like:
    'd': [0, 10]
    'w': [1]
    'a': [2, 6, 13]
    'c': [3, 5]
    'b: [4. 9]
    'y': [7]
    'u': [8]
    'g':[12]
    For each matting, we just record the index of the previous letter and try to find whether the next letter's index is larger than the previous index.
*/

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<char, vector<int>> _map {};
        const int n = s.length();
        for (int i=0; i<n; ++i)
        {
            _map[s[i]].push_back(i);
        }

        int result = 0;
        for (const auto& word: words)
        {
            if (this->in(word, _map))
            {
                result += 1;
            }
        }
        return result;

    }

private:
    bool in(const string& word, unordered_map<char, vector<int>>& _map)
    {
        // This variable denotes the previous letter's index. The initial value is -1.
        int lastIndex = -1;
        for (const auto& ch: word)
        {
            // First, we need to inspect whether the letter "ch" exists in the hash table.
            if (_map.find(ch) == _map.end())
            {
                return false;
            }
            // Use the binary search to optimise the time complexity.
            auto iter = upper_bound(_map[ch].cbegin(), _map[ch].cend(), lastIndex);
            if (iter == _map[ch].cend())
            {
                return false;
            }
            // Update the previous letter's index.
            lastIndex = *iter;
        }
        return true;
    }
};