// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

// Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

 

// Example 1:

// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
// Example 2:

// Input: nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 

// Constraints:

// 2 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5 * 104

/*
Approach:
    For this question, my first feeling is using a monotonic stack. Unfortunately, I failed since the question doesn't ask us to find the first 
element larger or smaller than an element, and we need to find the last one that satisfies the condition. So, we can record the index and the value 
simultaneously, sort them by the value, and then traverse the container from end to front to get the maximum value.
*/

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        const int n = nums.size();
        int ans = 0;
        vector<pair<int,int>> new_nums {};
        for (int i=0; i<n; ++i) 
        {
            new_nums.push_back(make_pair(nums[i], i));
        }
        // Sort the containter by the key of pairs.
        sort(new_nums.begin(), new_nums.end());
        vector<int> arr {};
        for (const auto &p: new_nums)
        {
            arr.push_back(p.second);
        }
        int greatest = arr.back();
        for (int i=n-2; i>=0; i--)
        {
            if (arr[i] <= greatest)
            {
                ans = max(ans, greatest-arr[i]);
            }

            // This step is important, remember to update the greatest value.
            else
            {
                greatest = arr[i];
            }
        }
        return ans;
    }
};