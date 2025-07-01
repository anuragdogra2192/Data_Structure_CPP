/** Leet Code:
 * 1963. Minimum Number of Swaps to Make the String Balanced
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.
Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

Time Complexity: O(N)
Space Complexity: O(N)
*/
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n = s.length();//n is always even, no need to check
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(ch == '[')
            {
                st.push(ch);    
            }
            else
            {
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else 
                {
                    st.push(ch);
                } 
            }
        }
        //Outside of for loop
        //If stack is not empty, then we need to do swaps.
        while(!st.empty())
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();    
            if(a == b) //'[[' or ']]'
            {
                ans += 1;
            }
            else// ']['
            {
                ans += 2;
            }
        }
        return ans/2;// divide by 2 to get no. of swaps.
    }
};