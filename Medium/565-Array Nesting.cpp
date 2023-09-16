// You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

// You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

// The first element in s[k] starts with the selection of the element nums[k] of index = k.
// The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
// We stop adding right before a duplicate element occurs in s[k].
// Return the longest length of a set s[k].

 

// Example 1:

// Input: nums = [5,4,0,3,1,6,2]
// Output: 4
// Explanation: 
// nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
// One of the longest sets s[k]:
// s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
// Example 2:

// Input: nums = [0,1,2]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] < nums.length
// All the values of nums are unique.

/*
Approach:
    If we use a brute force algorithm: Traverse the whole vector and judge every element individually, it can't pass all the test cases since the time 
complexity is O(n^2). Let's think about whether we need to traverse the whole element. For example, this test case: [0,1,2,3,4,5]. When we inspect the 
first element 0, we will find the final result: the longest path: 0->1->2->3->4->5. But we will check them twice when we visit the second element. So 
it's unnecessary to inspect an element for many times. To avoid the duplicate visit, we can use a "visited" array,like DFS in graph problem to mark 
whether a node we have visited, and we only operate on the node not visit.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    int arrayNesting(vector<int>& nums) 
    {
        int result = 0;
        const int n = nums.size();
        // Mark whether an element has been visited.
        vector<int> visited(n, 0);
        for (int i=0; i<n; ++i)
        {
            if (!visited[i])
            {
                int sum = 0;
                int start = nums[i];
                do
                {
                    start = nums[start];
                    sum += 1;
                    visited[i] = 1;
                }   
                while (start != nums[i]);
                result = std::max(result, sum);
            }
        }
        return result;
    }
};