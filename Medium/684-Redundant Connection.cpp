// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

/*
Approach:
    We can use a union-find data structure to find whether two nodes belong to the same set.
*/

#include <vector>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n);
        init();
    }

    void init()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }

    int find(int a)
    {
        return a == root[a] ? a : root[a] = find(root[a]);
    }

    bool isSame(int a, int b)
    {
        a = find(a);
        b = find(b);
        return a == b;
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
 
private:
    vector<int> root;
};

class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        UnionFind* obj = new UnionFind(1005);
        for (const auto& v: edges)
        {
            if (obj->isSame(v[0], v[1]))
            {
                return v;
            }
            else
            {
                obj->join(v[0], v[1]);
            }
        }
        delete obj;
        return {};
    }
};