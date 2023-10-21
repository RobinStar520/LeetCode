// There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.

// A point of the cheese with index i (0-indexed) is:

// reward1[i] if the first mouse eats it.
// reward2[i] if the second mouse eats it.
// You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.

// Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.

 

// Example 1:

// Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
// Output: 15
// Explanation: In this example, the first mouse eats the 2nd (0-indexed) and the 3rd types of cheese, and the second mouse eats the 0th and the 1st types of cheese.
// The total points are 4 + 4 + 3 + 4 = 15.
// It can be proven that 15 is the maximum total points that the mice can achieve.
// Example 2:

// Input: reward1 = [1,1], reward2 = [1,1], k = 2
// Output: 2
// Explanation: In this example, the first mouse eats the 0th (0-indexed) and 1st types of cheese, and the second mouse does not eat any cheese.
// The total points are 1 + 1 = 2.
// It can be proven that 2 is the maximum total points that the mice can achieve.
 

// Constraints:

// 1 <= n == reward1.length == reward2.length <= 105
// 1 <= reward1[i], reward2[i] <= 1000
// 0 <= k <= n

/*
Approach:
    For this question, we can use a greedy algorithm. Assuming that the second mouse eats all the cheese, then we only need to find out which cheeses
the first mouse eats to minimize the loss.
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>

using namespace std;

class Solution 
{
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) 
    {
        int sum = accumulate(reward2.cbegin(), reward2.cend(), 0, plus<int>());
        const int n = reward1.size();
        priority_queue<int, vector<int>, greater<int>> pq {};
        for (int i=0; i<n; ++i)
        {
            pq.push(reward2[i] - reward1[i]);
        }
        while (k --)
        {
            sum -= pq.top();
            pq.pop();
        }

        return sum;
    }
};