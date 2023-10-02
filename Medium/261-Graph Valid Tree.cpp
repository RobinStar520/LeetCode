// You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

// Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

// Example 1:


// Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
// Output: true
// Example 2:


// Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
// Output: false
 

// Constraints:

// 1 <= n <= 2000
// 0 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no self-loops or repeated edges.


/*
Approach:
    This is a graph theory question. You need to judge whether a graph is a valid tree. Here are some theorem below:
    1. A connected graph on n nodes is a tree if and only if it has n−1 edges;
    2. There should be only one connected component. More formally, a tree can only have one root.
*/

#include <vector>
#include <unordered_map>

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
    
    int setCount()
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

private:
    vector<int> root;
};

class Solution 
{
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if (edges.size() != n - 1)
        {
            return false;
        }
        UnionFind* obj = new UnionFind(n);
        for (const auto& v: edges)
        {
            obj->join(v[0], v[1]);
        }

        bool result = obj->setCount() == 1;
        // Don't forget to delete the allocated object on the heap.
        delete obj;
        return result;
    }
};