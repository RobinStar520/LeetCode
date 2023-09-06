// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

/*
Approach:
    Statistic the frequency of each letter in string "s", and judge whether the corresponding frequency of each letter in string "t" equals.
You can use a hash table.
*/


#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> _map {};
        for (const auto& ch: s)
        {
            _map[ch] ++;
        }
        for (const auto& ch: t)
        {
            // This step is to filter the letter that never appears in the string "s"
            if (_map.find(ch) == _map.end())
            {
                return false;
            }
            _map[ch] --;
            if (_map[ch] <= 0)
            {
                _map.erase(ch);
            }
        }
        return _map.empty();
    }
};