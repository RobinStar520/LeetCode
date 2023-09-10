// You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.

// Return the number of integer points on the line that are covered with any part of a car.

 

// Example 1:

// Input: nums = [[3,6],[1,5],[4,7]]
// Output: 7
// Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.
// Example 2:

// Input: nums = [[1,3],[5,8]]
// Output: 7
// Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.


/*
Approach:
    Use a set-like data structure to find which number occurs in the coordinate.
*/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int numberOfPoints(vector<vector<int>>& nums) 
    {
        unordered_set<int> _set {};
        for (const auto& v: nums)
        {
            for (int i=v.front(); i<=v.back(); ++i)
            {
                _set.insert(i);
            }
        }
        return static_cast<int>(_set.size());
    }
};