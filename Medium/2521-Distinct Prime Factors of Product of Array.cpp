// Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

// Note that:

// A number greater than 1 is called prime if it is divisible by only 1 and itself.
// An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
 

// Example 1:

// Input: nums = [2,4,3,7,10,6]
// Output: 4
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
// There are 4 distinct prime factors so we return 4.
// Example 2:

// Input: nums = [2,4,8,16]
// Output: 1
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
// There is 1 distinct prime factor so we return 1.
 

// Constraints:

// 1 <= nums.length <= 104
// 2 <= nums[i] <= 1000

/*
Approach:
    We can use a brute force algorithm to calculate all the prime factors for an integer.
*/
#include <unordered_set>
#include <vector>

using namespace std;

class Solution 
{
public:
    int distinctPrimeFactors(vector<int>& nums) 
    {
        unordered_set<int> _set {};
        for (auto& num: nums)
        {
            getFactors(num, _set);
        }

        return static_cast<int>(_set.size());
    }

private:
    void getFactors(int num, unordered_set<int>& _set)
    {
        while (num % 2 == 0)
        {
            _set.insert(2);
            num /= 2;
        }
        for (int i=3; i*i<=num; i+=2)
        {
            while (num % i == 0)
            {
                _set.insert(i);
                num /= i;
            }
        }
        if (num > 2)
        {
            _set.insert(num);
        }
        return;
    }
};