// Given the root of a binary tree, the depth of each node is the shortest distance to the root.

// Return the smallest subtree such that it contains all the deepest nodes in the original tree.

// A node is called the deepest if it has the largest depth possible among any node in the entire tree.

// The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest nodes of the tree.
// Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree.
// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

// Constraints:

// The number of nodes in the tree will be in the range [1, 500].
// 0 <= Node.val <= 500
// The values of the nodes in the tree are unique.

/*
Approach:
    This question is same sa question 1123.
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
#include <queue>
#include <vector>

using namespace std;

class Solution 
{
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        vector<vector<struct TreeNode*>> layers {};
        bfs(root, layers);
        struct TreeNode* result = layers.back()[0];
        for (int i=1; i<layers.back().size(); ++i)
        {
            result = lowestCommonAncestor(root, result, layers.back()[i]);
        }
        return result;
    }

private:
    void bfs(struct TreeNode* root, vector<vector<struct TreeNode*>>& layers)
    {
        if (nullptr == root)
        {
            return;
        }
        queue<struct TreeNode*> q {};
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<struct TreeNode*> layer {};
            while (n --)
            {
                struct TreeNode* node = q.front();
                q.pop();
                layer.push_back(node);
                if (nullptr != node->left)
                {
                    q.push(node->left);
                }
                if (nullptr != node->right)
                {
                    q.push(node->right);
                }
            }
            layers.push_back(layer);
        }
        return;
    }

    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* t1, struct TreeNode* t2)
    {
        if (nullptr == root || t1 == root || t2 == root)
        {
            return root;
        }
        struct TreeNode* left = lowestCommonAncestor(root->left, t1, t2);
        struct TreeNode* right = lowestCommonAncestor(root->right, t1, t2);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }
};