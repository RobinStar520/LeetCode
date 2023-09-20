// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
 

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

// Follow up:

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?

/*
Approach:
    This question will be easy without constraints: 1. You can't modify the original array; 2. You must use only constant extra space. For condition 
one, as long as we guarantee that after running the procedure, the array won't be modified, that's it. For condition two, we can allocate some extra 
space on the array, and use the space as a hashmap to count the frequency of the numbers.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        // The total size of the vector should be at least twice the original size.
        nums.resize(200000, 0);
        for (int i=0; i<n; ++i)
        {
            nums[n + nums[i]]++;
        }
        int result = 0;
        // Beware of the start index. It should be n instead of 0 since we start at index n to statistic the frequency of each number.
        for (int i=n; i<nums.size(); ++i)
        {
            if (nums[i] >= 2)
            {
                result = i - n;
            }
        }
        // Remove the extra space.
        nums.erase(nums.begin()+n, nums.end());
        return result;
    }
};