/* Leet code 1143.
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int solveRec(string text1,string text2, int i, int j)
    {
        //base case
        if(i >= text1.length())
        {
            return 0;
        }
        if(j >= text2.length())
        {
            return 0;
        }
        int ans = 0; 
        //match
        if(text1[i] == text2[j])
        {
            ans = 1 + solveRec(text1, text2, i+1, j+1);
        }
        else
        { //no match, means 1k baar i ko aage badao or 1k bar j ko aage badao.
            ans = 0 + max(solveRec(text1, text2, i+1, j), solveRec(text1, text2, i, j+1));
        }
        return ans;
    }
    //Time Complexity: O(n*m) n - txt1 length and m - txt2 length 
    int solveMem(string& text1, string& text2, int i, int j, vector<vector<int>>& dp)//Always try to pass byt ref
    {
        //base case
        if(i >= text1.length())
        {
            return 0;
        }
        if(j >= text2.length())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0; 
        //match
        if(text1[i] == text2[j])
        {
            ans = 1 + solveMem(text1, text2, i+1, j+1, dp);
        }
        else
        { //no match, means 1k baar i ko aage badao or 1k bar j ko aage badao.
            ans = 0 + max(solveMem(text1, text2, i+1, j, dp), solveMem(text1, text2, i, j+1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //Time Complexity: O(n*m) n - txt1 length and m - txt2 length 
    int solveTab(string& text1, string& text2)
    {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));

        for(int i = text1.length()-1; i>=0; i--)
        {
            for(int j = text2.length()-1; j>=0; j--)
            {
                int ans = 0; 
                //match
                if(text1[i] == text2[j])
                {
                    ans = 1 + dp[i+1][j+1];
                }
                else
                { //no match, means 1k baar i ko aage badao or 1k bar j ko aage badao.
                    ans = 0 + max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    //Time Complexity: O(n*m) n - txt1 length and m - txt2 length 
    int solveTabSpaceOptimize(string& text1, string& text2)
    {
        vector<int> prev(text2.length()+1, 0);
        vector<int> curr(text2.length()+1, 0);   
              //matrix direction                 //         ^
                                                 //         |
        for(int i = text1.length()-1; i>=0; i--) //    <----
        {
            for(int j = text2.length()-1; j>=0; j--)
            {
                int ans = 0; 
                //match
                if(text1[i] == text2[j])
                {
                    ans = 1 + prev[j+1]; // prev => i+1
                }
                else
                { //no match, means 1k baar i ko aage badao or 1k bar j ko aage badao.
                    ans = 0 + max(prev[j], curr[j+1]); //curr => i, prev => i+1 
                }
                curr[j] = ans;
            }
            //shifting
            prev = curr; // yaha galti hoti hai
        }
        return prev[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        //return solveRec(text1, text2, i, j);
        
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        //return solveMem(text1, text2, i, j, dp);
        //return solveTab(text1, text2);
        return solveTabSpaceOptimize(text1, text2);
    }
};