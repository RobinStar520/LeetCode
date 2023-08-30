// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:

// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

 

// Example 1:

// Input: moves = "L_RL__R"
// Output: 3
// Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
// Example 2:

// Input: moves = "_R__LL_"
// Output: 5
// Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".
// Example 3:

// Input: moves = "_______"
// Output: 7
// Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".
 

// Constraints:

// 1 <= moves.length == n <= 50
// moves consists only of characters 'L', 'R' and '_'.

/*
Approach:
    First, let's comprehend the question: "L" denotes moving towards left one step and "R" denotes moving right towards one step. If we consider the right side
is the positive direction, which means "R" represents +1, and "L" represents -1. If we want to make our final position as far as possible from the original point,
we should head in one direction as much as possible. So traverse the whole string, count the occurrences of "L" and "R" and find the maximum of their occurrences.
and then we will get the final result successfully. Formally, we need to let the ones of "R" and "L" appear as much as possible.
*/

#include <string>

using namespace std;

class Solution 
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        // There are only three different items in the string, so use three variables to represent them.
        int left = 0, right = 0, underline = 0;
        int result = 0;
        for (const auto& ch: moves)
        {
            switch (ch)
            {
                case 'L':
                    left ++;
                    break;
                case 'R':
                    right ++;
                    break;
                case '_':
                    underline ++;
                    break;
                default:
                    break;
            }
        }
        // This is a special case.
        if (underline == moves.size())
        {
            result = underline;
        }
        // Find the result greedily.
        else
        {
            int a = std::max(left, right);
            int b = std::min(left, right);
            result = a - b + underline;
        }
        return result;

    }
};