// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

// You always start to construct the left child node of the parent first if it exists.

 

// Example 1:


// Input: s = "4(2(3)(1))(6(5))"
// Output: [4,2,6,3,1,5]
// Example 2:

// Input: s = "4(2(3)(1))(6(5)(7))"
// Output: [4,2,6,3,1,5,7]
// Example 3:

// Input: s = "-4(2(3)(1))(6(5)(7))"
// Output: [-4,2,6,3,1,5,7]
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s consists of digits, '(', ')', and '-' only.

/*
Approach:
    We can construct this tree level by level.
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

#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    TreeNode* str2tree(string s) 
    {
        if (s.empty())
        {
            return nullptr;
        }
        int level = 0;
        // level -> node(address)
        unordered_map<int, struct TreeNode*> _map {};
        int index = s.find_first_of('(');
        if (index == string::npos)
        {
            struct TreeNode* root = new struct TreeNode(stoi(s));
            return root;
        }
        int val = stoi(s.substr(0, index));
        struct TreeNode* root = new struct TreeNode(val);
        _map[level] = root;
        const int n = s.length();
        level += 1;
        
        for (int i=index+1; i<n; ++i)
        {
           if (s[i] == '-' || std::isdigit(s[i]))
           {
               int j = i;
               
               for (j=i+1; j<n; ++j)
               {
                   if (!std::isdigit(s[j]))
                   {
                       break;
                   }
               }
               int val = stoi(s.substr(i, j-i));
               
               struct TreeNode* node = new struct TreeNode(val);
               _map[level] = node;
               int curLevel = level;
               if (_map[curLevel - 1]->left == nullptr)
               {
                   _map[curLevel - 1]->left = node;
               }
               else
               {
                   _map[curLevel - 1]->right = node;
               }
               i = j - 1;
           }
           else if (s[i] == '(')
           {
               level += 1;
           }
           else if (s[i] == ')')
           {
               level -= 1;
           }
        }
        return root;
    }
};