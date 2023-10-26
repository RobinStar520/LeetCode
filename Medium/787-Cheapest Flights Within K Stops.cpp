// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
// Example 2:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
// Example 3:


// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
// Output: 500
// Explanation:
// The graph is shown above.
// The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

// Constraints:

// 1 <= n <= 100
// 0 <= flights.length <= (n * (n - 1) / 2)
// flights[i].length == 3
// 0 <= fromi, toi < n
// fromi != toi
// 1 <= pricei <= 104
// There will not be any multiple flights between two cities.
// 0 <= src, dst, k < n
// src != dst

/*
Approach:
    We can use a greedy algorithm with BFS to solve this problem. For each step, choose the minimum cost for each edge of a node. Repeat this step 
until the "k" becomes 0.
*/

#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <limits>

using namespace std;

class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        // pair -> [weight, to]
        
        unordered_map<int, vector<pair<int, int>>> graph {};
        unordered_set<int> visited {};
        int result = 0;
        int count = 0;
        const int INF = numeric_limits<int>::max();
        vector<int> dist(n, INF);
        for (const auto& v: flights)
        {
            int from = v[0];
            int to = v[1];
            int weight = v[2];
            graph[from].emplace_back(to, weight);
            
        }
        queue<pair<int, int>> q {};
        q.push({src, 0});

        // Start the BFS
        while (count <= k && !q.empty())
        {
            int size = q.size();
            while (size --)
            {
                auto [node, dis] = q.front();
                q.pop();
                for (const auto& [neighbour, weight]: graph[node])
                {
                    if (weight + dis < dist[neighbour])
                    {
                        dist[neighbour] = weight + dis;
                        q.push({neighbour, dist[neighbour]});
                    }
                }
            }
            count += 1;
        }
        // If dust[dst] is infinite, it means we can't reach the node, so we return -1 according to the description.
        return dist[dst] == INF ? -1 : dist[dst];
    }

    
};
