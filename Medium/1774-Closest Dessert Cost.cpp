// You would like to make dessert and are preparing to buy the ingredients. You have n ice cream base flavors and m types of toppings to choose from. You must follow these rules when making your dessert:

// There must be exactly one ice cream base.
// You can add one or more types of topping or have no toppings at all.
// There are at most two of each type of topping.
// You are given three inputs:

// baseCosts, an integer array of length n, where each baseCosts[i] represents the price of the ith ice cream base flavor.
// toppingCosts, an integer array of length m, where each toppingCosts[i] is the price of one of the ith topping.
// target, an integer representing your target price for dessert.
// You want to make a dessert with a total cost as close to target as possible.

// Return the closest possible cost of the dessert to target. If there are multiple, return the lower one.

 

// Example 1:

// Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
// Output: 10
// Explanation: Consider the following combination (all 0-indexed):
// - Choose base 1: cost 7
// - Take 1 of topping 0: cost 1 x 3 = 3
// - Take 0 of topping 1: cost 0 x 4 = 0
// Total: 7 + 3 + 0 = 10.
// Example 2:

// Input: baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
// Output: 17
// Explanation: Consider the following combination (all 0-indexed):
// - Choose base 1: cost 3
// - Take 1 of topping 0: cost 1 x 4 = 4
// - Take 2 of topping 1: cost 2 x 5 = 10
// - Take 0 of topping 2: cost 0 x 100 = 0
// Total: 3 + 4 + 10 + 0 = 17. You cannot make a dessert with a total cost of 18.
// Example 3:

// Input: baseCosts = [3,10], toppingCosts = [2,5], target = 9
// Output: 8
// Explanation: It is possible to make desserts with cost 8 and 10. Return 8 as it is the lower cost.
 

// Constraints:

// n == baseCosts.length
// m == toppingCosts.length
// 1 <= n, m <= 10
// 1 <= baseCosts[i], toppingCosts[i] <= 104
// 1 <= target <= 104


/*
Approach:
    The constraints of the question are small, we can enumerate all the possibilities, and think about the backtracking algorithm. Actually, the most difficult
part is how to "There are at most two of each type of topping.". We can find another way to describe the question: Find all the subsets of a
given vector, but for each element, you can choose less than twice. This is a solution as well. Use backtracking to find all the subsets and test them individually,
but unfortunately, this solution can't pass all the test cases due to the memory limit exceeded. 
    Let's focus on the another condition: "You can add one or more types of topping or have no toppings at all", which means for an element in "toppigCosts", we have
three choices: add 0 * element, add 1 * element and add 2 * element. So, we only need to calculate the three situations and get the optimal value.
*/


#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        int result = 9999999;
        for (const auto& cost: baseCosts)
        {
            this->backtracking(0, result, target, cost, toppingCosts);
        }
        return result;
    }

private:
    void backtracking(int start, int& result, int target, int current, vector<int>& toppingCosts)
    {
        if (std::abs(target - result) > std::abs(target - current))
        {
            result = current;
        }
        else if (std::abs(target - result) == std::abs(current - target))
        {
            result = std::min(result, current);
        }
        if (start >= toppingCosts.size())
        {
            return;
        }
        // Main point: Calculate three situations, and get the optimal value.
        this->backtracking(start+1, result, target, current, toppingCosts);
        this->backtracking(start+1, result, target, current + toppingCosts[start], toppingCosts);
        this->backtracking(start+1, result, target, current + toppingCosts[start] * 2, toppingCosts);
        return;

    }
};