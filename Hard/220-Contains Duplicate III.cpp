// You are given an integer array nums and two integers indexDiff and valueDiff.

// Find a pair of indices (i, j) such that:

// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.

 

// Example 1:

// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
// Example 2:

// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
 

// Constraints:

// 2 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 1 <= indexDiff <= nums.length
// 0 <= valueDiff <= 109

/*
Approach:
    This quesiton belongs to a series of questions(Contains Duplicate I, II), and this qeustion has two extra conditions: "abs(i - j) <= indexDiff." and
"abs(nums[i] - nums[j]) <= valueDiff". When we confronting this kind of question with the absolute value, consider using a hash table to track the maximum 
or minimum value.
*/

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        // Attention: Use a multiset instead of a common set(set) since there can be duplicate numbers in the set.
        multiset<long long> _set;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            // Which step should be the first? Removing an element in the set or insert it? Actually, we ought to remove the element.
            if (i > indexDiff)
            {
                _set.erase(nums[i - indexDiff - 1]);
            }
            // Here, since the value "nums[i] - valueDiff" can be a very small negative number, so it's necessary to convert it to the long type.
            auto iter = _set.lower_bound(static_cast<long long>(nums[i]) - valueDiff);
            if (iter != _set.end() && abs(*iter - nums[i]) <= valueDiff)
            {
                return true;
            }
            
            _set.insert(nums[i]);
        }
        
        return false;
    }
};