// There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

// Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

// The cost is the sum of the connections' costs used.

 

// Example 1:


// Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
// Output: 6
// Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
// Example 2:


// Input: n = 4, connections = [[1,2,3],[3,4,4]]
// Output: -1
// Explanation: There is no way to connect all cities even if all edges are used.
 

// Constraints:

// 1 <= n <= 104
// 1 <= connections.length <= 104
// connections[i].length == 3
// 1 <= xi, yi <= n
// xi != yi
// 0 <= costi <= 105

/*
Approach:
    We need to find the minimum spanning tree for this question. We can use the Prim's algorithm.
*/

#include <vector>
#include <algorithm>

using namespace std;

// We use an union-find (disjoint set) to find whether there is a cycle in the graph.
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
    
    // Compress the path to reduce the time complexity.
    int find(int a)
    {
        return a == root[a] ? a : root[a] = find(root[a]);
    }

    bool isSame(int a, int b)
    {
        return find(a) == find(b);
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

    // Count how many connected components are in the graph. For the question, there is only one connected component should exist.
    int count()
    {
        int result = 0;
        for (int i=0; i<root.size(); ++i)
        {
            if (root[i] == i)
            {
                result += 1;
            }
        }
        return result;
    }

    // Initilize the union-find data structure.
    void reassign()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }

private:
    vector<int> root {};
};

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight): from(from), to(to), weight(weight) {};
};

struct Comp
{
public:
    bool operator()(struct Edge& a, struct Edge& b) const
    {
        return a.weight < b.weight;
    }
};


class Solution 
{
public:
    int minimumCost(int n, vector<vector<int>>& connections) 
    {
        UnionFind uf(n);
        vector<Edge> edges {};
        int rest = 0;
        int result = 0;
        for (const auto& v: connections)
        {
            uf.join(v[0]-1, v[1]-1);
            Edge edge(v[0]-1, v[1]-1, v[2]);
            edges.push_back(edge);
        }
        // Only one connected component is acceptable.
        if (uf.count() != 1)
        {
            return -1;
        }

        // Reset the union-find structure.
        uf.reassign();
        sort(edges.begin(), edges.end(), Comp());

        for (int i=0; i<edges.size() && rest < n-1; ++i)
        {
            int from = edges[i].from;
            int to = edges[i].to;
            int weight = edges[i].weight;
            // Check whether 
            if (!uf.isSame(from, to))
            {
                uf.join(from, to);
                result += weight;
                rest += 1;
            }
        }

        return result;
    }
};