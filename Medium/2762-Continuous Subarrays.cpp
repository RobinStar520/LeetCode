// You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

// Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
// Return the total number of continuous subarrays.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [5,4,2,4]
// Output: 8
// Explanation: 
// Continuous subarray of size 1: [5], [4], [2], [4].
// Continuous subarray of size 2: [5,4], [4,2], [2,4].
// Continuous subarray of size 3: [4,2,4].
// Thereare no subarrys of size 4.
// Total continuous subarrays = 4 + 3 + 1 = 8.
// It can be shown that there are no more continuous subarrays.
 

// Example 2:

// Input: nums = [1,2,3]
// Output: 6
// Explanation: 
// Continuous subarray of size 1: [1], [2], [3].
// Continuous subarray of size 2: [1,2], [2,3].
// Continuous subarray of size 3: [1,2,3].
// Total continuous subarrays = 3 + 2 + 1 = 6.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

/*
Approach:
    Obviously, this problem can be solved using two-pointers or sliding window techniques. The key point of the question is to track the maximum value of 
"|nums[i1] - nums[i2]|". You can use a max heap, but this may cause another problem that if you want to delete a specified value you have to clean up the
whole heap and push the rest elements again, this is a waste of time, so thinks of using a set. This can get the minimum and maximum value simultaneously.
*/

#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

class Solution 
{
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        long long result = 0ll;
        const int n = nums.size();
        multiset<int> _set {};
        int i = 0, j = 0;
        while (j < n)
        {
            _set.insert(nums[j]);
            while (!_set.empty() && (*_set.rbegin() - *_set.begin()) > 2)
            {
                _set.erase(_set.find(nums[i]));
                i += 1;
            }
            result += (j - i + 1);
            j += 1;
        }
        return result;
    }
};