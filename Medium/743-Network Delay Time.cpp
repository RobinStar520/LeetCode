// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

/*
Approach:
    This is a template question of Dijkstra's algorithm. Use dijkstra's algorithm step by step.
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <limits>
#include <functional>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        const int INF = numeric_limits<int>::max();
        unordered_map<int, vector<pair<int, int>>> graph {};
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq {};
        pq.push(make_pair(0, k));
        dist[k] = 0;
        for (const auto& v: times)
        {
            graph[v[0]].push_back(make_pair(v[2], v[1]));
        }
        while (!pq.empty())
        {
            auto [arriveTime, node] = pq.top();
            pq.pop();
            if (arriveTime > dist[node])
            {
                continue;
            }
            for (const auto& [time, neighbour]: graph[node])
            {
                if (dist[neighbour] > arriveTime + time)
                {
                    dist[neighbour] = arriveTime + time;
                    pq.push(make_pair(dist[neighbour], neighbour));
                }
            }

        }
        int result = numeric_limits<int>::min();
        // Note the start index here. We didn't use the index 0, so the loop should start at index 1.
        for (int i=1; i<=n; ++i)
        {
            result = std::max(result, dist[i]);
        }

        return result == INF ? -1 : result;
    }
};