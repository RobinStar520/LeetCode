// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

// Return the number of connected components in the graph.

 

// Example 1:


// Input: n = 5, edges = [[0,1],[1,2],[3,4]]
// Output: 2
// Example 2:


// Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
// Output: 1
 

// Constraints:

// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= ai <= bi < n
// ai != bi
// There are no repeated edges.

/*
Approach:
    DFS. Note: It's hard to use a BFS solution to resolve the problem due to the BFS's feature.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> _map {};
        vector<int> visited(n, 0);
        for (const auto& v: edges)
        {
            _map[v[0]].push_back(v[1]);
            _map[v[1]].push_back(v[0]);
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(i, _map, visited);
                result += 1;
            }
        }
        return result;
    }

private:
    void dfs(int start, unordered_map<int, vector<int>>& _map, vector<int>& visited)
    {
        visited[start] = 1;
        for (const auto& node: _map[start])
        {
            if (!visited[node])
            {
                dfs(node, _map, visited);
            }
        }
    }
};