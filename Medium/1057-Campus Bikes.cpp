// On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

// You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. All the given positions are unique.

// Assign a bike to each worker. Among the available bikes and workers, we choose the (workeri, bikej) pair with the shortest Manhattan distance between each other and assign the bike to that worker.

// If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index. If there are multiple ways to do that, we choose the pair with the smallest bike index. Repeat this process until there are no available workers.

// Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith worker is assigned to.

// The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

 

// Example 1:


// Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
// Output: [1,0]
// Explanation: Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
// Example 2:


// Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
// Output: [0,2,1]
// Explanation: Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].
 

// Constraints:

// n == workers.length
// m == bikes.length
// 1 <= n <= m <= 1000
// workers[i].length == bikes[j].length == 2
// 0 <= xi, yi < 1000
// 0 <= xj, yj < 1000
// All worker and bike locations are unique.

/*
Approach:
    For this question, follow the question description step by step. It's an easy sorting problem.
*/

#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

struct Comp
{
public:
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        bool flag = false;
        if (v1[0] != v2[0])
        {
            flag = v1[0] < v2[0]; 
        }
        else
        {
            if (v1[1] != v2[1])
            {
                flag = v1[1] < v2[1];
            }
            else
            {
                flag = v1[2] < v2[2];
            }
        }
        return flag;
    }
};

class Solution 
{
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        const int m = workers.size();
        const int n = bikes.size();
        vector<vector<int>> vct {};
        vector<int> result(m, -1);
        unordered_set<int> visited {};
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                int dis = std::abs(workers[i][1] - bikes[j][1]) + std::abs(workers[i][0] - bikes[j][0]);
                vct.push_back({dis, i, j});
            }
        }

        sort(vct.begin(), vct.end(), Comp());

        for (const auto& v: vct)
        {
            int worker = v[1];
            int bike = v[2];
            if (result[worker] == -1 && visited.find(bike) == visited.end())
            {
                result[worker] = bike;
                visited.insert(bike);
            }
        }

        return result;
    }
};