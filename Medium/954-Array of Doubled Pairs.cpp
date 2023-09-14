// Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

// Example 1:

// Input: arr = [3,1,3,6]
// Output: false
// Example 2:

// Input: arr = [2,1,2,6]
// Output: false
// Example 3:

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
 

// Constraints:

// 2 <= arr.length <= 3 * 104
// arr.length is even.
// -105 <= arr[i] <= 105

/*
Approach:
    There are many solutions for this question; I chose a greedy algorithm: First, count the frequency of each letter; Second, traverse the container,
if the frequency of the current letter is zero, skip it since frequency can't be a negative number. Then, judge the current letter via this condition:
arr[2 * i + 1] = 2 * arr[2 * i].
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        // value -> count
        unordered_map<int, int> _map {};
        for (const auto& i: arr)
        {
            _map[i] ++;
        }
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        for (int i=0; i<n; ++i)
        {
            if (_map[arr[i]] == 0)
            {
                continue;
            }
            if (_map[arr[i] * 2] > 0)
            {
                // Here, we must remove the key if _map[arr[i] * 2] == 1 since the value of the _map[arr[i] * 2] maybe a negative number.
                _map[arr[i] * 2] == 1 ? _map.erase(arr[i] * 2) : _map[arr[i] * 2] --;
                _map[arr[i]] == 1 ? _map.erase(arr[i]) : _map[arr[i]] --;
            }
        }
        for (const auto& [key, value]: _map)
        {
            if (value > 0)
            {
                return false;
            }
        }
        return true;
    }
};