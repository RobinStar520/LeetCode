// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

// If a folder[i] is located within another folder[j], it is called a sub-folder of it.

// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

// For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 

// Example 1:

// Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
// Output: ["/a","/c/d","/c/f"]
// Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
// Example 2:

// Input: folder = ["/a","/a/b/c","/a/b/d"]
// Output: ["/a"]
// Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
// Example 3:

// Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
// Output: ["/a/b/c","/a/b/ca","/a/b/d"]
 

// Constraints:

// 1 <= folder.length <= 4 * 104
// 2 <= folder[i].length <= 100
// folder[i] contains only lowercase letters and '/'.
// folder[i] always starts with the character '/'.
// Each folder name is unique.

/*
Approach:
    Sort the folders lexicographically, and insert the current element in an array and then loop until we get rid of all of their subfolders, 
repeat this until no element is left.
*/

#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        unordered_set<string> _set {};
        sort(folder.begin(), folder.end());
        for (const auto& str: folder)
        {
            string temp {};
            bool flag = true;
            for (int i=0; i<str.length(); ++i)
            {
                if (str[i] == '/')
                {
                    if (_set.find(temp) != _set.end())
                    {
                        flag = false;
                        break;
                    }
                    
                }
                temp += str[i];
            }
            if (flag == true)
            {
                _set.insert(temp);
            }
        }
        return vector<string>(_set.begin(), _set.end());
    }
};