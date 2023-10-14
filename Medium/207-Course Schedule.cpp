// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

/*
Approach:
    This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it 
will be impossible to take all courses. There are many different methods to implement the topological sort, here I use a BFS like approach since it's
easy to implement.

*/
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // This unordered_map store each node's indegree.
        unordered_map<int, int> inDegrees {};
        unordered_map<int, vector<int>> graph {};
        int count = 0;
        for (const auto& v: prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            inDegrees[v[0]] += 1;
        }
        queue<int> q {};
        for (int i=0; i<numCourses; ++i)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count += 1;
            for (auto& i: graph[node])
            {
                inDegrees[i] -= 1;
                if (inDegrees[i] == 0)
                {
                    q.push(i);
                }
            }
            
        }

        return count == numCourses;
    }
};