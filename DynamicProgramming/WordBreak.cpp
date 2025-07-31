/* Leet code 139.

139. Word Break
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated 
sequence of one or more dictionary words.

Note that the same word in the dictionary may be 
reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string& s, vector<string>& wordDict)
    {
        for(auto i : wordDict)
        {
            if(s == i) return true;
        }
        return false;
    }   

    bool solveRec(string& s, vector<string>& wordDict, int start)
    {
        if(start == s.size())  return true;
        //1 case karunga 
        string word = "";
        bool flag = false;
        for(int i = start; i<s.size(); i++)
        {
            word += s[i];
            if(isValid(word, wordDict))
            {//jab valid ho, toh next word, otherwise keep creating the word
                flag = flag || solveRec(s, wordDict, i+1);
            }
        }
        return flag;
    }
    
    bool solveMem(string& s, vector<string>& wordDict, int start, vector<int>& dp)
    {
        //base case
        if(start == s.size())  return true;

        if(dp[start] != -1)
        {
            return dp[start];
        }
        //1 case karunga 
        string word = "";
        bool flag = false;
        for(int i = start; i<s.size(); i++)
        {
            word += s[i];
            if(isValid(word, wordDict))
            {//jab valid ho, toh next word, otherwise keep creating the word
                flag = flag || solveMem(s, wordDict, i+1, dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }

    bool solveTab(string& s, vector<string>& wordDict)
    {
        int n = s.size();
        vector<int> dp(n+1, 1);
        //dp[n] = 1;
        for(int start=n-1; start>=0; start--)
        {
            string word = "";
            bool flag = false;
            for(int i = start; i<s.size(); i++)
            {
                word += s[i];
                if(isValid(word, wordDict))
                {//jab valid ho, toh next word, otherwise keep creating the word
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //return solveRec(s, wordDict, 0); 
        //1D - dp, only index is changing.
        //int n = s.size();
        //vector<int> dp(n+1, -1);
        //return solveMem(s, wordDict, 0, dp);
        return solveTab(s, wordDict);
    }
};