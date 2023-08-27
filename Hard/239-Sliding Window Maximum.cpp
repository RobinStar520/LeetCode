// ou are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


/*
Approach:
    This question is marked as "hard", but actually, it's easy and it's an entry-level question using the sliding window technique. We can use a hash map
and maintain a sliding window with size k, and then move the window, insert and remove the elements dynamically. Every time we move the window, we can get 
the maximum value in the window due to the property of the hash map in C++(auto sorting)
*/

#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> result {};
        // Use the function object "greater<>()" to ensure the key sorting is in ascending order.
        map<int, int, greater<int>> _map {};
        const int n = nums.size();
        // Fill the first k elements into the map.
        for (int i=0; i<k; ++i)
        {
            _map[nums[i]] += 1;
        }
        // The map will sort the key automatically.
        result.push_back(_map.begin()->first);
        for (int i=1; i<n-k+1; ++i)
        {
            _map[nums[i - 1]]--;
            if (_map[nums[i - 1]] <= 0)
            {
                _map.erase(nums[i - 1]);
            }
            _map[nums[i + k - 1]] ++;
            result.push_back(_map.begin()->first);
        }
        return result;
    }
};