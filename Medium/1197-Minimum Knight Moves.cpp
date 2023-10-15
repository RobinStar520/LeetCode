// In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.


// Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.

 

// Example 1:

// Input: x = 2, y = 1
// Output: 1
// Explanation: [0, 0] → [2, 1]
// Example 2:

// Input: x = 5, y = 5
// Output: 4
// Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 

// Constraints:

// -300 <= x, y <= 300
// 0 <= |x| + |y| <= 300

/*
Approach:
    This is a graph problem, we can use BFS to find the shortest path.
*/

#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

class Solution 
{
public:
    int minKnightMoves(int x, int y) 
    {
        x = abs(x);
        y = abs(y);
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        int result = 0;

        q.push({0, 0});
        visited.insert({0, 0});

        const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

        while (!q.empty()) 
        {
            int n = q.size();
            while (n--) 
            {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                if (cur_x == x && cur_y == y) 
                {
                    return result;
                }
                for (int i = 0; i < 8; ++i) 
                {
                    int next_x = cur_x + dx[i];
                    int next_y = cur_y + dy[i];
                    if (next_x >= -1 && next_y >= -1 && visited.find({next_x, next_y}) == visited.end()) 
                    {
                        q.push({next_x, next_y});
                        visited.insert({next_x, next_y});
                    }
                }
            }
            result += 1;
        }

        return result;
    }
};
