// There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

// Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

 

// Example 1:



// Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
// Output: ["B","C"] 
// Explanation: 
// You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
// Person with id = 1 -> watchedVideos = ["C"] 
// Person with id = 2 -> watchedVideos = ["B","C"] 
// The frequencies of watchedVideos by your friends are: 
// B -> 1 
// C -> 2
// Example 2:



// Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
// Output: ["D"]
// Explanation: 
// You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).
 

// Constraints:

// n == watchedVideos.length == friends.length
// 2 <= n <= 100
// 1 <= watchedVideos[i].length <= 100
// 1 <= watchedVideos[i][j].length <= 8
// 0 <= friends[i].length < n
// 0 <= friends[i][j] < n
// 0 <= id < n
// 1 <= level < n
// if friends[i] contains j, then friends[j] contains i

/*
Approach:
    Do BFS to find the kth level friends. Then collect movies saw by kth level friends and sort them accordingly.
*/

#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        unordered_map<int, vector<int>> graph {};
        unordered_map<string, int> countMap {};
        unordered_set<int> visited {};
        vector<string> result {};
        const int n = friends.size();
        for (int i=0; i<n; ++i)
        {
            for (const auto& num: friends[i])
            {
                graph[i].push_back(num);
                graph[num].push_back(i);
            }
        }
        queue<int> q {};
        q.push(id);
        visited.insert(id);
        // Start to do BFS.
        while (!q.empty())
        {
            int n = q.size();
            // Stop the BFS when the level goes into zero.
            if (level == 0)
            {
                break;
            }
            while (n --)
            {
                int node = q.front();
                q.pop();
                for (const auto& neighbour: graph[node])
                {
                    if (visited.find(neighbour) == visited.end())
                    {
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            level -= 1;
            
        }
        while (!q.empty())
        {
            int index= q.front();
            q.pop();
            for (const auto& str: watchedVideos[index])
            {
                countMap[str] += 1;
            }
        }

        vector<pair<string, int>> vct(countMap.begin(), countMap.end());
        // Sort the vector according to the description of the quesiton.
        sort(vct.begin(), vct.end(), [&](const pair<string, int>& p1, const pair<string, int>& p2) -> bool {
            if (p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
            else
            {
                return p1.second < p2.second;
            }
        });
        for (const auto& [key, value]: vct)
        {
            result.push_back(key);
        }
        return result;
    }
};