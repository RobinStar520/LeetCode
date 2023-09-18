// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.

 

// Example 1:


// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
// Example 2:


// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.
 

// Constraints:

// 1 <= n <= 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.

/*
Approach:
    We can use the DFS to calculate how many nodes we can't achieve.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long result = 0ll;
        unordered_map<int, vector<int>> _map {};
        for (const auto& v: edges)
        {
            _map[v[0]].push_back(v[1]);
            _map[v[1]].push_back(v[0]);
        }
        
        vector<int> visited(n, false);

        for (int i = 0; i < n; ++i) 
        {
            if (!visited[i]) 
            {
                int unreachableCount = dfs(i, _map, visited);
                result += static_cast<long long>(unreachableCount * 1ll * (n - unreachableCount));
            }
        }

        return result / 2; // Divide by 2 to avoid double counting
    }

private:
    int dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited) 
    {
        visited[node] = true;
        int unreachableCount = 1;

        for (const auto& neighbor : graph[node]) 
        {
            if (!visited[neighbor]) 
            {
                unreachableCount += dfs(neighbor, graph, visited);
            }
        }

        return unreachableCount;
    }
};