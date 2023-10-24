// You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

// Return true if you can make this square and false otherwise.

 

// Example 1:


// Input: matchsticks = [1,1,2,2,2]
// Output: true
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
// Example 2:

// Input: matchsticks = [3,3,3,3,4]
// Output: false
// Explanation: You cannot find a way to form a square with all the matchsticks.
 

// Constraints:

// 1 <= matchsticks.length <= 15
// 1 <= matchsticks[i] <= 108

/*
Approach:
    This question is similar to the question "Partition to K Equal Sum Subsets". In this question, we need to divide the whole vector into four subsets
with the same sum. We can use backtracking to solve it.
*/

#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution 
{
public:
    bool makesquare(vector<int>& matchsticks) 
    {
        vector<int> visited(matchsticks.size(), 0);
        int sum = accumulate(matchsticks.cbegin(), matchsticks.cend(), 0, plus<int>());
        if (sum % 4 != 0)
        {
            return false;
        }
        int target = sum / 4;
        return backtracking(0, matchsticks, visited, 0, target, 4);
    }

private:
    bool backtracking(int index, vector<int>& nums, vector<int>& visited, int subsetSum, int target, int k) 
    {
        if (k == 1) 
        {
            return true;
        }

        if (subsetSum == target) 
        {
            return backtracking(0, nums, visited, 0, target, k - 1);
        }

        for (int i = index; i < nums.size(); ++i) 
        {
            if (!visited[i] && subsetSum + nums[i] <= target) 
            {
                visited[i] = 1;
                if (backtracking(i + 1, nums, visited, subsetSum + nums[i], target, k)) 
                {
                    return true;
                }
                visited[i] = 0;
            }
        }

        return false;
    }
};