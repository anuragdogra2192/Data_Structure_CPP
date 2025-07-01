/* Leet Code: 1003
1003. Check If Word Is Valid After Substitutions

Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.

Example 1:

Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
Example 2:

Input: s = "abcabcababcc"
Output: true
Explanation:
"" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
Thus, "abcabcababcc" is valid.
Example 3:

Input: s = "abccba"
Output: false
Explanation: It is impossible to get "abccba" using the operation.
 

Constraints:

1 <= s.length <= 2 * 104
s consists of letters 'a', 'b', and 'c'
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
    public:
    bool isValid1(string s)
    {  //Using stack and Time Complexity: O(n)
        int n = s.size();
        if(s[0] != 'a' && s[n-1]=='c')
        {
            return false;
        }
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(ch == 'a')
            {
                st.push(ch);
            }
            else if(ch == 'b')
            {
                if(!st.empty() && st.top() == 'a')
                {
                    st.push(ch);
                }
                else
                {
                    return false;
                }
            }
            else
            {//ch == 'c'
                if(!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    if(!st.empty() && st.top() == 'a')
                    {
                        st.pop(); //"abc" pair found. popped "abc" pair
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
    
    bool isValid2(string s) {
    //Using Recursion
    //This solution is slow.
    //Time Complexity: Find and Substring - 3*O(n) * Recursive calls: O(n/3)
    //T.C. O(n^2)
        if(s.size() == 0)
        {
            return true;
        }

        int fnd = s.find("abc");//O(n)
        if(fnd != string::npos)
        {
            //found
            string tleft = s.substr(0, fnd);//O(n)
            string tright = s.substr(fnd+3, s.size()); //+3 for abc //O(n)
            return isValid2(tleft+tright);
        }
        return false;
    }

    //This solution is slow.
    //Time Complexity: Find and Substring - 3*O(n) * Recursive calls: O(n/3)
    //T.C. O(n^2)   
    bool isValid(string s) {
        //return isValid2(s);
        return isValid1(s);
    }
};