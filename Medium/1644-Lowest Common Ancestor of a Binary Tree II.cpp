// Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

// According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)". A descendant of a node x is a node y that is on the path from node x to some leaf node.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:



// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.
// Example 3:



// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
// Output: null
// Explanation: Node 10 does not exist in the tree, so return null.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q

/*
Approach:
    For this kind of question, total two steps: First, locate the nodes(optional, adjust based on the question); Second, find their lowest common ancestor.
We always use DFS to solve this kind of problem.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        struct TreeNode* node1 = findNode(root, p->val);
        struct TreeNode* node2 = findNode(root, q->val);
        if (node1 == nullptr || node2 == nullptr)
        {
            return nullptr;
        }
        return dfs(root, p, q);
    }

private:
    // Locate the node based on the value.
    struct TreeNode* findNode(struct TreeNode* root, int value)
    {
        if (nullptr == root || value == root->val)
        {
            return root;
        }
        struct TreeNode* result = nullptr;
        struct TreeNode* left = findNode(root->left, value);
        struct TreeNode* right = findNode(root->right, value);
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

    struct TreeNode* dfs(struct TreeNode* root, struct TreeNode* node1, struct TreeNode* node2)
    {
        if (nullptr == root)
        {
            return nullptr;
        }
        if (node1 == root || node2 == root)
        {
            return root;
        }
        struct TreeNode* left = dfs(root->left, node1, node2);
        struct TreeNode* right = dfs(root->right, node1, node2);
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }
};