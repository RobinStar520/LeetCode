// You are given an array nums consisting of positive integers.

// Starting with score = 0, apply the following algorithm:

// Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
// Add the value of the chosen integer to score.
// Mark the chosen element and its two adjacent elements if they exist.
// Repeat until all the array elements are marked.
// Return the score you get after applying the above algorithm.

 

// Example 1:

// Input: nums = [2,1,3,4,5,2]
// Output: 7
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
// - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
// - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
// Our score is 1 + 2 + 4 = 7.
// Example 2:

// Input: nums = [2,3,5,1,3,2]
// Output: 5
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
// - 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
// - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
// Our score is 1 + 2 + 2 = 5.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106

/*
Approach:
    We can use a heap to solve this problem.
*/

#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <unordered_set>

using namespace std;


class Solution 
{
public:
    long long findScore(vector<int>& nums) 
    {
        const int n = nums.size();
        long long result = 0ll;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq {};
        unordered_set<int> visited {};
        for (int i=0; i<n; ++i)
        {
            auto p = make_pair(nums[i], i);
            pq.push(p);
        }

        while (!pq.empty())
        {
            while (!pq.empty() && visited.find(pq.top().second) != visited.end())
            {
                pq.pop();
            }
            if (pq.empty())
            {
                break;
            }
            auto [value, index] = pq.top();
            pq.pop();
            result += value * 1ll;
            if (index == 0)
            {
                visited.insert(0);
                visited.insert(1);
            }
            else if (index == n - 1)
            {
                visited.insert(n - 1);
                visited.insert(n - 2);
            }
            else
            {
                visited.insert(index + 1);
                visited.insert(index - 1);
                visited.insert(index);
            }

        }

        return result;
    }
};