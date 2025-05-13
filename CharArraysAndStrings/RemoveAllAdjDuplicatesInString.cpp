/* Leet Code -  1047
1047. Remove All Adjacent Duplicates In String

You are given a string s consisting of 
lowercase English letters. 
A duplicate removal consists of choosing two adjacent and 
equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the 
letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, 
so the final string is "ca".

Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        string removeDuplicatesMethod1(string s)
        {
            string ans = "";
            for(int i=0; i<s.length(); i++)
            {
                if(ans.empty() || (ans.back() != s[i]))
                {      
                    ans.push_back(s[i]);
                }
                else
                {
                    ans.pop_back();
                }
            }
            return ans;
        }
    
        string removeDuplicatesMethod2(string s) {
            int i = 0;
            int j = 1;
            while(s.length()>0 && j<s.length())
            {
                if(s[i]!= s[j])
                { 
                    i++;
                    j++;
                }
                else
                {
                    s.erase(i,2);
    
                    if(i>0)
                    {
                        i--;
                        j--;
                    }
    
                }
            }
            return s;        
        }
    
        string removeDuplicates(string s) {
            return removeDuplicatesMethod1(s);
            //return removeDuplicatesMethod2(s);
        }
    
    };