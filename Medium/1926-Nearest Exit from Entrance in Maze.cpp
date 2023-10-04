// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

// Example 1:


// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1
// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
// Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.
// Example 2:


// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
// Output: 2
// Explanation: There is 1 exit in this maze at [1,2].
// [1,0] does not count as an exit since it is the entrance cell.
// Initially, you are at the entrance cell [1,0].
// - You can reach [1,2] by moving 2 steps right.
// Thus, the nearest exit is [1,2], which is 2 steps away.
// Example 3:


// Input: maze = [[".","+"]], entrance = [0,0]
// Output: -1
// Explanation: There are no exits in this maze.
 

// Constraints:

// maze.length == m
// maze[i].length == n
// 1 <= m, n <= 100
// maze[i][j] is either '.' or '+'.
// entrance.length == 2
// 0 <= entrancerow < m
// 0 <= entrancecol < n
// entrance will always be an empty cell.

/*
Approach:
    We can uas a BFS to find the shortest path to an exit
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        const int m = maze.size();
        const int n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        
        // Mark entrance cell as visited
        visited[entrance[0]][entrance[1]] = 1;
        
        int distance = 0;
        queue<pair<int, int>> q {};
        q.push(make_pair(entrance[0], entrance[1]));
        
        while (!q.empty()) 
        {
            int size = q.size();  // Process cells level by level
            distance++;  // Increment distance
            
            for (int i = 0; i < size; ++i) 
            {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                
                for (const auto& dir : directions) 
                {
                    int next_x = cur_x + dir[0];
                    int next_y = cur_y + dir[1];
                    
                    if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n &&
                        !visited[next_x][next_y] && maze[next_x][next_y] == '.') 
                        {
                        
                        // Mark the cell as visited and check if it's an exit
                        visited[next_x][next_y] = 1;
                        if (next_x == 0 || next_x == m - 1 || next_y == 0 || next_y == n - 1) 
                        {
                            return distance;
                        }
                        
                        q.push(make_pair(next_x, next_y));
                    }
                }
            }
        }
        
        return -1;  // No exit found
    }

private:
    int bfs(vector<vector<char>>& maze, vector<vector<int>>& visited, int x, int y)
    {
        const int m = maze.size();
        const int n = maze[0].size();
        int distance = 0;
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        while (!q.empty())
        {
            auto [cur_x, cur_y] = q.front();
            q.pop();
            
            if (maze[cur_x][cur_y] == '#')
            {
                return distance;
            }
            for (int i=0; i<4; ++i)
            {
                int next_x = cur_x + directions[i][0];
                int next_y = cur_y + directions[i][1];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !visited[next_x][next_y] && maze[next_x][next_y] != '+')
                {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                    
                }
            }
            distance += 1;
        }
        return -1;
    }

    vector<vector<int>> directions {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
};