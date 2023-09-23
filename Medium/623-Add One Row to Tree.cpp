// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

// Example 1:


// Input: root = [4,2,6,3,1,5], val = 1, depth = 2
// Output: [4,1,1,2,null,null,6,3,1,5]
// Example 2:


// Input: root = [4,2,null,3,1], val = 1, depth = 3
// Output: [4,2,null,1,1,3,null,null,1]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// The depth of the tree is in the range [1, 104].
// -100 <= Node.val <= 100
// -105 <= val <= 105
// 1 <= depth <= the depth of tree + 1

/*
Approach:
    We can use the BFS to find nodes in each layer. Insert a row based on the insertion rule.
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        vector<vector<struct TreeNode*>> layers {};
        bfs(root, layers);
        if (depth == 1)
        {
            struct TreeNode* newRoot = new struct TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        vector<struct TreeNode*> newNodes {};
        for (int i=0; i<layers[depth - 2].size()*2; ++i)
        {
            struct TreeNode* node = new struct TreeNode(val);
            newNodes.push_back(node);
        }
        
        auto prevLevel = layers[depth - 2];
        // Modify the left and right pointers.
        for (int i=0; i<prevLevel.size(); ++i)
        {
            struct TreeNode* preLeft = layers[depth - 2][i]->left;
            struct TreeNode* preRight = layers[depth - 2][i]->right;
            layers[depth - 2][i]->left = newNodes[i * 2];
            layers[depth - 2][i]->right = newNodes[i * 2 + 1];
            newNodes[i * 2]->left = preLeft;
            newNodes[i * 2 + 1]->right = preRight;

        }
        return root;
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
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            layers.push_back(layer);
        }
        return;
    }
};