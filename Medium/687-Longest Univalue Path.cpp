// Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

// The length of the path between two nodes is represented by the number of edges between them.

 

// Example 1:


// Input: root = [5,4,5,1,1,null,5]
// Output: 2
// Explanation: The shown image shows that the longest path of the same value (i.e. 5).
// Example 2:


// Input: root = [1,4,5,4,4,null,5]
// Output: 2
// Explanation: The shown image shows that the longest path of the same value (i.e. 4).
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
// The depth of the tree will not exceed 1000.

/*
Approach:
    For this question, we need to find the longest path that satisfies the condition. We can't use the pre-order traverse since it can't backtrack 
the nodes. So, we should use the post-order traverse to find all the possibilities.
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
    int longestUnivaluePath(TreeNode* root) 
    {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
   int dfs(struct TreeNode* root, int& result)
   {
       if (nullptr == root)
       {
           return 0;
       }
       int left = dfs(root->left, result);
       int right = dfs(root->right, result);
       int leftLen = 0, rightLen = 0;
       if (root->left != nullptr && root->left->val == root->val)
       {
           leftLen = left + 1;
       }
       if (root->right != nullptr && root->right->val == root->val)
       {
           rightLen = right + 1;
       }
       result = std::max(result, leftLen + rightLen);
       return std::max(leftLen, rightLen);
   }
  
};