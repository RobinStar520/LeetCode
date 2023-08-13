// You are given a 0-indexed integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the maximum digit in both numbers are equal.

// Return the maximum sum or -1 if no such pair exists.


// Example 1:

// Input: nums = [51,71,17,24,42]
// Output: 88
// Explanation: 
// For i = 1 and j = 2, nums[i] and nums[j] have equal maximum digits with a pair sum of 71 + 17 = 88. 
// For i = 3 and j = 4, nums[i] and nums[j] have equal maximum digits with a pair sum of 24 + 42 = 66.
// It can be shown that there are no other pairs with equal maximum digits, so the answer is 88.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: -1
// Explanation: No pair exists in nums with equal maximum digits.
 

// Constraints:

// 2 <= nums.length <= 100
// 1 <= nums[i] <= 104


/*
Approach:
    This question took me some time to understand. First we should notice that we need to find a pair of numbers, which means if we use some for-loops,
"i", "j" can't have the same value simultaneously; Second, according to the question, our goal is to find a pair of numbers such that the maximum digit in both 
numbers are equal rather than the final result.
    1. Use a map to store the number that has the same maximum digit;
    2. The type of the map's key should be "char" since we can convert the number to a string and then find the maximum digit easily.
    3. Set a priority queue as the map's value so that we can find the first two largest values;
    4. Traverse the whole map to find the result.
*/


#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxSum(vector<int>& nums) 
    {
        unordered_map<char, priority_queue<int, vector<int>>> _map {};
        for (const auto& i: nums)
        {
            string str = to_string(i);
            char maxval = *max_element(str.cbegin(), str.cend());
            _map[maxval].push(i);
        }
        int result = -1;
        for (auto& [key, value]: _map)
        {
            // cout << key << "->";
            // while (!value.empty())
            // {
            //     cout << value.top() << " ";
            //     value.pop();
            // }
            // cout << endl;
            if (value.size() >= 2)
            {
                int a = value.top();
                value.pop();
                int b = value.top();
                result = std::max(a + b, result);
            }
        }
        return result;
    }
};