// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

// Example 1:

// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:

// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 

// Constraints:

// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000

/*
Approach:
    We can use a heap and a greedy algorithm to solve this question. Fist, statistic the frequency of each barcode; Second, use a heap to ensure there
are not a pair of barcodes are neighbors.
*/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Comp
{
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const
    {
        return p1.second < p2.second;
    }
};

class Solution 
{
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) 
    {
        // if (barcodes.size() == 1)
        // {
        //     return barcodes;
        // }
        unordered_map<int, int> _map {};
        vector<int> result {};
        for (const auto& i: barcodes)
        {
            _map[i] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq(_map.begin(), _map.end());
        while (pq.size() > 1)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            result.push_back(p1.first);
            result.push_back(p2.first);
            if (p1.second > 1)
            {
                pq.push({p1.first, --p1.second});
            }
            if (p2.second > 1)
            {
                pq.push({p2.first, --p2.second});
            }
        }
        // Don't forget the last number in the heap.
        while (!pq.empty())
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};