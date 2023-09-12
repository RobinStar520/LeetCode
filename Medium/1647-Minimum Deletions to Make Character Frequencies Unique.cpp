// A string s is called good if there are no two different characters in s that have the same frequency.

// Given a string s, return the minimum number of characters you need to delete to make s good.

// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

// Example 1:

// Input: s = "aab"
// Output: 0
// Explanation: s is already good.
// Example 2:

// Input: s = "aaabbbcc"
// Output: 2
// Explanation: You can delete two 'b's resulting in the good string "aaabcc".
// Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
// Example 3:

// Input: s = "ceabaacb"
// Output: 2
// Explanation: You can delete both 'c's resulting in the good string "eabaab".
// Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
 

// Constraints:

// 1 <= s.length <= 105
// s contains only lowercase English letters.

/*
Approach:
    A step-by step approach:
    1.Count the character frequencies.
    2.Sort the frequencies.
    3.Iterate from the highest frequency to the second highest.
    4.Determine how much to deduct from the current frequency to make it less than or equal to the next frequency.
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minDeletions(string s) 
    {
        vector<int> freq(26, 0);
        unordered_set<int> _set {};
        for (const auto& ch: s)
        {
            freq[ch - 'a'] += 1;
        }
        int result = 0;
        for (int i=0; i<26; ++i)
        {
            int cur = freq[i];
            while (cur > 0 && _set.find(cur) != _set.end())
            {
                result += 1;
                cur -= 1;
            }
            _set.insert(cur);
        }
        return result;
    }
};