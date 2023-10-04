// HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

// The special characters and their entities for HTML are:

// Quotation Mark: the entity is &quot; and symbol character is ".
// Single Quote Mark: the entity is &apos; and symbol character is '.
// Ampersand: the entity is &amp; and symbol character is &.
// Greater Than Sign: the entity is &gt; and symbol character is >.
// Less Than Sign: the entity is &lt; and symbol character is <.
// Slash: the entity is &frasl; and symbol character is /.
// Given the input text string to the HTML parser, you have to implement the entity parser.

// Return the text after replacing the entities by the special characters.

 

// Example 1:

// Input: text = "&amp; is an HTML entity but &ambassador; is not."
// Output: "& is an HTML entity but &ambassador; is not."
// Explanation: The parser will replace the &amp; entity by &
// Example 2:

// Input: text = "and I quote: &quot;...&quot;"
// Output: "and I quote: \"...\""
 

// Constraints:

// 1 <= text.length <= 105
// The string may contain any possible characters out of all the 256 ASCII characters.

/*
Approach:
    We can use a hashmap to store all the entities, and then use string matching to replace them.
*/

#include <unordered_map>
#include <string>

using namespace std;

class Solution 
{
public:
    string entityParser(string text) 
    {
        string result {};
        unordered_map<string, char> _map {
            {"&quot;", '"'}, {"&apos;", '\''}, {"&amp;", '&'}, {"&gt;", '>'},
            {"&lt;", '<'}, {"&frasl;", '/'}
        };
        const int n = text.length();
        for (int i=0; i<n; ++i)
        {
            if (text[i] == '&')
            {
                int index = text.find_first_of(';', i);
                string sub = text.substr(i, index - i + 1);
                // We replace the character only when the entity is in the hashmap.
                if (_map.find(sub) != _map.end())
                {
                    result.push_back(_map[sub]);
                    i = index;
                }
                else
                {
                    result.push_back(text[i]);
                }
            }
            else
            {
                result.push_back(text[i]);
            }
        }

        return result;
    }
};