// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.
// Example 2:


// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.
// Example 3:


// Input: root = [1,2,3,4,6,5,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// This case is the exact same as example 2, but with nodes 5 and 6 swapped.
// Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 0 <= Node.val <= 1000

/*
Approach:
    This question is similar to question 314-Binary Tree Vertical Order Traversal. To solve this question, we can mark each tree node and traverse 
the tree via their coordinates. Note that we cannot directly sort the values of nodes.
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
#include <algorithm>

using namespace std;

struct Comp
{
public:
    bool operator()(const pair<struct TreeNode*, pair<int, int>>& p1, const pair<struct TreeNode*, pair<int, int>>& p2) const
    {
        bool res = true;
        if (p1.second == p2.second)
        {
            res = p1.first->val < p2.first->val;
        }
        else
        {
            res = p1.second < p2.second;
        }
        return res;
    }
};

class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> result {};
        vector<vector<pair<struct TreeNode*, pair<int, int>>>> layers {};
        int maxval = numeric_limits<int>::min();
        int minval = numeric_limits<int>::max();
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
            // Note: We can't sort the vector here.
            result.push_back(item);
        }
        return result;
    }

private:
    // We use a level-order traverse to mark the nodes
    // pair<int, int> denotes row and column.
    void bfs(struct TreeNode* root, vector<vector<pair<struct TreeNode*, pair<int, int>>>>& layers, int& minval, int& maxval)
    {
        if (nullptr == root)
        {
            return;
        }
        queue<pair<struct TreeNode*, pair<int, int>>> q {};
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty())
        {
            int n = q.size();
            vector<pair<struct TreeNode*, pair<int, int>>> layer {};
            while (n --)
            {
                auto p = q.front();
                q.pop();
                layer.push_back(p);
                minval = std::min(minval, p.second.second);
                maxval = std::max(maxval, p.second.second);
                if (p.first->left != nullptr)
                {
                    q.push({p.first->left, {p.second.first + 1, p.second.second - 1}});
                }
                if (p.first->right != nullptr)
                {
                    q.push({p.first->right, {p.second.first + 1, p.second.second + 1}});
                }
            }
            sort(layer.begin(), layer.end(), Comp());
            layers.push_back(layer);
        }
        return;
    }
};