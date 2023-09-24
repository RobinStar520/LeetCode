// Given a 0-indexed integer 2D array nodes, your task is to determine if the given array represents the preorder traversal of some binary tree.

// For each index i, nodes[i] = [id, parentId], where id is the id of the node at the index i and parentId is the id of its parent in the tree (if the node has no parent, then parentId = -1).

// Return true if the given array represents the preorder traversal of some tree, and false otherwise.

// Note: the preorder traversal of a tree is a recursive way to traverse a tree in which we first visit the current node, then we do the preorder traversal for the left child, and finally, we do it for the right child.

 

// Example 1:

// Input: nodes = [[0,-1],[1,0],[2,0],[3,2],[4,2]]
// Output: true
// Explanation: The given nodes make the tree in the picture below.
// We can show that this is the preorder traversal of the tree, first we visit node 0, then we do the preorder traversal of the right child which is [1], then we do the preorder traversal of the left child which is [2,3,4].


// Example 2:

// Input: nodes = [[0,-1],[1,0],[2,0],[3,1],[4,1]]
// Output: false
// Explanation: The given nodes make the tree in the picture below.
// For the preorder traversal, first we visit node 0, then we do the preorder traversal of the right child which is [1,3,4], but we can see that in the given order, 2 comes between 1 and 3, so, it's not the preorder traversal of the tree.


 

// Constraints:

// 1 <= nodes.length <= 105
// nodes[i].length == 2
// 0 <= nodes[i][0] <= 105
// -1 <= nodes[i][1] <= 105
// The input is generated such that nodes make a binary tree.

/*
Approach:
    This is a very common question. Although the question doesn't declare that the value of each node is unique, we should know that this condition is satisfied.
Otherwise, some duplicated values will cover some existing nodes, and it's ambiguous. So we can use an auxliary hashmap to build the tree.
*/

#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
public:
    int val;

    struct Node* left;

    struct Node* right;

    explicit Node(int val): val(val), left(nullptr), right(nullptr) {}
};


class Solution 
{
public:
    bool isPreorder(vector<vector<int>>& nodes) 
    {
        unordered_map<int, struct Node*> _map {};
        vector<int> seq {};
        // The variable root_mark recode the root value.
        int root_mark = -1;
        // Start to build a binary tree.
        for (const auto& v: nodes)
        {
            int child = v[0], parent = v[1];
            if (parent == -1)
            {
                root_mark = child;
            }
            seq.push_back(child);
            if (_map.find(child) == _map.end())
            {
                struct Node* pchild = new struct Node(child);
                _map[child] = pchild;
                if (_map.find(parent) == _map.end())
                {
                    struct Node* pparent = new struct Node(parent);
                    _map[parent] = pparent;
                    pparent->left = pchild;
                }
                else
                {
                    struct Node* pparent = _map[parent];
                    if (pparent->left == nullptr)
                    {
                        pparent->left = pchild;
                    }
                    else if (pparent->right == nullptr)
                    {
                        pparent->right = pchild;
                    }
                }
            }
            else
            {
                struct Node* pchild = _map[child];
                if (_map.find(parent) == _map.end())
                {
                    struct Node* pparent = new struct Node(parent);
                    _map[parent] = pparent;
                    pparent->left = pchild;
                }
                else
                {
                    struct Node* pparent = _map[parent];
                    if (pparent->left == nullptr)
                    {
                        pparent->left = pchild;
                    }
                    else if (pparent->right == nullptr)
                    {
                        pparent->right = pchild;
                    }
                }
            }
        }

        vector<int> pre_order {};
        dfs(_map[root_mark], pre_order);
        
        return pre_order == seq;
    }

private:
    // Pre-order traverse.
    void dfs(Node* root, vector<int>& vct)
    {
        if (nullptr == root)
        {
            return;
        }
        vct.push_back(root->val);
        dfs(root->left, vct);
        dfs(root->right, vct);
        return;
    }
};