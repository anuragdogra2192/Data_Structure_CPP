/** Leet Code 20.
 
 * 20. Valid Parentheses - Interview Question (highly important) 
 * 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket
of the same type.

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            
            //ch -> open / close bracket
            //if open -> then push in stack
            //if close -> stack ke top pe check karo ki isak 'open' bracket hai ya nahi.

            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {//Close bracket mila hai
             //ch == ')' || ch == ']' || ch == '}'
             // the stack ke top ko check karo ki usme correct open bracket hai ya nahi.
                if(ch  == ')' && !st.empty() && st.top() == '(')
                {//Bracket match
                    st.pop();
                }
                else if(ch == ']' && !st.empty() && st.top() == '[')
                {//Bracket match
                    st.pop();
                }
                else if(ch == '}' && !st.empty() && st.top() == '{')
                {//Bracket match
                    st.pop();
                }
                else
                {//bracket not matching
                    return false;
                }
            }
        }  
        if(st.empty())
        {
            return true;
        }    
        return false;
    }
};