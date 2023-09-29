// Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

// A group of duplicate files consists of at least two files that have the same content.

// A single directory info string in the input list has the following format:

// "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
// It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

// The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

// "directory_path/file_name.txt"
 

// Example 1:

// Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
// Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
// Example 2:

// Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
// Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 

// Constraints:

// 1 <= paths.length <= 2 * 104
// 1 <= paths[i].length <= 3000
// 1 <= sum(paths[i].length) <= 5 * 105
// paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
// You may assume no files or directories share the same name in the same directory.
// You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.
 
/*
Approach:
    We can use a hashmap to store file content and file path. Pay attention to the separation of a file path.
*/

#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
        vector<vector<string>> result {};
        // content -> full_path
        unordered_map<string, vector<string>> _map {};
        for (const auto& str: paths)
        {
            stringstream ss(str);
            string item {};
            vector<string> temp {};
            while (getline(ss, item, ' '))
            {
                temp.push_back(item);
            }
            string path = temp.front();
            for (int i=1; i<temp.size(); ++i)
            {
                int index = temp[i].find_first_of('(');
                string content = temp[i].substr(index+1);
                content.pop_back();
                _map[content].push_back(temp.front() + "/" + temp[i].substr(0, index));
            }
        }
        for (const auto& [key, value]: _map)
        {
            // Only the vector's length is more than one, which means the vector contains duplicated files, we add to the final result.
            if (value.size() > 1)
            {
                result.push_back(value);
            }
        }
        return result;
    }
};