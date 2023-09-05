// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
// Output: true
// Example 2:


// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

/*
Approach:
    This question has at least three different approaches. A traditional method is to store all the node values into a vector via an in-order DFS, 
and judge whether the vector is sorted in ascending order. This approach uses an extra vector. To save the memory, I decided to use a single DFS
approach based on the attributes of the binary search tree.
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
#include <limits>

using namespace std;

class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        const long MAX = numeric_limits<long>::max();
        const long MIN = numeric_limits<long>::min();
        return this->dfs(root, MIN, MAX);
    }   

private:
    bool dfs(struct TreeNode* root, long minval, long maxval)
    {
        if (nullptr == root)
        {
            return true;
        }
        // Be aware of the constraints, the maximum value of the node can be INT_MAX and the minimum value can be INT_MIN,
        // which means our "maxval" should larger than INT_MAX, and "minval" should less than INT_MIN.
        if (root->val >= maxval || root->val <= minval)
        {
            return false;
        }
        bool left = this->dfs(root->left, minval, root->val);
        bool right = this->dfs(root->right, root->val, maxval);
        return left && right;
    }
};