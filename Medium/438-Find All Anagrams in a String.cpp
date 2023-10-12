// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
 

// Constraints:

// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters.

/*
Approach:
    We can use the sliding window technique. Use a hashmap to keep track of a given length string, and check how many anagrams another string has.
*/

#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char, int> map1 {}, map2 {};
        vector<int> result {};
        if (p.length() > s.length())
        {
            return result;
        }
        for (const auto& ch: p)
        {
            map2[ch] += 1;
        }
        const int n = p.length();
        for (int i=0; i<n; ++i)
        {
            map1[s[i]] += 1;
        }
        if (map1 == map2)
        {
            result.push_back(0);
        }

        for (int i=1; i<s.length()-n+1; ++i)
        {
            map1[s[i - 1]] --;
            if (map1[s[i - 1]] <= 0)
            {
                map1.erase(s[i - 1]);
            }
            map1[s[i + n - 1]] += 1;
            if (map1 == map2)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};