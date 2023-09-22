// Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

// Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

// Example 1:



// Input: root = [2,3,1,3,1,null,1]
// Output: 2 
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
// Example 2:



// Input: root = [2,1,1,1,3,null,null,null,null,null,1]
// Output: 1 
// Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
// Example 3:

// Input: root = [9]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 9

/*
Approach:
    The essence of this question is for us to find all paths from the root node to the leaf nodes. But note that we must statistic the frequency of the
number when we are searching the paths due to the huge constaint.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int result = 0;
        unordered_map<int, int> _map {};
        dfs(root, _map, result);
        return result;
    }

private:
    void dfs(struct TreeNode* root, unordered_map<int, int>& _map, int& result)
    {
        if (nullptr == root)
        {
            return;
        }
        _map[root->val] ++;
        if (nullptr == root->left && nullptr == root->right)
        {
            int odds = 0;
            bool flag = true;
            for (const auto& [key, value]: _map)
            {
                if (value % 2 == 1)
                {
                    odds ++;
                }
                if (odds >= 2)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                result += 1;
            }
        }
        else
        {
            dfs(root->left, _map, result);
            dfs(root->right, _map, result);
        }
        // Backtracking.
        _map[root->val] --;
        if (_map[root->val] <= 0)
        {
            _map.erase(root->val);
        }
        return;
    }
};