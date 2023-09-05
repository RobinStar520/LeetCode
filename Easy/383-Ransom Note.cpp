// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

/*
Approach:
    This is an easy question using a hash table. Just simulate the process and judge each letter in the magazine.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> _map {};
        for (const auto& ch: magazine)
        {
            _map[ch] ++;
        }
        for (const auto& ch: ransomNote)
        {
            if (_map.find(ch) == _map.end())
            {
                return false;
            }
            _map[ch] --;
            // This step is important since the frequency may become negative, but it's not allowed.
            if (_map[ch] <= 0)
            {
                _map.erase(ch);
            }
        }
        return true;
    }
};