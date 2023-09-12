// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

// Example 1:


// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4
 

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.

/*
Approach:
    First, we should know that this is not a graph problem since we only need to calculate the perimeter. So, traverse the matrix, if the value of a 
cell is 1, try to find whether it has neighbours in four directions. Be aware of the boundary cell.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int up, down, left, right;
        int result = 0;
        
        for (int r = 0; r < rows; r++) 
        {
            for (int c = 0; c < cols; c++) 
            {
                if (grid[r][c] == 1) 
                {
                    if (r == 0)
                    {
                        up = 0;
                    }
                    else
                    {
                        up = grid[r-1][c];
                    }
                     
                    if (c == 0)
                    {
                        left = 0; 
                    }
                    else
                    {
                        left = grid[r][c-1]; 
                    }

                    if (r == rows-1)
                    {
                        down = 0; 
                    }
                    else
                    {
                        down = grid[r+1][c]; 
                    }
                        
                    if (c == cols-1)
                    {
                         right = 0; 
                    }

                    else
                    {
                        right = grid[r][c+1]; 
                    }
                        
                    result += 4 - (up + left + right + down);
                }
            }
        }

        return result;
    }
};