// Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

 

// Example 1:

// Input: root = [2,1,3]
// Output: [2,1,3]
// Example 2:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The input tree is guaranteed to be a binary search tree.

/*
Approach:
    For this question, we can divide it into two part: serialize and deserialize. For the first part, we can save a copy of he level-oerder traversal.
Of course, you can save a pre-order traversal sequence and a in-order traversal sequence as well, but it will use more memory to store and more time to
parse. Suppose you use the first way to save a binary search tree in string format like this: "2,1,3" how to recover it?
    Obviously, the first number of the sequence is the root's value. Traverse the sequence from index one, and insert a new node to the root.
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
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string result = bfs(root);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data.empty())
        {
            return nullptr;
        }
        stringstream ss(data);
        string str {};
        vector<int> seq {};
        while (getline(ss, str, ','))
        {
            seq.push_back(stoi(str));
        }
        const int n = seq.size();
        struct TreeNode* root = new struct TreeNode(seq.front());
        for (int i=1; i<n; ++i)
        {
            root = insert(root, seq[i]);
        }
        return root;
    }

private:
    string bfs(struct TreeNode* root)
    {
        if (nullptr == root)
        {
            return {};
        }
        string result {};
        queue<struct TreeNode*> q {};
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                struct TreeNode* node = q.front();
                q.pop();
                result += to_string(node->val) + ",";
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        result.pop_back();
        return result;
    }

    struct TreeNode* insert(struct TreeNode* root, int val)
    {
        if (nullptr == root)
        {
            return new struct TreeNode(val);
        }
        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }
        if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;