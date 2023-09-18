// Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.

// In other words, answer whether or not if there exists a line that after reflecting all points over the given line, the original points' set is the same as the reflected ones.

// Note that there can be repeated points.

 

// Example 1:


// Input: points = [[1,1],[-1,1]]
// Output: true
// Explanation: We can choose the line x = 0.
// Example 2:


// Input: points = [[1,1],[-1,-1]]
// Output: false
// Explanation: We can't choose a line.
 

// Constraints:

// n == points.length
// 1 <= n <= 104
// -108 <= points[i][j] <= 108

/*
Approach:
    For this question, as long as we understand this principle: all the points will be in the range[Xmin, Ymax] and [Ymin, Ymax], the question will be
easy to solve.
*/

#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution 
{
public:
    bool isReflected(vector<vector<int>>& points) 
    {
        int max_x = points[0][0];
        int min_x = max_x;
        set<std::pair<int, int>> set;
        // Find the maximum and minimum value of the coordinate.
        for (const auto& p : points) 
        {
            max_x = std::max(max_x, p[0]);
            min_x = std::min(min_x, p[0]);
            set.insert({p[0], p[1]});
        }

        double mid = static_cast<double>(max_x + min_x) / 2;

        for (const auto& p : set) 
        {
            if (set.find({static_cast<int>(2 * mid) - p.first, p.second}) == set.end()) 
            {
                return false;
            }
        }
        return true;
    }
};