// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:


// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 8

/*
Apprpach:
    Our first impression of this question may be tricky. How do you insert and save the node? Actually, If we look at the example test cases carefully,
we can find that the different value of the root has different results. For example, for sequence [1, 2, 3], each number in the sequence can be the root of 
the binary search tree. So we can find the permutation of the sequence, and build a corresponding binary search tree. This method can't avoid the duplicated
trees, so we need an additional function to remove them.
    Note: this is not an effective approach since its essence is a brute-force algorithm.
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
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<int> vct {};
        vector<struct TreeNode*> result {};
        unordered_set<string> _set {};
        for (int i=1; i<=n; ++i)
        {
            vct.push_back(i);
        }
        do
        {
            struct TreeNode* root = new struct TreeNode(vct.front());
            string str {};
            for (int i=1; i<n; ++i)
            {
                root = buildBST(root, vct[i]);
            }
            dfs(root, str);
            if (_set.find(str) == _set.end())
            {
                result.push_back(root);
            }
            _set.insert(str);
            // cout << str << endl;
            
        }
        while (next_permutation(vct.begin(), vct.end()));
        return result;
    }

private:
    // The essence of this function is adding a new tree node to a existing tree.
    struct TreeNode* buildBST(struct TreeNode* root, int val)
    {
        if (nullptr == root)
        {
            return new struct TreeNode(val);
        }
        
        if (val < root->val)
        {
            root->left = buildBST(root->left, val);
        }
        if (val > root->val)
        {
            root->right = buildBST(root->right, val);
        }
        return root;
    }

    // This function is to add a unique "label" for every binary search tree.
    // We can't use the in-order traversal because of the property of the binary search tree.
    void dfs(struct TreeNode* root, string& str)
    {
        if (nullptr == root)
        {
            return;
        }
        str += to_string(root->val);
        dfs(root->left, str);
        dfs(root->right, str);
        return;
    }
};