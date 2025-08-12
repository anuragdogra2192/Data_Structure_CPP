/*Leet code 72.
72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int solve(string& word1, string& word2, int i, int j)
    {
        //Base Case:
        if(i >= word1.length())
        {//word1 wali string khatam ho gayi hai
         //may be word 1 is shorter than word2.
          return word2.length() - j; //Remaining words2 return 
        }

        if(j >= word2.length())
        {//word2 wali string khatam ho gayi hai
          //maybe word2 is shorter than word1.
          return word1.length() - i; 
        }

        int ans = 0;
        if(word1[i] == word2[j])
        {//match hai toh
        //ans 0 hogaya + aage bad jate hai.
            ans = 0 + solve(word1, word2, i+1, j+1);
        }
        else//Not match
        {//Means operation performed, toh +1 toh kardo
            //insert
            int option1 = 1 + solve(word1, word2, i, j+1);
            //remove
            int option2 = 1 + solve(word1, word2, i+1, j);
            //replace
            int option3 = 1 + solve(word1, word2, i+1, j+1);
            ans = min(option1, min(option2, option3));
        }
        return ans;
    }

    int solveMem(string& word1, string& word2, int i, int j, vector<vector<int> >& dp)
    {
        //Base Case:
        if(i >= word1.length())
        {//word1 wali string khatam ho gayi hai
         //may be word 1 is shorter than word2.
          return word2.length() - j; //Remaining words2 return 
        }

        if(j >= word2.length())
        {//word2 wali string khatam ho gayi hai
          //maybe word2 is shorter than word1.
          return word1.length() - i; 
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if(word1[i] == word2[j])
        {//match hai toh
        //ans 0 hogaya + aage bad jate hai.
            ans = 0 + solveMem(word1, word2, i+1, j+1, dp);
        }
        else//Not match
        {//Means operation performed, toh +1 toh kardo
            //insert
            int option1 = 1 + solveMem(word1, word2, i, j+1, dp);
            //remove
            int option2 = 1 + solveMem(word1, word2, i+1, j, dp);
            //replace
            int option3 = 1 + solveMem(word1, word2, i+1, j+1, dp);
            ans = min(option1, min(option2, option3));
        }
        return dp[i][j] = ans;
    }
    //bottom up
    int solveBottomUp(string& word1, string& word2)
    {   
        int i = 0; 
        int j = 0;
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0)); 
        //base case handle
        for(int j = 0; j<=n; j++)
        {
            dp[m][j] = word2.length() - j;
        }
        for(int i = 0; i<=m; i++)
        {
            dp[i][n] = word1.length() - i;
        }

        //Reverse
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int ans = 0;
                if(word1[i] == word2[j])
                {//match hai toh
                //ans 0 hogaya + aage bad jate hai.
                    ans = 0 + dp[i+1][j+1];
                }
                else//Not match
                {//Means operation performed, toh +1 toh kardo
                    //insert
                    int option1 = 1 + dp[i][j+1];
                    //remove
                    int option2 = 1 + dp[i+1][j];
                    //replace
                    int option3 = 1 + dp[i+1][j+1];
                   ans = min(option1, min(option2, option3));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        //int ans = solve(word1, word2, i, j);
        //2D dp - i and j are chnaging
        //int m = word1.size();
        //int n = word2.size();
        //vector<vector<int> > dp(m+1, vector<int>(n+1, -1)); 
        //int ans = solveMem(word1, word2, i, j, dp);
        int ans = solveBottomUp(word1, word2);
        return ans;
    }
};