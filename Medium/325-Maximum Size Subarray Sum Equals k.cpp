// Given an integer array nums and an integer k, return the maximum length of a 
// subarray
//  that sums to k. If there is not one, return 0 instead.

 

// Example 1:

// Input: nums = [1,-1,5,-2,3], k = 3
// Output: 4
// Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
// Example 2:

// Input: nums = [-2,-1,2,1], k = 1
// Output: 2
// Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 

// Constraints:

// 1 <= nums.length <= 2 * 105
// -104 <= nums[i] <= 104
// -109 <= k <= 109

/*
Approach:
    Prefix-sum technique + hashmap.
*/


#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        unordered_map<int, int> _map {};
        const int n = nums.size();
        int result = 0;
        vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for (int i=1; i<=n; ++i)
        {
            prefix[i] = nums[i - 1] + prefix[i - 1];
            _map[prefix[i]] = i;
        }
        for (int i=0; i<n; ++i)
        {
            int val = k - nums[i];
            if (_map.find(prefix[i + 1] + val) != _map.end())
            {
                result = std::max(result, _map[prefix[i + 1] + val] - i);
            }
        }

        return result;
    }
};