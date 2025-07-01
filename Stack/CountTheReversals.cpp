/** Geek for Geeks:

Count the Reversals

Given a string s consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression. A reversal means changing '{' to '}' or vice-versa.

Examples:

Input: s = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Input: s = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Constraints:
1 ≤ |s| ≤ 105

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        stack<char> st;
        int n = s.length();
        int ans = 0;
        
        if(n%2==1)//odd length: Impossible to store pairs.
        {
            return -1;
        }
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(ch == '{')
            {
                st.push(ch);
            }
            else 
            {
                if (!st.empty() && st.top() == '{')
                {//char == '}'
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
        
        //Now if the stack is not empty then we have to do the reversal.
        while(!st.empty())
        {
            char a = st.top(); 
            st.pop();
            char b = st.top(); 
            st.pop();
            
            if(a == b)//same }} or {{ 
            {
                ans+=1;
            }
            else//if(a!=b)//diff: }{
            {
                ans+=2;
            }
        }
        return ans;
    }
};
