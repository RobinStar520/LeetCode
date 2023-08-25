// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105

/*
Approach:
    This is a series of questions. The solution to the previous question "217-Contains Duplicate" is straightforward. The only difference between them
is that it has an extra condition. We can use a hash table to track the index of each element, as long as finding an element satisfies the condition, return 
true. Otherwise, return false.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        // value -> vector[index]
        // In fact, we can just store the last index of each element since we don't care about all the previous index of an element.
        unordered_map<int, vector<int>> _map {};
        const int n = nums.size();
        for (int i=0; i<n; ++i)
        {
            if (_map.find(nums[i]) != _map.end())
            {
                int last = _map[nums[i]].back();
                if (i - last <= k)
                {
                    return true;
                }
            }
            _map[nums[i]].push_back(i);
        }
        return false;
    }
};