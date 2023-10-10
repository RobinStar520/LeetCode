// On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

// The north direction is the positive direction of the y-axis.
// The south direction is the negative direction of the y-axis.
// The east direction is the positive direction of the x-axis.
// The west direction is the negative direction of the x-axis.
// The robot can receive one of three instructions:

// "G": go straight 1 unit.
// "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
// "R": turn 90 degrees to the right (i.e., clockwise direction).
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

// Example 1:

// Input: instructions = "GGLLGG"
// Output: true
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "G": move one step. Position: (0, 2). Direction: North.
// "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
// "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
// "G": move one step. Position: (0, 1). Direction: South.
// "G": move one step. Position: (0, 0). Direction: South.
// Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
// Based on that, we return true.
// Example 2:

// Input: instructions = "GG"
// Output: false
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "G": move one step. Position: (0, 2). Direction: North.
// Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
// Based on that, we return false.
// Example 3:

// Input: instructions = "GL"
// Output: true
// Explanation: The robot is initially at (0, 0) facing the north direction.
// "G": move one step. Position: (0, 1). Direction: North.
// "L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
// "G": move one step. Position: (-1, 1). Direction: West.
// "L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
// "G": move one step. Position: (-1, 0). Direction: South.
// "L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
// "G": move one step. Position: (0, 0). Direction: East.
// "L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
// Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
// Based on that, we return true.
 

// Constraints:

// 1 <= instructions.length <= 100
// instructions[i] is 'G', 'L' or, 'R'.

/*
Approach:
    The first impression of this question is using a brute force method to check whether the robot's path is a circle. But this method can't work since
for each move, we must confirm the robot's direction. So we can use a mathematical approach: First, simulate the moving process for a round; Second, check
the final direction of the robot. The robot's path can't be a circle if the final direction is North.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool isRobotBounded(string instructions) 
    {
        vector<pair<pair<int,int>, char>> pos {};
        pos.push_back({{0,0}, 'N'});
        unordered_map<char,pair<int,int>> dirs {
            {'N', {0, 1}},
            {'S', {0, -1}},
            {'E', {1, 0}},
            {'W', {-1, 0}}
        };
        for(char c:instructions)
        {
            switch(c)
            {
                case 'G':{
                    auto v = pos.back();
                    int x = v.first.first;
                    int y = v.first.second;
                    char d = v.second;
                    int nx = dirs[d].first+x;
                    int ny = dirs[d].second+y;
                    pos.push_back({{nx, ny}, d});
                    break;
                }
                case 'L':{
                    auto v = pos.back();
                    int x = v.first.first;
                    int y = v.first.second;
                    char d = v.second;
                    if(d=='N') d = 'W';
                    else if(d=='W') d = 'S';
                    else if(d=='S') d = 'E';
                    else if(d=='E') d = 'N';
                    pos.push_back({{x, y}, d});
                    break;
                }  
                case 'R':{
                    auto v = pos.back();
                    int x = v.first.first;
                    int y = v.first.second;
                    char d = v.second;
                    if(d=='N') d = 'E';
                    else if(d=='E') d = 'S';
                    else if(d=='S') d = 'W';
                    else if(d=='W') d = 'N';
                    pos.push_back({{x, y}, d});
                    break;
                }
            }
        }
        auto v = pos.back();
        int x = v.first.first;
        int y = v.first.second;
        char d = v.second;
        if(x==0&&y==0) return true;
        return d!='N';
    }
};