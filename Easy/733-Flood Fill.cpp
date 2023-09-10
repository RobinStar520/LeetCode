// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

 

// Example 1:


// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

// Constraints:

// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], color < 216
// 0 <= sr < m
// 0 <= sc < n

/*
Approach:
    For this question, we only need to notice when we should modify the cell's colour, and it's suitable to use the BFS since we will search the 
four directions simultaneously.
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        const int m = image.size();
        const int n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        this->bfs(sr, sc, color, image, visited);
        return image;
    }

private:
    void bfs(int x, int y, int color,  vector<vector<int>>& image, vector<vector<int>>& visited)
    {
        queue<pair<int, int>> q {};
        q.push(make_pair(x, y));
        visited[x][y] = 1;
        int initColor = image[x][y];
        image[x][y] = color;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (int i=0; i<4; ++i)
            {
                int X = p.first + directions[i][0];
                int Y = p.second + directions[i][1];
                if (X < 0 || Y < 0 || X >= image.size() || Y >= image[0].size())
                {
                    continue;
                }
                if (!visited[X][Y] && image[X][Y] == initColor)
                {
                    visited[X][Y] = 1;
                    image[X][Y] = color;
                    q.push(make_pair(X, Y));
                }
            }
        }
        return;
    }

    vector<vector<int>> directions {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
};