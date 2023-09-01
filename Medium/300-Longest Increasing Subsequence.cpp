// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

/*
Approach:
    We can't use two-pointers algorithm or sliding window techniques since the final result is not a consecutive vector. Think about the dynamic
programming. Let's use a vector called "dp", and the index i denotes the longest increasing subsequence we can get from 0 ~ i. Obviously,
dp[i] = 1 + dp[j] (0 <= j < i). So, we need to use two loops to find the "dp[j]".
*/


#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<int> dp(n + 1, 1);
        for (int i=1; i<n; ++i)
        {
            for (int j=0; j<i; ++j)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};