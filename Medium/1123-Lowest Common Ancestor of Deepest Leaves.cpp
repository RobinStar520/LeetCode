// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

// Recall that:

// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest leaf-nodes of the tree.
// Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree, and it's the lca of itself.
// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

// Constraints:

// The number of nodes in the tree will be in the range [1, 1000].
// 0 <= Node.val <= 1000
// The values of the nodes in the tree are unique.

/*
Approach:
    First, we need to find the deepest leaves. We can use the BFS to find the last level of the binary tree easily; Second, find the lowest common
ancestor. To find the lowest common ancestor, we have to compare every two nodes in the deepest leaves. Until now, I haven't found another effective 
way to skip or optimise this step.
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        vector<vector<struct TreeNode*>> layers {};
        bfs(root, layers);
        
        if (layers.back().size() == 1)
        {
            return layers.back().back();
        }
        const int n = layers.back().size();
        struct TreeNode* result = layers.back().front();
        for (int i=1; i<n; ++i)
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

    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* node1, struct TreeNode* node2)
    {
        if (nullptr == root || node1 == root || node2 == root)
        {
            return root;
        }
        struct TreeNode* leftNode = lowestCommonAncestor(root->left, node1, node2);
        struct TreeNode* rightNode = lowestCommonAncestor(root->right, node1, node2);
        if (leftNode != nullptr && rightNode != nullptr)
        {
            return root;
        }
        return leftNode == nullptr ? rightNode : leftNode;
    }
};