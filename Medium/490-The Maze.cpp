// There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

// You may assume that the borders of the maze are all walls (see examples).

 

// Example 1:


// Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
// Output: true
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
// Example 2:


// Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
// Output: false
// Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
// Example 3:

// Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
// Output: false
 

// Constraints:

// m == maze.length
// n == maze[i].length
// 1 <= m, n <= 100
// maze[i][j] is 0 or 1.
// start.length == 2
// destination.length == 2
// 0 <= startrow, destinationrow <= m
// 0 <= startcol, destinationcol <= n
// Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
// The maze contains at least 2 empty spaces.

/*
Approach:
    This is a trick question because we can't only check whether there is at least one path from the start position to the destination. 
Our task is to check if there exists a path from the start cell to the destination cell, we can use a breadth-first search (BFS) algorithm.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) 
    {
        const int m = maze.size();
        const int n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q {};
        q.push(make_pair(start.front(), start.back()));
        visited[start.front()][start.back()] = 1;
        while (!q.empty())
        {
            auto [cur_x, cur_y] = q.front();
            q.pop();
            if (destination.front() == cur_x && destination.back() == cur_y)
            {
                return true;
            }
            for (int i=0; i<4; ++i)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                while (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && maze[next_x][next_y] == 0)
                {
                    next_x += dx[i];
                    next_y += dy[i];
                }
                next_x -= dx[i];
                next_y -= dy[i];
                if (!visited[next_x][next_y])
                {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                }
            }
        }
        return false;
    }

private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
};