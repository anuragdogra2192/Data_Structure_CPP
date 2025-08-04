/* Leet code 516.

516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int solveRec(string& a, string& b, int i, int j)
    {
        if(i >= a.length())
        {
            return 0;
        }
        if(j >= b.length())
        {
            return 0;
        }
        int ans = 0;
        //match
        if(a[i] == b[j])
        {
            ans = 1 + solveRec(a, b, i+1, j+1); 
        }
        else
        {//no match, 1k baar i ko +1 karo aur 1k baar j ko +1 karo
            ans = 0 + max( solveRec(a, b, i+1, j), solveRec(a, b, i, j+1)); 
        }
        return ans;
    }

    int solveMem(string& a, string& b, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= a.length())
        {
            return 0;
        }
        if(j >= b.length())
        {
            return 0;
        }
        int ans = 0;
        //match
        if(a[i] == b[j])
        {
            ans = 1 + solveMem(a, b, i+1, j+1, dp); 
        }
        else
        {//no match, 1k baar i ko +1 karo aur 1k baar j ko +1 karo
            ans = 0 + max( solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp)); 
        }
        return ans;
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

    int longestPalindromeSubseq(string s) {
        string first = s;
        string second = s;
        reverse(second.begin(), second.end());
        //return solveRec(first, second, 0, 0);
        //vector<vector<int>> dp(first.length()+1, vector<int>(second.length()+1, -1));
        //return solveMem(first, second, 0, 0, dp);
        //return solveTab(first, second);
        return solveTabSpaceOptimize(first, second);
    }
};