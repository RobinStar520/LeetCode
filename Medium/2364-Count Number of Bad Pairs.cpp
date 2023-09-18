// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

 

// Example 1:

// Input: nums = [4,1,3,3]
// Output: 5
// Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
// The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
// The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
// The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
// The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
// There are a total of 5 bad pairs, so we return 5.
// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 0
// Explanation: There are no bad pairs.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

/*
Approach:
    There are two constraints of a bad pair. It's not very easy to calculate the number of bad pairs, so we can count the number of good pairs.
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution 
{
public:
    long long countBadPairs(vector<int>& nums) 
    {
        // nums[i] - i -> count
        unordered_map<int, int> _map {};
        const int n = nums.size();
        // Note: the result may larger than 2 ^ 31 - 1.
        long long result = (n *1ll - 1) * n / 2;
        for (int i=0; i<n; ++i)
        {
            _map[nums[i] - i] ++;
        }
        for (const auto& [key, value]: _map)
        {
            if (value != 1)
            {
                result -= value *1ll * (value -1) / 2;
            }
        }
        return result;
    }
};