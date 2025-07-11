/**
 * Leet Code 1047.
1047. Remove All Adjacent Duplicates In String
Solved
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"

Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicatesMethod3(string s)
    {//Using Stack.
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(!st.empty() && ch == st.top())
            {
                st.pop();
            }
            else {
                st.push(ch);
            }   
        }
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string removeDuplicates(string s) {
        return removeDuplicatesMethod3(s);
    }
};