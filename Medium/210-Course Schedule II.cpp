// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

/*
Approach:
    Two steps for this question: First, check whether the graph is a DAG. More formally, inspect whether there are cycles in the graph; Second, if the 
graph is a valid DAG, outputting its topological sequence.
*/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> graph {};
        unordered_map<int, int> inDegrees {};
        vector<int> result {};
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
            result.push_back(node);
            for (auto& i: graph[node])
            {
                inDegrees[i] -= 1;
                if (inDegrees[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        return count == numCourses ? result : vector<int>();
    }
};