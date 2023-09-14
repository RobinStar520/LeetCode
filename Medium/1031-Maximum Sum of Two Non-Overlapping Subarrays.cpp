// Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

// The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
// Output: 20
// Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
// Example 2:

// Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
// Output: 29
// Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
// Example 3:

// Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
// Output: 31
// Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
 

// Constraints:

// 1 <= firstLen, secondLen <= 1000
// 2 <= firstLen + secondLen <= 1000
// firstLen + secondLen <= nums.length <= 1000
// 0 <= nums[i] <= 1000

/*
Approach:
    We can use prefix sums to calculate any subarray sum quickly. For each L length subarray, find the best possible M length subarray that occurs 
before and after it.
*/

#include <vector>
#include <numeric>
#include <functional>
#include <limits>

using namespace std;

class Solution 
{
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) 
    {
        const int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i=1; i<n; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int result = numeric_limits<int>::min();
        int i = 0, j = firstLen - 1;
        while (j < n)
        {
            int first = prefixSum[j] - prefixSum[i] + nums[i];
            // There are two situations here:
            // 1.Both the left side and the right side's length are longer than the "secondLen".
            // 2. Only one side we can choose to calculate.
            if (i >= secondLen)
            {
                int second = numeric_limits<int>::min();
                for (int k=0; k<=i-secondLen; ++k)
                {
                    second = std::max(second, prefixSum[k + secondLen - 1] - prefixSum[k] + nums[k]);
                }
                result = std::max(result, first + second);
            }
            if (j + secondLen <= n-1)
            {
                int second = numeric_limits<int>::min();
                for (int k=j+1; k<=n-secondLen; ++k)
                {
                    second = std::max(second, prefixSum[k + secondLen - 1] - prefixSum[k] + nums[k]);
                }
                result = std::max(result, first + second);
            }
            i ++;
            j ++;
        }
        return result;
    }
};