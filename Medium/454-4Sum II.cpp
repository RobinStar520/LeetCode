// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

// Example 1:

// Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// Output: 2
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
// Example 2:

// Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// Output: 1
 

// Constraints:

// n == nums1.length
// n == nums2.length
// n == nums3.length
// n == nums4.length
// 1 <= n <= 200
// -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

/*
Approach:
    If we use the brute force algorithm, the time complexity will be O(n^4) since we have four indices: (i,j,k,l). To reduce the time complexity, we can
use two hashmaps to store the frequency of the sum of each pair(i, j).
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        const int n = nums1.size();
        // Count the frequency individually, so we use two hashmaps.
        unordered_map<int, int> map1 {}, map2 {};
        int result = 0;
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                map1[nums1[i] + nums2[j]] ++;
                map2[nums3[j] + nums4[i]] ++;
            }
        }
        for (const auto& [key, value]: map1)
        {
            if (map2.find(-key) != map2.end())
            {
                result += value * map2[-key];
            }
        }
        return result;
    }
};