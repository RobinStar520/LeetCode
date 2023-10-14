// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.

 

// Example 1:


// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]
// Example 2:


// Input: root = [2,1,1]
// Output: [[1]]
// Example 3:


// Input: root = [2,2,2,3,null,3,null]
// Output: [[2,3],[3]]
 

// Constraints:

// The number of the nodes in the tree will be in the range [1, 5000]
// -200 <= Node.val <= 200

/*
Approach:
    For this question, the most difficult part is denoting a binary tree. An effective way is converting the binary tree to a C++ string using
post-order traversal.
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
#include <unordered_map>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string, int> _map {};
        vector<struct TreeNode*> result {};
        dfs(root, _map, result);
        return result;
    }

private:
    string dfs(struct TreeNode* root, unordered_map<string, int>& _map, vector<struct TreeNode*>& result)
    {
        if (nullptr == root)
        {
            return {};
        }
        string str = "(" + dfs(root->left, _map, result) + ")" +  to_string(root->val) + "("
        + dfs(root->right, _map, result) + ")";
        _map[str] ++;
        if (_map[str] == 2)
        {
            result.push_back(root);
        }
        return str;
    }
};