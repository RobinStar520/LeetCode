// Given the root of a binary tree, turn the tree upside down and return the new root.

// You can turn a binary tree upside down with the following steps:

// The original left child becomes the new root.
// The original root becomes the new right child.
// The original right child becomes the new left child.

// The mentioned steps are done level by level. It is guaranteed that every right node has a sibling (a left node with the same parent) and has no children.

 

// Example 1:


// Input: root = [1,2,3,4,5]
// Output: [4,5,2,null,null,3,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree will be in the range [0, 10].
// 1 <= Node.val <= 10
// Every right node in the tree has a sibling (a left node that shares the same parent).
// Every right node in the tree has no children.

/*
Approach:
    For this question, we need to modify the pointers of each node. Modifying them straightforwardly is hard, so we should use some auxiliary space 
to help us.
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
#include <queue>

using namespace std;

class Solution 
{
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) 
    {
        if (nullptr == root || (nullptr == root->left && nullptr == root->right))
        {
            return root;
        }
        // This is an auxilary vector.
        vector<vector<struct TreeNode*>> result {};
        bfs(root, result);
        const int n = result.size();
        for (auto& v: result)
        {
            for (auto& p: v)
            {
                p->left = nullptr;
                p->right = nullptr;
            }
        }
        for (int i=1; i<n; ++i)
        {
            if (result[i].size() <= 1)
            {
                result[i].push_back(nullptr);
            }
            struct TreeNode* node = result[i].front();
            node->left = result[i].back();
            node->right = result[i - 1].front();
        }
        return result.back().front();
    }

private:
    void bfs(struct TreeNode* root, vector<vector<struct TreeNode*>>& result)
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
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            result.push_back(layer);
        }
        return;
    }
};