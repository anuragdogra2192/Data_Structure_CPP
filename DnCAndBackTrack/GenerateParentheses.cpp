/* Leet Code 22.
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:

1 <= n <= 8
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    //Restricted Recursion
        void solve(vector<string>&ans, int open, int close, string& output, int n)
        {
            //base case
            if(((open + close) == 2*n) && output.length()>0)
            {
                ans.push_back(output);
                return;
            }
            //1k case mein karunga 
            if(open < n)
            {
                output.push_back('(');
                //Baaki recursion sambhalega
                solve(ans, open+1, close, output, n);
                //Backtrack
                output.pop_back();
            }
            if(close < open)
            {
                output.push_back(')');
                solve(ans, open, close+1, output, n);
                //backtrack
                output.pop_back();
            }
            
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            int open = 0;
            int close = 0;
            string output = "";
            solve(ans, open, close, output, n);
            return ans;
        }
    };
/*
Need to understand it.
Big O	Reasoning
O(4^n / sqrt(n)) The time complexity of the generateParenthesis function is O(4^n / sqrt(n))
 because for each position in the output string, we have 2 choices (open or close bracket) 
 and we make 2 recursive calls for each choice. 
 This results in a total of 2^(2n) possible combinations of parentheses. 
 However, not all combinations are valid, so the actual number of 
 valid combinations is approximately 4^n / sqrt(n) due to Catalan number formula. 
 Therefore, the time complexity is O(4^n / sqrt(n)).
*/