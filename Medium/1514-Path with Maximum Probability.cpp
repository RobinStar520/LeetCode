// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

// Example 1:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
// Example 2:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000
// Example 3:



// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.
 

// Constraints:

// 2 <= n <= 10^4
// 0 <= start, end < n
// start != end
// 0 <= a, b < n
// a != b
// 0 <= succProb.length == edges.length <= 2*10^4
// 0 <= succProb[i] <= 1
// There is at most one edge between every two nodes.

/*
Approach:
    We can use Dijkstria's algorithm to slove this problem.
*/

#include <utility>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

// Use a disjoint-set to check whether two nodes are connected.
class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root.resize(n);
        for (int i=0; i<n; ++i)
        {
            root[i] = i;
        }
    }

    int find(int a)
    {
        return a == root[a] ? a : root[a] = find(root[a]);
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        root[b] = a;
    }

    int count()
    {
        int a = 0;
        for (int i=0; i<root.size(); ++i)
        {
            if (root[i] == i)
            {
                a += 1;
            }
        }
        return a;
    }

private:
    vector<int> root {};
};

class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        unordered_map<int, vector<pair<double, int>>> graph {};
        unordered_set<int> visited {};
        priority_queue<pair<double, int>> pq {};
        UnionFind uf(n);
        vector<double> dist(n, 0.00000);
        // Build graph
        for (int i=0; i<edges.size(); ++i)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            graph[from].push_back(make_pair(weight, to));
            graph[to].push_back(make_pair(weight, from));
            uf.join(from, to);
        }

        pq.push(make_pair(1.00000, start_node));
        while (!pq.empty())
        {
            auto [prob, u] = pq.top();
            pq.pop();
            if (visited.find(u) != visited.end())
            {
                continue;
            }
            visited.insert(u);
            for (const auto& neighbour: graph[u])
            {
                auto [weight, v] = neighbour;
                double newProb = weight * prob * 1.00000;
                if (newProb > dist[v])
                {
                    dist[v] = newProb;
                    pq.emplace(newProb, v);
                }
            }
        }
        return dist[end_node];
    }
};