/* Leet Code 44.
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

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
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool solveRec(string& s, int si, string& p, int pi)
    {
        //base case
        if(si == s.size() && pi==p.size())
        {//Means all chars are matched 
            return true;
        }
        if(pi == p.size() && si < s.size())
        {//pattern lhatam ho gaya hai but s bacha hai, matlab pattern galat hai
            return false;
        }

        if(si == s.size() && pi < p.size())
        {//si is out of bound and pi is still inbound
         //Therefore we need to check if all the remaining chars in p are '*' or not 
            while(pi < p.size())
            {
                if(p[pi] != '*')
                {
                    return false;
                }
                pi++;
            }
            //if we are here, all chars are *
            return true;
        }
        //Main logic. 
        //Single char matching
        if((s[si] == p[pi]) || (p[pi] == '?'))
        {
            return solveRec(s, si+1, p, pi+1);
        }
        
        if(p[pi] == '*')
        {   //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai. Lets take both cases
            
            //Case A: treat * as null or "", means pi ko +1 kardo
            bool caseA = solveRec(s, si, p, pi+1);

            //Case B: Lets * consume one char of s, means si ko +1 kardo
            bool caseB = solveRec(s, si+1, p, pi);

            return caseA || caseB;
        }

        //No match
        //Char doesnot match in s[si] and p[pi]
        return false;
    }
    
    bool solveMem(string& s, int si, string& p, int pi, vector<vector<int> >& dp)
    {
        //base case
        if(si == s.size() && pi==p.size())
        {//Means all chars are matched 
            return true;
        }
        if(pi == p.size() && si < s.size())
        {//pattern lhatam ho gaya hai but s bacha hai, matlab pattern galat hai
            return false;
        }

        if(si == s.size() && pi < p.size())
        {//si is out of bound and pi is still inbound
         //Therefore we need to check if all the remaining chars in p are '*' or not 
            while(pi < p.size())
            {
                if(p[pi] != '*')
                {
                    return false;
                }
                pi++;
            }
            //if we are here, all chars are *
            return true;
        }

        if(dp[si][pi] != -1)
        {
            return dp[si][pi];
        }

        //Main logic. 
        //Single char matching
        bool ans;
        if((s[si] == p[pi]) || (p[pi] == '?'))
        {
            ans = solveMem(s, si+1, p, pi+1, dp);
        }
        else if(p[pi] == '*')
        {   //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai. Lets take both cases
            
            //Case A: treat * as null or "", means pi ko +1 kardo
            bool caseA = solveMem(s, si, p, pi+1, dp);

            //Case B: Lets * consume one char of s, means si ko +1 kardo
            bool caseB = solveMem(s, si+1, p, pi, dp);

            ans = caseA || caseB;
        }
        else
        {
            //No match
            //Char doesnot match in s[si] and p[pi]
            ans = false;
        }
        dp[si][pi] = ans;
        return dp[si][pi];
    }

    bool solveTab(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        dp[m][n] = true;
        //s ka index is out of bound, means col == m and p ka index is still inbound
        //Therefore we need to check if all the remaining chars in p are '*' or not 
        for(int col = 0; col < n; col++)
        {
            int j = col;
            bool flag = true;
            while(j < p.size())
            { 
                if(p[j] != '*')
                {
                    flag = false;
                    break;
                }
                j++;
            }
            //if we are here, all chars are *
            dp[m][col] = flag;
        }

        for(int si = m-1; si>=0; si--)
        {
            for(int pi = n; pi>=0; pi--)
            {
                bool ans;
                if((s[si] == p[pi]) || (p[pi] == '?'))
                {
                    ans = dp[si+1][pi+1];
                }
                else if(p[pi] == '*')
                {   //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai. Lets take both cases
                    
                    //Case A: treat * as null or "", means pi ko +1 kardo
                    bool caseA = dp[si][pi+1];

                    //Case B: Lets * consume one char of s, means si ko +1 kardo
                    bool caseB = dp[si+1][pi];
                    ans = caseA || caseB;
                }
                else
                {
                    //No match
                    //Char doesnot match in s[si] and p[pi]
                    ans = false;
                }
                dp[si][pi] = ans;
            }
        }
        return dp[0][0];
    }

    bool solveTabSC(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<int>curr(n+1, 0);//Row 1 with n+1 cols
        vector<int>next(n+1, 0);//Row 2 with n+1 cols
        //inital stat in next row
        next[n] = true;
        //s ka index is out of bound, means col == m and p ka index is still inbound
        //Thderefore we need to check if all the remaining chars in p are '*' or not 
        for(int col = 0; col < n; col++)
        {
            int j = col;
            bool flag = true;
            while(j < p.size())
            { 
                if(p[j] != '*')
                {
                    flag = false;
                    break;
                }
                j++;
            }
            //if we are here, all chars are *
            next[col] = flag;
        }

        for(int si = m-1; si>=0; si--)
        {
            for(int pi = n; pi>=0; pi--)
            {
                bool ans;
                if((s[si] == p[pi]) || (p[pi] == '?'))
                {
                    ans = next[pi+1];
                }
                else if(p[pi] == '*')
                {   //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai. Lets take both cases
                    
                    //Case A: treat * as null or "", means pi ko +1 kardo
                    bool caseA = curr[pi+1];

                    //Case B: Lets * consume one char of s, means si ko +1 kardo
                    bool caseB = next[pi];
                    ans = caseA || caseB;
                }
                else
                {
                    //No match
                    //Char doesnot match in s[si] and p[pi]
                    ans = false;
                }
                curr[pi] = ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    bool isMatch(string s, string p) {
        int si = 0; // index to iterate over string s 
        int pi = 0; // index to iterate over string p   
        //return solveRec(s, si, p, pi);
        //int m = s.length();
        //int n = p.length();
        //vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
        //return solveMem(s, si, p, pi, dp);
        //return solveTab(s, p);
        //Time complexity O(m*n)
        //Space complexity O(n)
        return solveTabSC(s, p);
    }
};