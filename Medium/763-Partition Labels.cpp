// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

/*
Approach:
    This question seems to use an algorithm related to backtracking, but actually does not. We just need to find the furthest border of each letter in the
sequence we traversed before. We can divide the task into two steps: First, get the final position for each letter; Second, traverse the whole sequence, and update
the letter's furthest index. If we find the furthest index equals the current index, it means we find a new separation point. 
*/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> result {};
        // Get the last index of each letter.
        unordered_map<char, int> _map {};
        const int n = s.length();
        for (int i=0; i<n; ++i)
        {
            _map[s[i]] = i;
        }
        int left = 0;
        int right = 0;
        for (int i=0; i<n; ++i)
        {
            // Update the furthest index for each letter.
            right = std::max(right, _map[s[i]]);
            // If the current idnex equals the furthest index, it means we have find a separtion point, and add it to the result vector.
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }

};