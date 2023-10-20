
// You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [42,11,1,97]
// Output: 2
// Explanation: The two pairs are:
//  - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
//  - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
// Example 2:

// Input: nums = [13,10,35,24,76]
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

/*
Approach:
    The condition can be rearranged to (nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])), so we can transform each nums[i] into (nums[i] - rev(nums[i])). 
Then, count the number of (i, j) pairs that have equal values. Keep a map storing the frequencies of values that you have seen so far. For each i, check if 
nums[i] is in the map. If it is, then add that count to the overall count. Then, increment the frequency of nums[i].
*/

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int countNicePairs(vector<int>& nums) 
    {
        // value -> frequency
        int MOD = 1e9 + 7;
        unordered_map<int, long long> _map {};
        for (auto& num: nums)
        {
            string str = to_string(num);
            reverse(str.begin(), str.end());
            num -= stoi(str);
            _map[num] += 1;
        }
        long long result = 0ll;
        for (const auto& [key, value]: _map)
        {
            if (value >= 2)
            {
                result += value * 1ll *(value - 1) / 2 ;
            }
        }
        return result % MOD;
    }


};