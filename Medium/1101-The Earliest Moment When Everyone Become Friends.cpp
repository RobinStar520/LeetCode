// There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

// Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

// Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

 

// Example 1:

// Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
// Output: 20190301
// Explanation: 
// The first event occurs at timestamp = 20190101, and after 0 and 1 become friends, we have the following friendship groups [0,1], [2], [3], [4], [5].
// The second event occurs at timestamp = 20190104, and after 3 and 4 become friends, we have the following friendship groups [0,1], [2], [3,4], [5].
// The third event occurs at timestamp = 20190107, and after 2 and 3 become friends, we have the following friendship groups [0,1], [2,3,4], [5].
// The fourth event occurs at timestamp = 20190211, and after 1 and 5 become friends, we have the following friendship groups [0,1,5], [2,3,4].
// The fifth event occurs at timestamp = 20190224, and as 2 and 4 are already friends, nothing happens.
// The sixth event occurs at timestamp = 20190301, and after 0 and 3 become friends, we all become friends.
// Example 2:

// Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
// Output: 3
// Explanation: At timestamp = 3, all the persons (i.e., 0, 1, 2, and 3) become friends.
 

// Constraints:

// 2 <= n <= 100
// 1 <= logs.length <= 104
// logs[i].length == 3
// 0 <= timestampi <= 109
// 0 <= xi, yi <= n - 1
// xi != yi
// All the values timestampi are unique.
// All the pairs (xi, yi) occur at most one time in the input.

/*
Approach:
    A graph problem! You can use an ordinary method like BFS or DFS. For this question, I use a union-find data structure.
*/

#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n);
        init();
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
        root[b] = a;
    }
    
    int setCount()
    {
        int count = 0;
        for (int i=0; i<root.size(); ++i)
        {
            if (root[i] == i)
            {
                count += 1;
            }
        }
        return count;
    }


private:
    vector<int> root;

    void init()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }
};

class Solution 
{
public:
    int earliestAcq(vector<vector<int>>& logs, int n) 
    {
        sort(logs.begin(), logs.end());
        UnionFind* obj = new UnionFind(n);
        int result = -1;
        for (const auto& v: logs)
        {
            obj->join(v[1], v[2]);
            // When there is only one connected component in the graph, which means everyone has become friends.
            if (obj->setCount() == 1)
            {
                result = v[0];
                break;
            }
        }
        delete obj;
        return result;
    }
};