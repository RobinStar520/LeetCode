// You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

// difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
// Every worker can be assigned at most one job, but one job can be completed multiple times.

// For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning the workers to the jobs.

 

// Example 1:

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
// Example 2:

// Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
// Output: 0
 

// Constraints:

// n == difficulty.length
// n == profit.length
// m == worker.length
// 1 <= n, m <= 104
// 1 <= difficulty[i], profit[i], worker[i] <= 105

/*
Approach:
    For this question, we need to inspect two aspects: First, we should find how much work a specified worker can do;  Second, find the work that has
the maximum profit. We can solve this problem using a greedy approach.
*/

#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

class Solution 
{
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int result = 0;
        vector<pair<int, int>> temp {};
        const int n = difficulty.size();
        for (int i=0; i<n; ++i)
        {
            temp.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(temp.begin(), temp.end(), [&](pair<int, int>& p1, pair<int, int>& p2) -> bool {
            return p1.first <= p2.first;
        });
        for (int i=0; i<n; ++i)
        {
            difficulty[i] = temp[i].first;
            profit[i] = temp[i].second;
        }
        for (const auto& i: worker)
        {
            // Use binary search to find the range of work that a worker can do.
            auto iter = upper_bound(difficulty.cbegin(), difficulty.cend(), i);
            if (iter == difficulty.cbegin())
            {
                continue;
            }
            // Find the maximum profit work in the range we found before.
            int maxval = 0;
            for (int i=0; i<iter-difficulty.cbegin(); ++i)
            {
                maxval = std::max(maxval, profit[i]);
            }
            result += maxval;
        }
        return result;
    }
};