/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), 
implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

Time Complexity: O(2^n) -> exponential
Space Complexity: O(n)

Time limit exceeded, we will improve it using dp.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatchHelper(string& s, int si, string& p, int pi)
    {
        //base case
        if(si == s.size() && pi==p.size())
        {//Means all chars are matched 
            return true;
        }
        if(si == s.size() && pi < p.size())
        {//si is out of bound and pi still inbound
         //Therefore we need to check if all the remaining chars in p are '*' or not.
            while(pi < p.size())
            {
                if(p[pi] != '*')
                {
                    return false;
                }
                pi++;
            }
            return true;
        }


        //Single char matching
        if((s[si] == p[pi]) || (p[pi] == '?'))
        {
            return isMatchHelper(s, si+1, p, pi+1);
        }

        if(p[pi] == '*')
        {
            //Case A: treat * as null or "", means pi ko +1 kardo
            bool caseA = isMatchHelper(s, si, p, pi+1);

            //Case B: Lets * consume one char of s, means si ko +1 kardo
            bool caseB = isMatchHelper(s, si+1, p, pi);

            return caseA || caseB;
        }

        //Char doesnot match in s[si] and p[pi]
        return false;
    }

    bool isMatch(string s, string p) {
        int si = 0; // index to iterate over string s 
        int pi = 0; // index to iterate over string p   
        return isMatchHelper(s, si, p, pi);
    }
};