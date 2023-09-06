// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

/*
Approach:
    There are two methods to solve the problem: The first step is to count the frequency of each letter in both algorithms. In the second step, you can
use a priority queue(heap) to calculate the top K frequent elements, or put the pairs into a vector and then sort it. I selected the first one since it has
a better time complexity.
*/


#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using P = pair<int, int>;
class Comp
{
public:
    bool operator()(const P& p1, const P& p2) const
    {
        return p1.second < p2.second;
    }
};

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> _map {};
        vector<int> result {};
        priority_queue<P, vector<P>, Comp> pq {};
        for (const auto& i: nums)
        {
            _map[i] ++;
        }
        for (auto& p: _map)
        {
            pq.push(p);
        }

        while (k --)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;

    }
};