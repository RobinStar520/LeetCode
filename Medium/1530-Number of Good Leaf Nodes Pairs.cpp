// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.

 

// Example 1:


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
// Example 2:


// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
// Example 3:

// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].
 

// Constraints:

// The number of nodes in the tree is in the range [1, 210].
// 1 <= Node.val <= 100
// 1 <= distance <= 10

/*
Approach:
    This is a simple question, but you have to do many things. First, you need to get the common ancestor of two nodes; Second, find all the leaf nodes;
Third, calculate the distance from one leaf node to another. Last, get the final result.
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
    int countPairs(TreeNode* root, int distance) 
    {
        vector<struct TreeNode*> vct {};
        dfs(root, vct);
        int result = 0;
        const int n = vct.size();
        if (1 == n)
        {
            return 0;
        }
        for (int i=0; i<n-1; ++i)
        {
            struct TreeNode* ancestor = lowestCommonAncestor(root, vct[i], vct[i + 1]);
            // cout << ancestor->val << endl;
            int dis = findDistance(ancestor, vct[i], vct[i + 1]);
            if (dis <= distance)
            {
                result += 1;
            }
            // cout << vct[i]->val << "," <<vct[i + 1]->val << "->" << dis << endl;
        }
        return result;
        
    }

private:
    // This funtion is to get all the leaf nodes.
    void dfs(struct TreeNode* root, vector<struct TreeNode*>& vct)
    {
        if (nullptr == root)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            vct.push_back(root);
        }
        dfs(root->left, vct);
        dfs(root->right, vct);
        return;
    }

    // This function is to get the lowest common ancestor of two leaf nodes.
    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* node1, struct TreeNode* node2)
    {
        if (nullptr == root || root == node1 || root == node2)
        {
            return root;
        }
        struct TreeNode* left = lowestCommonAncestor(root->left, node1, node2);
        struct TreeNode* right = lowestCommonAncestor(root->right, node1, node2);
        if (nullptr != left && nullptr != right)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }

    // This is an auxilary function, which calcluate he distance from one node to another.
    int getDistance(struct TreeNode* root, struct TreeNode* node)
    {
        if (nullptr == root)
        {
            return -1;
        }
        if (root == node)
        {
            return 0;
        }
        int left = getDistance(root->left, node);
        int right = getDistance(root->right, node);
        int result = -1;
        if (left >= 0)
        {
            result = left + 1;
        }
        else if (right >= 0)
        {
            result = right + 1;
        }
        return result;
    }

    // Calculate the distance from the lowest common ancestor
    int findDistance(struct TreeNode* ancestor, struct TreeNode* node1, struct TreeNode* node2)
    {
        int distance1 = getDistance(ancestor, node1);
        int distance2 = getDistance(ancestor, node2);
        if (distance1 == -1 || distance2 == -1)
        {
            return -1;
        }
        return distance1 + distance2;
    }
};