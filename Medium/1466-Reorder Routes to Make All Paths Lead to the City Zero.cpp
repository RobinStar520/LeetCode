// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

 

// Example 1:


// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 2:


// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 3:

// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
 

// Constraints:

// 2 <= n <= 5 * 104
// connections.length == n - 1
// connections[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi

/*
Approach:
    This is a typical graph problem using DFS. Let's start at city 0, and we think each city has two paths to its neighbours. DFS can help us
find all the existing paths, so the rest of the paths are what we need to build.
*/

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution 
{
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        int result = 0;
        set<pair<int, int>> _set {};
        vector<int> visited(n, 0);
        // city -> neighbours
        unordered_map<int, vector<int>> _map {};
        for (const auto& v: connections)
        {
            _map[v[0]].push_back(v[1]);
            _map[v[1]].push_back(v[0]);
            _set.insert(make_pair(v[0], v[1]));
        }
        visited[0] = 1;
        dfs(0, _map, _set, visited, result);
        return result;
    }

    void dfs(int city, unordered_map<int, vector<int>>& _map, set<pair<int, int>>& _set, vector<int>& visited, int& result)
    {
        for (const auto& i: _map[city])
        {
            if (!visited[i])
            {
                if (_set.find({i, city}) == _set.end())
                {
                    result += 1;
                }
                visited[i] = true;
                dfs(i, _map, _set, visited, result);
            }
        }
    }
};