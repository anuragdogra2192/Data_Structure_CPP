/** Leet code 71.
 * 71. Simplify Path
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

Time Complexity
The code iterates through the input string path once: O(N), where N is the length of the path.
Each directory name is pushed/popped from the stack at most once: O(N) stack operations in total.
The buildAns function pops all elements from the stack and appends them to the answer string: O(N).
Total Time Complexity:
O(N)
*/
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void buildAns(stack<string>&st, string& ans)
    {//Tail Recursion,
        if(st.empty())
        {
            return;
        }
        string minPath = st.top();
        st.pop();
        buildAns(st, ans);
        ans += minPath; 
    }

    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i < path.size())
        {
            int start = i;
            int end = i+1;
            while(end<path.size() && path[end] != '/')
            {
                ++end;
            }
            string minPath = path.substr(start, end-start);//length = end - start;
            i = end;// after end
            if(minPath == "/" || minPath == "/.")
            {
                continue;
            }
            if(minPath != "/..")
            {
                st.push(minPath);
            }
            else if(!st.empty() && minPath == "/..")
            {
                cout<<"Anurag"<<endl;
                cout<<st.top();
                st.pop();
            }
        }
        string ans = st.empty() ? "/" : ""; //empty means at / or say root dir
        buildAns(st, ans);
        return ans;
    }
};