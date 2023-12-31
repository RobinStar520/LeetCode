// There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

// You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

// It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

// Return the original array nums. If there are multiple solutions, return any of them.

 

// Example 1:

// Input: adjacentPairs = [[2,1],[3,4],[3,2]]
// Output: [1,2,3,4]
// Explanation: This array has all its adjacent pairs in adjacentPairs.
// Notice that adjacentPairs[i] may not be in left-to-right order.
// Example 2:

// Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
// Output: [-2,4,1,-3]
// Explanation: There can be negative numbers.
// Another solution is [-3,1,4,-2], which would also be accepted.
// Example 3:

// Input: adjacentPairs = [[100000,-100000]]
// Output: [100000,-100000]
 

// Constraints:

// nums.length == n
// adjacentPairs.length == n - 1
// adjacentPairs[i].length == 2
// 2 <= n <= 105
// -105 <= nums[i], ui, vi <= 105
// There exists some nums that has adjacentPairs as its pairs.

/*
Approach:
    Find the first element of nums - it will only appear once in adjacentPairs. The adjacent pairs are like edges of a graph. Perform a depth-first 
search from the first element.
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int, int> inDegrees {};
        unordered_map<int, vector<int>> graph {};
        unordered_set<int> visited {};
        vector<int> result (adjacentPairs.size()+1, 0);
        for (const auto& v: adjacentPairs)
        {
            inDegrees[v[0]] += 1;
            inDegrees[v[1]] += 1;
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        int node {};
        for (const auto& [key, value]: inDegrees)
        {
            if (value == 1)
            {
                node = key;
                break;
            }
        }
        int index = 0;
        dfs(node, graph, visited, index, result);
        
        return result;
    }

private:
    void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int& index, vector<int>& result)
    {
        visited.insert(node);
        result[index] = node;
        index += 1;
        for (const auto& neighbour: graph[node])
        {
            if (visited.find(neighbour) == visited.end())
            {
                dfs(neighbour, graph, visited, index, result);
            }
        }
        return;
    }
};