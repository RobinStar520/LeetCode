// Given the root of a binary tree and two integers p and q, return the distance between the nodes of value p and value q in the tree.

// The distance between two nodes is the number of edges on the path from one to the other.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
// Output: 3
// Explanation: There are 3 edges between 5 and 0: 5-3-1-0.
// Example 2:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
// Output: 2
// Explanation: There are 2 edges between 5 and 7: 5-2-7.
// Example 3:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
// Output: 0
// Explanation: The distance between a node and itself is 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 109
// All Node.val are unique.
// p and q are values in the tree.

/*
Approach:
    We divide the problem into three parts: First, find the nodes that the value equals p and q individually. We can't skip this step since the question
doesn't provide the address of the nodes. Second, find the lowest common ancestor of the two nodes; Last, calculate the distance from the ancestor we have 
found to the two nodes. I wrote three auxiliary functions to clarify the structure; You can distinguish what they can do via their name.
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

class Solution 
{
public:
    int findDistance(TreeNode* root, int p, int q) 
    {
        struct TreeNode* node1 = findNode(root, p);
        struct TreeNode* node2 = findNode(root, q);
        struct TreeNode* ancestor = lowestCommonAncestor(root, node1, node2);
        int result = getDistance(ancestor, node1, 0) + getDistance(ancestor, node2, 0);
        return result;
    }

private:
    // Find the address of the node based on its value.
    struct TreeNode* findNode(struct TreeNode* root, int value)
    {
        if (nullptr == root || root->val == value)
        {
            return root;
        }
        struct TreeNode* left = findNode(root->left, value);
        struct TreeNode* right = findNode(root->right, value);
        struct TreeNode* result;
        if (left != nullptr)
        {
            result = left;
        }
        if (right != nullptr)
        {
            result = right;
        }
        return result;
    }

    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* node1, struct TreeNode* node2)
    {
        if (nullptr == root)
        {
            return nullptr;
        }
        if (node1 == root || node2 == root)
        {
            return root;
        }
        struct TreeNode* left = lowestCommonAncestor(root->left, node1, node2);
        struct TreeNode* right = lowestCommonAncestor(root->right, node1, node2);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }

    int getDistance(struct TreeNode* root, struct TreeNode* node, int distance)
    {
        if (nullptr == root)
        {
            return 0;
        }
        if (root == node)
        {
            return distance;
        }
        int left = getDistance(root->left, node, 1+distance);
        int right = getDistance(root->right, node, 1+distance);
        return left == 0 ? right : left;
    }

};