// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

// Example 1:


// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
// Example 2:


// Input: root = [1,2,3], targetSum = 5
// Output: []
// Example 3:

// Input: root = [1,2], targetSum = 0
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

/*
Approach:
    This is a binary tree problem combined with backtracking. We need to find all the paths from the root node to all the leaf nodes. To avoid redundant 
operations, we should set an additional argument called "pathSum", which denotes the current sum result of the path. 
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
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path {};
        vector<vector<int>> result {};
        int curSum = 0;
        dfs(root, curSum, targetSum, path, result);
        return result;
    }

private:
    void dfs(struct TreeNode* root, int& pathSum, int targetSum, vector<int>& path, vector<vector<int>>& result)
    {
        if (nullptr == root)
        {
            return;
        }
        pathSum += root->val;
        path.push_back(root->val);
        if (nullptr == root->left && nullptr == root->right)
        {
            if (targetSum == pathSum)
            {
                result.push_back(path);
            }
        }
        else
        {
            dfs(root->left, pathSum, targetSum, path, result);
            dfs(root->right, pathSum, targetSum, path, result);
        }
        // Backtracking.
        path.pop_back();
        pathSum -= root->val;
        return;
    }
};