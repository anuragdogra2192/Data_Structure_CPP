/* Leet code 5.
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
//we can solve with better approach using dynamic programming.
//Time complexity -  O(N^2)
    string expandAroundCenter(string s, int i, int j)
    {   
        int max_len = 0;
        string ans = "";
        while(i>=0 && j < s.length() && s[i] == s[j])
        {//Means its a Palindrome
            int str_len = j-i+1;
            if (max_len < str_len)
            {   
                max_len = str_len;
                ans = s.substr(i, max_len);
            }
            i--;
            j++;
        }
        return ans;
    }

    string longestPalindrome2(string s) {
        string longest="";
        for(int center=0; center<s.length(); center++)
        {
            //odd
            string oddMaxString = expandAroundCenter(s, center, center);
            //even
            string evenMaxString = expandAroundCenter(s, center, center+1);
            // Update the longest palindrome
            if (oddMaxString.length() > longest.length()) {
                longest = oddMaxString;
            }
            if (evenMaxString.length() > longest.length()) {
                longest = evenMaxString;
            }
        }
        return longest;
    }
    ///Below has the recur to dp approach, 
    int maxLength = 1;
    int start = 0;
    bool solveRec(string& s, int i , int j)
    {//pallindrom using recursion
        //base case
        if(i>=j)
        {
            return true;
        }
        bool flag = false ;
        if(s[i] == s[j])
        {
            flag = solveRec(s, i+1, j-1); 
        }
        if(flag)
        {
            int currlen = j-i+1;
            if(currlen > maxLength)
            {
                maxLength = currlen;
                start = i;
            }
        }
        return flag;
    }

    bool solveMem(string& s, int i , int j, vector<vector<int>>& dp)
    {//pallindrom using recursion
        //base case
        if(i>=j)
        {
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] == s[j])
        {
            flag = solveMem(s, i+1, j-1, dp); 
        }
        if(flag)
        {
            int currlen = j-i+1;
            if(currlen > maxLength)
            {
                maxLength = currlen;
                start = i;
            }
        }
        dp[i][j] = flag;
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        //2D- dp, as i and j both are channging
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                //bool t = solveRec(s, i, j);
                bool t = solveMem(s, i, j, dp);
            } 
        }
        return s.substr(start, maxLength);
    }
};