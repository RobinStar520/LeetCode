// There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

// Implement the Graph class:

// Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
// addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
// int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
 

// Example 1:


// Input
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
// [[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
// Output
// [null, 6, -1, null, 6]

// Explanation
// Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
// g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
// g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
// g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
// g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
 

// Constraints:

// 1 <= n <= 100
// 0 <= edges.length <= n * (n - 1)
// edges[i].length == edge.length == 3
// 0 <= fromi, toi, from, to, node1, node2 <= n - 1
// 1 <= edgeCosti, edgeCost <= 106
// There are no repeated edges and no self-loops in the graph at any point.
// At most 100 calls will be made for addEdge.
// At most 100 calls will be made for shortestPath.

/*
Approach:
    This is an easy problem using Dijkstra's algorithm. The constraints are mid-level so that we can optimise the algorithm by a priority queue.
*/

#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>
#include <unordered_map>
#include <utility>

using namespace std;

class Graph 
{
public:
    Graph(int n, vector<vector<int>>& edges) : n(n), INF(numeric_limits<int>::max())
    {
        for (const auto& v: edges)
        {
            graph[v[0]].push_back(make_pair(v[2], v[1]));
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        graph[edge[0]].push_back(make_pair(edge[2], edge[1]));
        return;
    }
    
    int shortestPath(int node1, int node2) 
    {
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq {};
        pq.push(make_pair(0, node1));
        dist[node1] = 0;
        while (!pq.empty())
        {
            auto [value, node] = pq.top();
            pq.pop();
            if (value > dist[node])
            {
                continue;
            }
            for (const auto& [val, neighbour]: graph[node])
            {
                if (dist[neighbour] > val + value)
                {
                    dist[neighbour] = val + value;
                    pq.push(make_pair(dist[neighbour], neighbour));
                }
            }
        }
        return dist[node2] == INF ? -1 : dist[node2];
    }


private:
    unordered_map<int, vector<pair<int, int>>> graph {};

    int n;

    int INF;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */