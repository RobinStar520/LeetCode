// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104

/*
Approach:
    First impression: Using a brute force algorithm to get all the triplets, but this method can't pass all the test cases due to the time limit exceeded.
So we need to reconstruct the equation: result = min(nums[i] + nums[j] + nums[k] - target). We can get the value nums[i] + nums[k] by using two for loops,
and then we just need to find the first element satisfied this condition "result = min(target - nums[i] - nums[j])" since we don't care about the index of 
each element. Now think of sorting the whole vector, and using the binary search to find the nums[k] efficiently. There are many details that need to be paid 
attention to in the whole process and I have written some annotations to make the code easy to understand.
*/

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        // Here, we need to set a proper value initially based on the constraints, but the value can't be the INT_MAX liked since
        // in some next steps we will calculate "target - result", and this will cause data range overflow.
        int result = 99999;
        for (int i=0; i<n; ++i)
        {
            for (int j=i+1; j<n-1; ++j)
            {
                int k = target - nums[i] - nums[j];
                // Using binary search to search the first element equal or larger than k.
                auto iter = lower_bound(nums.cbegin() + j + 1, nums.cend(), k);
                
                int tempSum = nums[i] + nums[j];
                
                // Here, we need to compare the absolute value since the distance between two points is a non negative value
                if (iter != nums.cend())
                {
                    result = abs(target - (tempSum + *iter)) < abs(target - result) ? tempSum + *iter : result;
                }
                // Ditto
                if (iter != nums.cbegin() + j + 1)
                {
                    --iter;
                    result = abs(target - (tempSum + *iter)) < abs(target - result) ? tempSum + *iter : result;
                }
                
            }
        }
        return result;
    }
};