// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

// Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0
// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]
// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
 

// Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.

/*
Approach:
    This is a graph problem. First, we should form a proper graph. Apparently, this is a undirected graph with weight. 
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, int> transformation {};
        int idx = 0;

        for (const vector<string>& eq : equations)
        {
            if (transformation.find(eq[0]) == transformation.end()) 
            {
                transformation[eq[0]] = idx++;
            }
            if (transformation.find(eq[1]) == transformation.end()) 
            {
                transformation[eq[1]] = idx++;
            }
        }

        vector<vector<pair<int, double>> > graph(idx);

        for (int i = 0; i < equations.size(); i++) 
        {
            int u = transformation[equations[i][0]];
            int v = transformation[equations[i][1]];
            double val = values[i];
            graph[u].emplace_back(v, val);
            graph[v].emplace_back(u, 1.0 / val);
        }

        
        vector<double> result {};
        for (const vector<string>& query : queries) 
        {
            if (transformation.find(query[0]) == transformation.end() || transformation.find(query[1]) == transformation.end()) 
            {
                result.push_back(-1.0);
            } 
            else 
            {
                int start = transformation[query[0]];
                int end = transformation[query[1]];
                double res = evaluateExpression(graph, start, end);
                result.push_back(res);
            }
        }

        return result;
    }

    double evaluateExpression(const vector<vector<pair<int, double>> >& graph, int start, int end) 
    {
        if (start == end)
        {
            return 1.00000;
        }
        queue<pair<int, double>> q {};
        q.push({start, 1.00000});
        unordered_set<int> visited {};

        while (!q.empty()) 
        {
            int curr = q.front().first;
            double value = q.front().second;
            q.pop();
            visited.insert(curr);

            for (const pair<int, double>& neighbor : graph[curr]) 
            {
                int next = neighbor.first;
                double weight = neighbor.second;
                if (next == end) 
                {
                    return value * weight;
                }
                if (visited.find(next) == visited.end()) 
                {
                    q.push({next, value * weight});
                }
            }
        }

        return -1.00000;
    }
};


