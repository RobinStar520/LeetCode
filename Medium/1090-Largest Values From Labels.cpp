// There is a set of n items. You are given two integer arrays values and labels where the value and the label of the ith element are values[i] and labels[i] respectively. You are also given two integers numWanted and useLimit.

// Choose a subset s of the n elements such that:

// The size of the subset s is less than or equal to numWanted.
// There are at most useLimit items with the same label in s.
// The score of a subset is the sum of the values in the subset.

// Return the maximum score of a subset s.

 

// Example 1:

// Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
// Output: 9
// Explanation: The subset chosen is the first, third, and fifth items.
// Example 2:

// Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
// Output: 12
// Explanation: The subset chosen is the first, second, and third items.
// Example 3:

// Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
// Output: 16
// Explanation: The subset chosen is the first and fourth items.
 

// Constraints:

// n == values.length == labels.length
// 1 <= n <= 2 * 104
// 0 <= values[i], labels[i] <= 2 * 104
// 1 <= numWanted, useLimit <= n

/*
Approach:
   We can use a priority queue or an ordered set to find the least current need.
*/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

using _P = pair<int, priority_queue<int, vector<int>>>;

struct Comp
{
public:
    bool operator()(const _P& p1, const _P& p2) const
    {
        if (p1.second.empty() && p2.second.empty())
        {
            return false;
        }
        if (p1.second.empty())
        {
            return true;
        }
        if (p2.second.empty())
        {
            return false;
        }
        return p1.second.top() < p2.second.top();
    }
};


class Solution 
{
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) 
    {
        unordered_map<int, priority_queue<int, vector<int>>> _map {};
        // label -> count
        unordered_map<int, int> _count {};
        const int n = values.size();
        for (int i=0; i<n; ++i)
        {
            _map[labels[i]].push(values[i]);
        }
        priority_queue<_P, vector<_P>, Comp> pq(_map.begin(), _map.end());
       
        int result = 0;
        while (numWanted > 0 && !pq.empty())
        {
            auto p = pq.top();
            
            pq.pop();

            if (!p.second.empty())
            {
                int label = p.first;
                int value = p.second.top();
                if (_count[label] < useLimit)
                {
                    result += value;
                    p.second.pop();
                    pq.push(p); 
                    ++_count[label];
                    --numWanted;
                }
            }
        }
        return result;
    }
};