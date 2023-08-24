// Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

 

// Example 1:

// Input: nums = [-2,0,1,3], target = 2
// Output: 2
// Explanation: Because there are two triplets which sums are less than 2:
// [-2,0,1]
// [-2,0,3]
// Example 2:

// Input: nums = [], target = 0
// Output: 0
// Example 3:

// Input: nums = [0], target = 0
// Output: 0
 

// Constraints:

// n == nums.length
// 0 <= n <= 3500
// -100 <= nums[i] <= 100
// -100 <= target <= 100

/*
Approach:
    This is a series of questions. These questions have a feature: either using binary search or using a hash table(hash map or hash set). For this question,
we can use the brute force algorithm, which has O(n ^ 3) complexity, and it won't pass all the test cases due to the time limit exceeded. A binary search
algorithm can reduce the time complexity to O(n ^ 2 * logn), so for this qeustion I used the binary search. Note: The binary search isn't the fastest algorithm.
(Two pointers algorithm is the most efficient and fastest algorithm).
    Initially,  we need two for loops, and then think about the inequality "nums[i] + nums[j] + nums[k] < target". This can be rewritten as "nums[i] + nums[j] < target - nums[k]",
so we use the for loop to calculate the sum of two elements, and then using binary search find the value "target - nums[k]". After finding the position of "target - nums[k]", it's 
easy for us to calculate the distance between two values.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        if (nums.empty())
        {
            return 0;
        }
        // Sort the whole vector since this step is necessary for the bianry search.
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int result = 0;
        for (int i=0; i<n; ++i)
        {
            for (int j=i+1; j<n; ++j)
            {
                // Find the iterator that point to the first element equal or larger than "target - nums[i] - nums[j]".
                auto iter = lower_bound(nums.cbegin()+j, nums.cend(), target - nums[i] - nums[j]);
                // Note this step.
                if (iter != nums.cbegin() + j)
                {
                    // "lower_bound" helps us to find the first element equal or larger than a specified value, *iter probably equals the value,
                    // so we should move the iterator one step previously.
                    iter --;
                    // Calculate how many items from "nums.cbegin() + j" to the iterator "iter".
                    result += (iter - nums.cbegin() - j);
                }
            }
        }
        return result;
    }
};