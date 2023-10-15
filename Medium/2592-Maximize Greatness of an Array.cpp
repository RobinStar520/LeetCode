// You are given a 0-indexed integer array nums. You are allowed to permute nums into a new array perm of your choosing.

// We define the greatness of nums be the number of indices 0 <= i < nums.length for which perm[i] > nums[i].

// Return the maximum possible greatness you can achieve after permuting nums.

 

// Example 1:

// Input: nums = [1,3,5,2,1,3,1]
// Output: 4
// Explanation: One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
// At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 3
// Explanation: We can prove the optimal perm is [2,3,4,1].
// At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

/*
Approach:
    We can use a greedy approach to solve this problem. For each element in the vector, we try to find the first element greater than it.
*/

#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        int result = 0;
        // value -> count
        map<int, int> _map {};
        for (const auto& i: nums)
        {
            _map[i] ++;
        }
        vector<int> vct {};
        for (const auto& i: nums)
        {
            auto iter = _map.upper_bound(i);
            if (iter == _map.end())
            {
                iter = _map.begin();
            }
            int val = iter->first;
            vct.push_back(val);
            _map[val] --;
            if (_map[val] <= 0)
            {
                _map.erase(val);
            }
        }
        const int n = nums.size();
        for (int i=0; i<n; ++i)
        {
            if (vct[i] > nums[i])
            {
                result += 1;
            }
        }
        return result;
    }
};