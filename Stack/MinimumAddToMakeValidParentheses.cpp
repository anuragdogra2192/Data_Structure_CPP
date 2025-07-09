/** Leet Code 921. 
921. Minimum Add to Make Parentheses Valid

Interview 

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.

Time Complexity: O(n)
Space Complexity: O(n)
 */

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;

        for(char ch : s)
        {
            if(ch == '(')
            {//means this requires a ')' to become valid
                ans++;//moves ++
                st.push(ch);
            }
            else//ch == ')'
            {
                if(!st.empty())
                {//Means there is/are '(' available
                    st.pop();
                    ans--; //moves --
                }
                else
                {//If stack is empty and ')'
                //means we need a extra move to make it valid.
                    ans++;
                    //Definitely there is no point in Pushing ')'
                    //in stack.
                }
            }
        }
        return ans;
    }
};