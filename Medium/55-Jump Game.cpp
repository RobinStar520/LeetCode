// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

/*
Approach:
    Obviously, this is a greedy algorithm question. In each jumping, we want to jump as far as possible. In one step, if we find that the distance we can jump in the 
next step can't reach the last element, which means we will fail anyway, so we just need to find the longest distance we can jump in each step. What's more, thinking of 
some edge cases, like the length of array is one, which means we don't need to do anything due to the start position and the end position  overlapping.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        const int n = nums.size();
        // special situation, the length of the array is one.
        if (n == 1)
        {
            return true;
        }
        // the variable "range" repersents the longest distance that we can reach.
        int range = 0;
        
        for (int i=0; i<=range; ++i)
        {
            // find the next longest distance we can get.
            range = std::max(range, i + nums[i]);
            // if the longest distance is more than the length of array, it means we can reach the last position.
            if (range >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};