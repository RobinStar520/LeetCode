// Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Example 2:


// Input: root = [3,9,8,4,0,1,7]
// Output: [[4],[9],[3,0,1],[8],[7]]
// Example 3:


// Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
// Output: [[4],[9,5],[3,0,1],[8,2],[7]]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

/*
Approach:
    This question is similar to the question 987. The only difference is that we don’t need to sort the nodes for this problem.
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
#include <utility>
#include <limits>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        int maxval = numeric_limits<int>::min();
        int minval = numeric_limits<int>::max();
        vector<vector<pair<struct TreeNode*, pair<int,int>>>> layers {};
        vector<vector<int>> result {};
        bfs(root, layers, minval, maxval);
        for (int i=minval; i<=maxval; ++i)
        {
            vector<int> item {};
            for (const auto& v: layers)
            {
                for (const auto& p: v)
                {
                    if (p.second.second == i)
                    {
                        item.push_back(p.first->val);
                    }
                }
            }
            
            result.push_back(item);
        }
        
        return result;
    }

private:
    void bfs(struct TreeNode* root, vector<vector<pair<struct TreeNode*, pair<int,int>>>>& layers, int& minval, int& maxval)
    {
        if (nullptr == root)
        {
            return;
        }
        queue<pair<struct TreeNode*, pair<int,int>>> q{};
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            int n = q.size();
            vector<pair<struct TreeNode*, pair<int,int>>> layer {};
            while (n --)
            {
                auto p = q.front();
                q.pop();
                minval = std::min(minval, p.second.second);
                maxval = std::max(maxval, p.second.second);
                layer.push_back(p);
                if (p.first->left != nullptr)
                {
                    q.push({p.first->left, make_pair(p.second.first + 1, p.second.second - 1)});
                }
                if (p.first->right != nullptr)
                {
                    q.push({p.first->right, make_pair(p.second.first + 1, p.second.second + 1)});
                }
            }
            layers.push_back(layer);
        }
    }
};