// There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

// Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

// Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

 

// Example 1:


// Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
// Output: 2
// Example 2:

// Input: wall = [[1],[1],[1]]
// Output: 3
 

// Constraints:

// n == wall.length
// 1 <= n <= 104
// 1 <= wall[i].length <= 104
// 1 <= sum(wall[i].length) <= 2 * 104
// sum(wall[i]) is the same for each row i.
// 1 <= wall[i][j] <= 231 - 1

/*
Approach:
    First, we should calculate the bricks' edge at each level. We can use a prefix sum technique to complete this task.
*/

#include <vector>
#include <map>
#include <limits>

using namespace std;


class Solution 
{
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        // We don't consider the rightmost vertical line, so to simplify the whole procedure, we use an ordered hashmap to remove the last element.
        // Otherwise, we have to traverse the whole hashmap to eliminate the value we don't need.
        map<int, int> _map {};
        const int n = wall.size();
        for (const auto& v: wall)
        {
            // Prefix-sum.
            vector<int> sum(v.size(), 0);
            sum[0] = v[0];
            _map[sum[0]] ++;
            for (int i=1; i<v.size(); ++i)
            {
                sum[i] = sum[i - 1] + v[i];
                _map[sum[i]] ++;
            }
        }
        int result = numeric_limits<int>::max();
        // If we only have one type of brick, which means we have to cross all the bricks anyway.
        if (1 == _map.size())
        {
            return n;
        }
        _map.erase(std::prev(_map.end()));
        for (const auto& [key, value]: _map)
        {
            result = std::min(result, n - value);
        }
        return result;
    }

private:
    vector<int> getPrefixSum(const vector<int>& vct)
    {
        vector<int> result(vct.size(), 0);
        result[0] = vct[0];
        for (int i=1; i<vct.size(); ++i)
        {
            result[i] = result[i - 1] + vct[i];
        }
        return result;
    }
};