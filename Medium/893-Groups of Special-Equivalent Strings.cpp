// You are given an array of strings of the same length words.

// In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].

// Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j].

// For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz".
// A group of special-equivalent strings from words is a non-empty subset of words such that:

// Every pair of strings in the group are special equivalent, and
// The group is the largest size possible (i.e., there is not a string words[i] not in the group such that words[i] is special-equivalent to every string in the group).
// Return the number of groups of special-equivalent strings from words.

 

// Example 1:

// Input: words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
// Output: 3
// Explanation: 
// One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings is all pairwise special equivalent to these.
// The other two groups are ["xyzz", "zzxy"] and ["zzyx"].
// Note that in particular, "zzxy" is not special equivalent to "zzyx".
// Example 2:

// Input: words = ["abc","acb","bac","bca","cab","cba"]
// Output: 3
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 20
// words[i] consist of lowercase English letters.
// All the strings are of the same length.

/*
Approach:
    According to the question description: In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i]. So we can
divide the letters in the string into two groups: 0 and 1, which denotes the letter is in the odd/even index. If two strings have the same structure after collecting 
all the letters, we consider they should belong to the same group.

*/

#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class Solution 
{
public:
    int numSpecialEquivGroups(vector<string>& words) 
    {
        set<map<int, multiset<char>>> _set {};
        for (const auto& word: words)
        {
            map<int, multiset<char>> _map {};
            for (int i=0; i<word.length(); ++i)
            {
                _map[i % 2].insert(word[i]);
            }
            
            _set.insert(_map);
        }
        return static_cast<int>(_set.size());
    }
};