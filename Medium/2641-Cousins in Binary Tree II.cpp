// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.

 

// Example 1:


// Input: root = [5,4,9,1,10,null,7]
// Output: [0,0,0,7,7,null,11]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 5 does not have any cousins so its sum is 0.
// - Node with value 4 does not have any cousins so its sum is 0.
// - Node with value 9 does not have any cousins so its sum is 0.
// - Node with value 1 has a cousin with value 7 so its sum is 7.
// - Node with value 10 has a cousin with value 7 so its sum is 7.
// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
// Example 2:


// Input: root = [3,1,2]
// Output: [0,0,0]
// Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 3 does not have any cousins so its sum is 0.
// - Node with value 1 does not have any cousins so its sum is 0.
// - Node with value 2 does not have any cousins so its sum is 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 104

/*
Approach:
    First, let's look at the constraints: The largest number of the nodes in the tree could be 100,000, which means you can hardly use two or more BFS
or DSF. So, we must come up with a one-pass algorithm to solve it.
    How can we judge whether two nodes are cousins on the same level? Apparently via their parent.
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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        // Don't forget to modify the value of the root.
        root->val = 0;
        bfs(root);
        return root;
    }

private:
    void bfs(struct TreeNode*& root)
    {
        if (nullptr == root)
        {
            return;
        }
        vector<vector<struct TreeNode*>> layers {};
        queue<struct TreeNode*> q {};
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<struct TreeNode*> layer {};
            int sum = 0;
            while (n --)
            {
                struct TreeNode* node = q.front();
                q.pop();
                layer.push_back(node);
                sum += node->val;
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            if (layers.empty())
            {
                layers.push_back(layer);
                continue;
            }
            for (int i=0; i<layers.back().size(); ++i)
            {
                if (layers.back()[i]->left != nullptr && layers.back()[i]->right != nullptr)
                {
                    int k = layers.back()[i]->left->val + layers.back()[i]->right->val;
                    layers.back()[i]->left->val = sum - k;
                    layers.back()[i]->right->val = sum - k;
                }
                else if (layers.back()[i]->left != nullptr && layers.back()[i]->right == nullptr)
                {
                    int _val = layers.back()[i]->left->val;
                    layers.back()[i]->left->val = sum - _val;
                }
                else if (layers.back()[i]->left == nullptr && layers.back()[i]->right != nullptr)
                {
                    int _val = layers.back()[i]->right->val;
                    layers.back()[i]->right->val = sum - _val;
                }

            }
            layers.push_back(layer);
        }
    }
};