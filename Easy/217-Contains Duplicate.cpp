// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

/*
Approach:
    This is a series of questions, and this is the simplest one. Use a hash table to statistic the occurrence of each element in the vector.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // It's unnecessary to use an ordered map since this question just counts the occurrence of each element.
        unordered_map<int, int> _map {};
        int total = 0;
        for (const auto& i: nums)
        {
            _map[i] ++;
            if (_map[i] >= 2)
            {
                return true;
            }
        }
        return false;
        
    }
};