// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

// Example 1:


// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:


// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:


// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 1 <= Node.val <= 100
// Each node has a unique value.
// x != y
// x and y are exist in the tree.

/*
Approach:
    We can use two hashmaps to reduce the time complexity. If we don't do so, we need to use two DFS to judge whether two nodes are cousins.
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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        // This hashmap is to store the node's address and level index.
        unordered_map<int, pair<struct TreeNode*, int>> _map {};
        // This hashmap is to store node and its parent.
        unordered_map<struct TreeNode*, struct TreeNode*> parentMap {};
        dfs(root, _map, parentMap, 0);
        
        if (_map[x].second != _map[y].second)
        {
            return false;
        }
        if (parentMap[_map[x].first] == parentMap[_map[y].first])
        {
            return false;
        }
        return true;
    }

private:
    void dfs(struct TreeNode* root, unordered_map<int, pair<struct TreeNode*, int>>& _map, unordered_map<struct TreeNode*, struct TreeNode*>& parentMap, int level)
    {
        if (nullptr == root)
        {
            return;
        }
        _map[root->val] = make_pair(root, level);
        if (root->left != nullptr)
        {
            parentMap[root->left] = root;
        }
        if (root->right != nullptr)
        {
            parentMap[root->right] = root;
        }
        dfs(root->left, _map, parentMap,  1+level);
        dfs(root->right, _map, parentMap, 1+level);
        return;
    }
};