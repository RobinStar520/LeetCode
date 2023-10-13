// You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].

// Return any permutation of nums1 that maximizes its advantage with respect to nums2.

 

// Example 1:

// Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
// Output: [2,11,7,15]
// Example 2:

// Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
// Output: [24,32,8,12]
 

// Constraints:

// 1 <= nums1.length <= 105
// nums2.length == nums1.length
// 0 <= nums1[i], nums2[i] <= 109
// Accepted
// 63.5K
// Submissions
// 121.7K
// Acceptance Rate
// 52.1%

/*
Approach:
    For this question, we can use a greedy approach: For each element in the "nums2" vector, we try to find the first number that is larger than the 
element in the "nums1" vector. Apparently, binary search is a good choice.
*/

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result(nums1.size(), 0);
        map<int, int> _map {};
        for (const auto& i: nums1)
        {
            _map[i] += 1;
        }
        for (int i=0; i<nums2.size(); ++i)
        {
            // Binary search.
            auto iter = _map.upper_bound(nums2[i]);
            if (iter == _map.end())
            {
                result[i] = -1;
            }
            else
            {
                result[i] = iter->first;
                _map[iter->first] -= 1;
                if (_map[iter->first] <= 0)
                {
                    _map.erase(iter->first);
                }
            }

        }

        for (int i=0; i<nums2.size(); ++i)
        {
            if (result[i] == -1)
            {
                int val = _map.begin()->first;
                _map[val] -= 1;
                if (_map[val] <= 0)
                {
                    _map.erase(val);
                }
                result[i] = val;
            }
        }

        return result;
    }
};