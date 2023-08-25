// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

/*
Approach:
    This question has two difficulties: one is to remove quadruple with duplicate elements, and the other is to reduce the time complexity. This question 
doesn't ask us to find a result related to the index, so we can sort the whole vector to deduplicate. Using an extra space may be helpful, like a hash
map. But on the other hand, this would take us more time to remove the duplicate elements. So the most efficient algorithm for this question is a two-pointer
approach.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> result {};
        for (int i=0; i<n; ++i)
        {
            // Deduplicate
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j=i+1; j<n; ++j)
            {
                // Deduplicate
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                // two pointers
                int left = j + 1;
                int right = n - 1;
                while (right > left)
                {
                    // Attention: Here we have to convert each element to "long" type due to some edge test cases. For example: 
                    // nums[i] + nums[j] + nums[left] + nums[right] = 2000000000 + 1000000000. This will cause runtime error.
                    if (nums[i] * 1l + nums[j] * 1l + nums[left] * 1l + nums[right] * 1l > target)
                    {
                        right --;
                    }
                    else if (nums[i] * 1l + nums[j] * 1l + nums[left] * 1l + nums[right] * 1l < target)
                    {
                        left ++;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // Move two pointers until the last elements are not equal(nums[right], nums[right - 1])
                        // Be aware that "right" is the rightmost index, so each movement should be subtracted.
                        while (right > left && nums[right] == nums[right - 1])
                        {
                            right --;
                        }
                        while (right > left && nums[left] == nums[left + 1])
                        {
                            left ++;
                        }
                        // Mooe two pointers
                        right --;
                        left ++;
                    }
                }
            }
        }
        return result;
    }
};