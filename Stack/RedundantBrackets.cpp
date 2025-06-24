/** Geek for Geeks:

    Expression contains redundant bracket or not

Given a string of balanced expression str, find if it contains 
a redundant parenthesis or not. 
A set of parenthesis are redundant if the same sub-expression is surrounded
by unnecessary or multiple brackets. 
Return 1 ifit contains a redundant parenthesis, else 0.
Note: Expression may contain + , - , *, and / operators. 
Given expression is valid and there are no white spaces present.

Example 1:

Input:
exp = ((a+b))
Output:
Yes
Explanation:
((a+b)) can reduced to (a+b).
Example 2:

Input:
exp = (a+b+(c+d))
Output:
No
Explanation:
(a+b+(c+d)) doesn't have any redundant or multiple
brackets.
Your task:
You don't have to read input or print anything. Your task is to complete the function checkRedundancy() which takes the string s as input and returns 1 if it contains redundant parentheses else 0.

Constraints:
1<=|str|<=104

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
 */

#include<iostream>
#include<stack>
using namespace std;

 class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        int redundant = 0;
        bool op = false;
        for(int i = 0; i<s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
            {
                st.push(ch);
            }
            else
            {
                if(ch == ')' && !st.empty() && st.top() != '(')
                {
                    //means operators hai
                    //We will pop till we find the '('
                    while(!st.empty() && st.top() != '(')
                    {
                        st.pop();
                    }
                    //Here means top -> '('
                    //poping the '('
                    st.pop();
                }
                else if(ch == ')' && !st.empty() && st.top() == '(') 
                {
                    redundant++;
                    st.pop();
                }
            }
        }
        if(redundant > 0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Time Complexity:
The function iterates through the string once, 
and each stack operation (push/pop) is O(1).
Each character is pushed and popped at most once.
Total Time Complexity:
O(N), where N is the length of the string.

Space Complexity
The stack stores at most O(N) characters 
(in the worst case, all are operators and parentheses).

Total Space Complexity: O(N)

Summary:
Time Complexity: O(N)
Space Complexity: O(N)
*/
