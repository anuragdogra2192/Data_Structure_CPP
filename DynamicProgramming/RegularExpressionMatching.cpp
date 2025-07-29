/* Leet code 10.
10. Regular Expression Matching
really hard.
Given an input string s and a pattern p, implement regular expression matching
with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
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
        if(si >= s.size() && pi>=p.size())
        {//Means all chars are matched 
            return true;
        }
        if(pi >= p.size())
        {//pattern lhatam ho gaya hai but s bacha hai, matlab pattern galat hai
            return false;
        }
        //main Logic
        //match or no match
        // '.'  and '*' handling
        bool currMatch = (si < s.length() && ((s[si] == p[pi]) || (p[pi] == '.')));
        //handling of *, phele hi check karna padega, so that preceding char 
        if(pi+1 < p.length() && p[pi+1] == '*')
        {   
            //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai.
            bool replaceWithEmptyChar = (solveRec(s, si, p, pi+2));
            //replace * with prec char + *
            bool replaceWithPrecChar = (currMatch && solveRec(s, si+1, p, pi));
            return replaceWithEmptyChar || replaceWithPrecChar;
        }
        else if(currMatch)//Single char matching '.'
        {
            return solveRec(s, si+1, p, pi+1);
        }
        else
        {
            //no matching 
            return false;
        }
    }
    
    bool solveMem(string& s, int si, string& p, int pi, vector<vector<int> >& dp)
    {
        //base case
        if(si >= s.size() && pi>=p.size())
        {//Means all chars are matched 
            return true;
        }
        if(pi >= p.size())
        {//pattern lhatam ho gaya hai but s bacha hai, matlab pattern galat hai
            return false;
        }
        if(dp[si][pi] != -1)
        {
            return dp[si][pi];
        }
        //main Logic
        //match or no match
        // '.'  and '*' handling
        bool ans;
        bool currMatch = (si < s.length() && ((s[si] == p[pi]) || (p[pi] == '.')));
        //handling of *, phele hi check karna padega, so that preceding char 
        if(pi+1 < p.length() && p[pi+1] == '*')
        {   
            //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai.
            bool replaceWithEmptyChar = solveMem(s, si, p, pi+2, dp);
            //replace * with prec char + *
            bool replaceWithPrecChar = (currMatch && solveMem(s, si+1, p, pi, dp));
            ans = replaceWithEmptyChar || replaceWithPrecChar;
        }
        else if(currMatch)//Single char matching '.'
        {
            ans = solveMem(s, si+1, p, pi+1, dp);
        }
        else
        {
            //no matching 
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

        for(int si=m; si>=0; si--)// why not m-1, because s can be  = "" and p = "a*"", this return true as an ans.
        {
            for(int pi=n-1; pi>=0; pi--)
            {
                bool ans;
                bool currMatch = (si < s.length() && ((s[si] == p[pi]) || (p[pi] == '.')));
                //handling of *, phele hi check karna padega, so that preceding char 
                if(pi+1 < p.length() && p[pi+1] == '*')
                {   
                    //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai.
                    bool replaceWithEmptyChar = dp[si][pi+2];
                    //replace * with prec char + *
                    bool replaceWithPrecChar = (currMatch &&  dp[si+1][pi]);
                    ans = replaceWithEmptyChar || replaceWithPrecChar;
                }
                else if(currMatch)//Single char matching '.'
                {
                    ans = dp[si+1][pi+1];
                }
                else
                {
                    //no matching 
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
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);
        
        next[n] = true;

        for(int si=m; si>=0; si--)
        {
               if(si == m)//both s and p are processed.
               {
                    curr[n] = true;//Therefore we set to true
               }
               else
               {
                    curr[n] = false;
               }
            for(int pi=n-1; pi>=0; pi--)
            {
                bool ans;
                bool currMatch = (si < s.length() && ((s[si] == p[pi]) || (p[pi] == '.')));
                //handling of *, phele hi check karna padega, so that preceding char 
                if(pi+1 < p.length() && p[pi+1] == '*')
                {   
                    //* empty string bhi ban sakta hai ya koi char bhi ban sakta hai.
                    bool replaceWithEmptyChar = curr[pi+2];
                    //replace * with prec char + *
                    bool replaceWithPrecChar = (currMatch &&  next[pi]);
                    ans = replaceWithEmptyChar || replaceWithPrecChar;
                }
                else if(currMatch)//Single char matching '.'
                {
                    ans = next[pi+1];
                }
                else
                {
                    //no matching 
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
        return solveTabSC(s, p);
    }
};