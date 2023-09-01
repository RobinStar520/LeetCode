// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.
 

// Constraints:

// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lowercase English letters.


/*
Approach:
   This is a typical backtracking problem. We can enumerate all the possibilities and check them individually, then get the maximum length string.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        int result = 0;
        string item {};
        unordered_map<char, int> _map {};
        this->backtracking(0, result, item, arr, _map);
        return result;
    }

private:
    bool hasSame(string& str1, string& str2, unordered_map<char, int>& _map)
    {
        // Attention: Clean the hash map first; otherwise, it will save the previous state.
        _map.clear();
        for (const auto& ch: str1)
        {
            _map[ch] ++;
        }
        for (const auto& ch: str2)
        {
            _map[ch] ++;
        }
        for (const auto& [key, value]: _map)
        {
            if (value > 1)
            {
                return true;
            }
        }
        return false;
    }
    
    // Backtravking method
    // Set the Deduplication hash map as a parameter to avoid reallocating the space and causing time waste.
    void backtracking(int start, int& maxSize, string& item, vector<string>& arr, unordered_map<char, int>& _map)
    {
        if (start >= arr.size())
        {
            return;
        }

        for (int i=start; i<arr.size(); ++i)
        {
            if (!hasSame(item, arr[i], _map))
            {
                item += arr[i];
                maxSize = std::max(static_cast<int>(item.length()), maxSize);
                this->backtracking(i+1, maxSize, item, arr, _map);
                for (int j=0; j<arr[i].length(); ++j)
                {
                    item.pop_back();
                }
            }
        }
        return;
    }
};