// You are given an integer array nums. A subsequence of nums is called a square streak if:

// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.
// Example 2:

// Input: nums = [2,3,5,6,7]
// Output: -1
// Explanation: There is no square streak in nums so return -1.
 

// Constraints:

// 2 <= nums.length <= 105
// 2 <= nums[i] <= 105

/*
Approach:
    This question, we can use a greedy algorithm. First, sort the vector; Second, count the frequency of each number; Third, use a loop to find the 
longest square streak.
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution 
{
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        unordered_map<long long, int> _map {};
        for (const auto& i: nums)
        {
            _map[i] ++;
        }
        sort(nums.begin(), nums.end());
        int result = -1;
        for (const auto& i: nums)
        {
            if (_map.empty())
            {
                break;
            }
            int len = 0;
            // Note the data range of the variable "current". We can't define it as an int value.
            long long current = i * 1ll;
            while (_map.find(current) != _map.end())
            {
                _map.erase(current);
                ++len;
                current = pow(current, 2);
            }
            // If the value of "len" is one, we don't update it, because the final result should be larger than two.
            result = len > 1 ? max(len, result) : result;
        }
        return result; 
    }
};