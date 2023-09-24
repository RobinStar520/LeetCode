// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

 

// Example 1:


// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
// Example 2:

// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]
 

// Constraints:

// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.

/*
Approach:
    This is an easy question. We need to use a post-order traverse to remove the target node.
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
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        unordered_set<int> _set(to_delete.begin(), to_delete.end());
        vector<struct TreeNode*> result {};
        dfs(root, result, _set);
        if (nullptr != root)
        {
            result.push_back(root);
        }
        return result;
    }

private:
    // Note: We should pay more attention to the data type of thje first argument. It should be a reference of a pointer.
    void dfs(struct TreeNode* &root, vector<struct TreeNode*>& result, unordered_set<int>& _set)
    {
        if (nullptr == root)
        {
            return;
        }
        dfs(root->left, result, _set);
        dfs(root->right, result, _set);
        if (_set.find(root->val) != _set.end())
        {
            if (nullptr != root->left)
            {
                result.push_back(root->left);
            }
            if (nullptr != root->right)
            {
                result.push_back(root->right);
            }
            // Here, we cannot delete root directly. If you do this, the left and right children will be lost. This can cause a memory leak.
            root = nullptr;
        }
    }
};