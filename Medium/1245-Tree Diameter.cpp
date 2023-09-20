// The diameter of a tree is the number of edges in the longest path in that tree.

// There is an undirected tree of n nodes labeled from 0 to n - 1. You are given a 2D array edges where edges.length == n - 1 and edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the tree.

// Return the diameter of the tree.

 

// Example 1:


// Input: edges = [[0,1],[0,2]]
// Output: 2
// Explanation: The longest path of the tree is the path 1 - 0 - 2.
// Example 2:


// Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
// Output: 4
// Explanation: The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
 

// Constraints:

// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi

/*
Approach:
    For this question, first we should know that the "tree" in the description is not strictly a tree. We should consider it as an undirected graph.
So don't try to find a root. After understanding this, you can use dfs to solve the problem.
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int treeDiameter(vector<vector<int>>& edges) 
    {
        if (edges.empty())
        {
            return 0;
        }
        unordered_map<int, vector<int>> _map {};
        unordered_set<int> _set {};
        for (const auto& v: edges)
        {
            _map[v[0]].push_back(v[1]);
            _map[v[1]].push_back(v[0]);
            _set.insert(v[0]);
            _set.insert(v[1]);
        }
        vector<int> visited(_set.size(), 0);
        int result = 0;
        dfs(0, _map, visited, result);
        return result;
    }

private:
    int dfs(int node, unordered_map<int, vector<int>>& _map, vector<int>& visited, int& result)
    {
        int left = 0, right = 0;
        visited[node] = 1;
        for (const auto& i: _map[node])
        {
            int distance = 0;
            if (!visited[i])
            {
                distance = 1 + dfs(i, _map, visited, result);
            }
            if (distance > left)
            {
                right = left;
                left = distance;
            }
            else if (distance > right)
            {
                right = distance;
            }
        }
        result = std::max(result, left + right);
        return left;
    }
};