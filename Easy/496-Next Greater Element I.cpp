// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.
 

// Follow up: Could you find an O(nums1.length + nums2.length) solution?

/*
Approach: 
    LeetCode marked this question as easy due to its small constraints, so we can use the brute forth algorithm that traverse the vector twice. This question
asks us to find the next greater element for each element, so think of using a monotonic stack, and then the time complexity of the algorithm will reduce to
O(nums1.length + nums2.length)
*/

#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        vector<int> result(n1, -1);
        stack<int> _stack {};
        // value -> index
        // Using a map aims to find the index quickly via the value.
        unordered_map<int, int> _map {};
        for (int i=0; i<n1; ++i)
        {
            _map[nums1[i]] = i;
        }
        _stack.push(0);
        for (int i=1; i<n2; ++i)
        {
            while (!_stack.empty() && nums2[i] > nums2[_stack.top()])
            {
                // try to find the index
                if (_map.find(nums2[_stack.top()]) != _map.end())
                {
                    int index = _map[nums2[_stack.top()]];
                    result[index] = nums2[i];
                }
                _stack.pop();
            }
            _stack.push(i);
        }
        return result;
    }
};