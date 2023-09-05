// Given the root of a binary tree, find the largest 
// subtree
// , which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

// A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

// The left subtree values are less than the value of their parent (root) node's value.
// The right subtree values are greater than the value of their parent (root) node's value.
// Note: A subtree must include all of its descendants.

 

// Example 1:



// Input: root = [10,5,15,1,8,null,7]
// Output: 3
// Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
// Example 2:

// Input: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -104 <= Node.val <= 104
 

// Follow up: Can you figure out ways to solve it with O(n) time complexity?

/*
Approach:
    We can use two DFSs: First DFS is to judge whether a subtree is a binary search tree and get the number of the tree's nodes; Second DFS used to 
get the maximum number of nodes that the sub-binary search tree has.
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
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();

class Solution 
{
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        int result = 0;
        this->dfs(root, result);
        return result;
    }

private:
    // Here I use a pair as the return value of the function since the pair objet consumes less memory. You can use a vector as well.
    pair<bool, int> isValid(struct TreeNode* root, int minval, int maxval)
    {
        if (nullptr == root)
        {
            return make_pair(true, 0);
        }

        auto left = isValid(root->left, minval, root->val);
        auto right = isValid(root->right, root->val, maxval);

        bool valid = (root->val > minval) && (root->val < maxval);


        int totalCount = 1 + left.second + right.second;

        valid = valid && left.first && right.first;
        return make_pair(valid, totalCount);
    }

    void dfs(struct TreeNode* root, int& result)
    {
        if (nullptr == root)
        {
            return;
        }
        auto p = this->isValid(root, MIN, MAX);
        if (p.first == true)
        {
            result = std::max(p.second, result);
        }
        this->dfs(root->left, result);
        this->dfs(root->right, result);
        return;
    }
};