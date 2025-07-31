/* Leet code 115.
115. Distinct Subsequences

Given two strings s and t, return the number of distinct 
subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int solveRec(string& s, string& t, int i, int j)
    {
        if(i == s.length() && j == t.length())
        {//means equal hogaya
            return 1;
        }
        // or we can say below. 
        //j tabhi aage bagd raha hai jab match kar raha hai.
        if(j == t.length())
        {//same here match ho gaya hai
             return 1;
        }
        if(i == s.length() && j < t.length())
        {//ki match nahi hua hai
         // i katham but j still remaining.
            return 0;
        }
        int ans = 0;
        //Include wala case
        if(s[i] == t[j])
        {
            ans += solveRec(s, t, i+1, j+1);
        }
        //exclude, i ko aage badao and j wahi rahega.
        ans += solveRec(s, t, i+1, j);
        return ans;
    }

    int solveMem(string& s, string& t, int i, int j, vector<vector<int> >& dp)
    {
        //if(i == s.length() && j == t.length())
        //{//means equal hogaya
        //    return 1;
        //}
        // or we can say below. 
        //j tabhi aage bagd raha hai jab match kar raha hai.
        if(j == t.length())
        {//same here match ho gaya hai
             return 1;
        }
        if(i == s.length() && j < t.length() )
        {//ki match nahi hua hai
         // i katham but j still remaining.
            return 0;
        }
        //base case ends here.
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        //Include wala case
        if(s[i] == t[j])
        {
            ans += solveMem(s, t, i+1, j+1, dp);
        }
        //exclude, i ko aage badao and j wahi rahega.
        ans += solveMem(s, t, i+1, j, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(string& s, string& t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i<=n; i++)
        {
            dp[i][m] = 1;
        }
        
        //reverse 
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                long long ans = 0;
                //Include wala case
                if(s[i] == t[j])
                {
                    ans += dp[i+1][j+1];
                }
                //exclude, i ko aage badao and j wahi rahega.
                ans += dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    
    int solveTabSC(string& s, string& t)
    {
        int n = s.size();
        int m = t.size();

        vector<int>curr(m+1, 0);
        vector<int>next(m+1, 0);
        next[m] = 1;
        
        //reverse 
        for(int i=n; i>=0; i--)
        {
            if(i == n)
            {
                curr[m] = 1;
            }
            for(int j=m-1; j>=0; j--)
            { 
                long long ans = 0;
                //Include wala case
                if(s[i] == t[j])
                {
                    ans += next[j+1];
                }
                //exclude, i ko aage badao and j wahi rahega.
                ans += next[j];
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int numDistinct(string s, string t) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = t.size();
        //return solveRec(s, t, i, j);  
        //2D -  dp as i and j both are changing.
        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //return solveMem(s, t, i, j, dp);
        //return solveTab(s,t);
        return solveTabSC(s,t);
    }
};