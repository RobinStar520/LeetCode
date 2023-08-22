// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.
 

// Constraints:

// 1 <= k <= nums.length <= 105
// 1 <= nums[i] <= 105

/*
Approach: 
    We can use the sliding window technique to solve this problem. The problem asks us to find a k-length subarray without duplicate elements, our first impression
is to use a set or similar data structure to track the single element.However, this method can't work due to some special cases like [2, 2, 2, 1, 3]. So we should use
a hash table instead of a set.
*/

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        // value -> count
        unordered_map<int, int> _map {};
        // all the elements in the vector are non-negative numbers, so set the initial value of the result as 0.
        long long result = 0ll;
        long long curSum = accumulate(nums.cbegin(), nums.cbegin() + k, 0ll, plus<long long>());
        for (int i=0; i<k; ++i)
        {
            _map[nums[i]] ++;
        }
        // Think of the first k elements. 
        if (_map.size() == k)
        {
            result = std::max(curSum, result);
        }
        const int n = nums.size();
        // Be aware of the range of the for-loop
        for (int i=1; i<n-k+1; ++i)
        {
            _map[nums[i - 1]] --;
            // This step is important, to ensure remove the element that occurrence is zero, otherwise, the number of elements can't decrease.
            if (_map[nums[i - 1]] <= 0)
            {
                _map.erase(nums[i - 1]);
            }
            _map[nums[i + k - 1]] ++;
            curSum -= nums[i - 1];
            curSum += nums[i + k - 1];
            // As long as the the size of map equals k, we compare the current value to the final result. Otherwise, we do nothing.
            if (_map.size() == k)
            {
                result = std::max(result, curSum);
            }
            
        }
        return result;
    }
};
