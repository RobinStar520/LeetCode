// You are given some lists of regions where the first region of each list includes all other regions in that list.

// Naturally, if a region x contains another region y then x is bigger than y. Also, by definition, a region x contains itself.

// Given two regions: region1 and region2, return the smallest region that contains both of them.

// If you are given regions r1, r2, and r3 such that r1 includes r3, it is guaranteed there is no r2 such that r2 includes r3.

// It is guaranteed the smallest region exists.

 

// Example 1:

// Input:
// regions = [["Earth","North America","South America"],
// ["North America","United States","Canada"],
// ["United States","New York","Boston"],
// ["Canada","Ontario","Quebec"],
// ["South America","Brazil"]],
// region1 = "Quebec",
// region2 = "New York"
// Output: "North America"
// Example 2:

// Input: regions = [["Earth", "North America", "South America"],["North America", "United States", "Canada"],["United States", "New York", "Boston"],["Canada", "Ontario", "Quebec"],["South America", "Brazil"]], region1 = "Canada", region2 = "South America"
// Output: "Earth"
 

// Constraints:

// 2 <= regions.length <= 104
// 2 <= regions[i].length <= 20
// 1 <= regions[i][j].length, region1.length, region2.length <= 20
// region1 != region2
// regions[i][j], region1, and region2 consist of English letters.

/*
Approach:
   A difficult question! The requirement of the question is simple if you read the description of the question carefully: give two names and find 
their lowest common ancestor. Apparently, we should use a tree to store the relativities among the nodes, and we need to come up with an effective way
to find the lowest common ancestor: Traverse the tree from bottom to top started from the given node. In trees, the edges were directed. Trees are 
directed graphs. You can't access a node's parent, only its children. Once you move to a child, you can't move back.We can setan additional pointer 
that points to its parent to avoid this feature. This way, we can access a node's parent in O(1) time.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TNode
{
    string name;

    vector<struct TNode*> children {};

    struct TNode* parent;

    explicit TNode(string name): name(name), parent(nullptr) {}
};

class Solution 
{
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
    {
        struct TNode* root = buildTree(regions);
        struct TNode* pcur1 = map[region1];
        struct TNode* pcur2 = map[region2];
        
        unordered_set<string> set1 {}, set2 {};
        string result {};
        // Find the lowest common ancestor. Node the loop condition.
        while (true)
        {
            if (pcur1 == root && pcur2 == root)
            {
                break;
            }
            set1.insert(pcur1->name);
            set2.insert(pcur2->name);
            if (set2.find(pcur1->name) != set2.end())
            {
                result = pcur1->name;
                break;
            }
            if (set1.find(pcur2->name) != set1.end())
            {
                result = pcur2->name;
                break;
            }
            // Here, ensure the current pointer doesn't equal the root
            if (pcur1 != root)
            {
                pcur1 = pcur1->parent;
            }
            
            if (pcur2 != root)
            {
                pcur2 = pcur2->parent;
            }
        }

        return result;
    }

private:
    // This hashmap ensures we can access a node in O(1) time.
    unordered_map<string, struct TNode*> map {};

    struct TNode* buildTree(vector<vector<string>>& regions)
    {
        for (const auto& vct: regions)
        {
            for (const auto& name: vct)
            {
                if (this->map.find(name) == this->map.end())
                {
                    this->map[name] = new struct TNode(name);
                }
            }
        }
        struct TNode* root = new struct TNode("11111111");
        for (const auto& vct: regions)
        {
            const int n = vct.size();
            if (root->children.empty())
            {
                root->children.push_back(map[vct[0]]);
                map[vct[0]]->parent = root;
            }
            struct TNode* parent = map[vct[0]];
            for (int i=1; i<n; ++i)
            {
                struct TNode* child = map[vct[i]];
                map[vct[i]]->parent = parent;
                parent->children.push_back(child);
            }

        }
        return root;
    }

};