// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// For example, you may serialize the following 3-ary tree


 

// as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.

// Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.


 

// For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

// You do not necessarily need to follow the above-suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.

 

// Example 1:

// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Example 2:

// Input: root = [1,null,3,2,4,null,5,6]
// Output: [1,null,3,2,4,null,5,6]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The height of the n-ary tree is less than or equal to 1000
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.

/*
Approach:
    In question 536-Construct Binary Tree from String, we can build a binary from a pre-order traversal sequence. So as long as we can convert the 
tree to a pre-order traversal string format, this question will be solved. This is a series of question. If you understand the process of this question
you can solve the similar question easily, like 297-Serialize and Deserialize Binary Tree.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <string>
#include <unordered_map>

using namespace std;

class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) 
    {
        return toString(root);
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) 
    {
        if (data.empty())
        {
            return nullptr;
        }
        unordered_map<int, Node*> _map {};
        int level = 1;
        int index = data.find_first_of('(');
        if (index == string::npos)
        {
            return new Node(stoi(data));
        }
        struct Node* root = new Node(stoi(data.substr(0, index)));
        _map[0] = root;
        for (int i=index+1; i<data.length(); ++i)
        {
            int j = i;
            if (std::isdigit(data[i]))
            {
                while (std::isdigit(data[j]))
                {
                    j ++;
                }
                Node* node = new Node(stoi(data.substr(i,j-i)));
                _map[level] = node;
                _map[level - 1]->children.push_back(node);
                // cout << data.substr(i, j - i) << endl; 
                i = j - 1;
            }
            else if (data[i] == '(')
            {
                level ++;
            }
            else
            {
                level --;
            }
        }
        return root;
    }

private:
    // use pre-order traversal to convert the tree to string format.
    string toString(Node* root)
    {
        if (nullptr == root)
        {
            return {};
        }
        string result = to_string(root->val);
        for (int i=0; i<root->children.size(); ++i)
        {
            result += "(" + toString(root->children[i]) + ")";
            
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));