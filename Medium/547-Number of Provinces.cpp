// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

/*
Approach:
    This is a graph problem. Use DFS to solve it.
*/

/*
02/10/23 update:
    I rewrite the code using an union-find data structure.
*/

// #include <vector>
// #include <unordered_map>

// using namespace std;

// class Solution 
// {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) 
//     {
//         unordered_map<int, vector<int>> _map {};
//         int result = 0;
//         const int n = isConnected.size();
//         vector<int> visited(n, 0);
//         for (int i=0; i<n; ++i)
//         {
//             for (int j=0; j<n; ++j)
//             {
//                 if (isConnected[i][j] == 1)
//                 {
//                     _map[i].push_back(j);
//                     _map[j].push_back(i);
//                 }
//             }
//         }
//         for (int i=0; i<n; ++i)
//         {
//             if (!visited[i])
//             {
//                 result += 1;
//                 visited[i] = 1;
//                 dfs(i, _map, visited);
//             }
//         }
//         return result;
//     }

//     void dfs(int num, unordered_map<int, vector<int>>& _map, vector<int>& visited)
//     {
//         for (const auto& i: _map[num])
//         {
//             if (!visited[i])
//             {
//                 visited[i] = 1;
//                 dfs(i, _map, visited);
//             }
//         }
//         return;
//     }
// };

#include <vector>
#include <unordered_set>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n, 0);
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
        return root[a] == a ? a : root[a] = find(root[a]);
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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        UnionFind* obj = new UnionFind(isConnected.size());
        for (int i=0; i<isConnected.size(); ++i)
        {
            for (int j=0; j<isConnected[i].size(); ++j)
            {
                if (isConnected[i][j] == 1)
                {
                    obj->join(j, i);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            // Only increment result when a city is its own root, indicating a new province.
            if (obj->find(i) == i)
            {
                result += 1;
            }
        }
        delete obj;
        return result;
    }
};