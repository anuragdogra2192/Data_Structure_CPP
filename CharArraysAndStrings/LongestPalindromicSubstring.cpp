/*
Leet Code: 5.
5. Longest Palindromic Substring

Given a string s, return the longest palindromic 
substring in s.

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
#include<string>
using namespace std;

class Solution {
    public:
    //we can also solve with better approach using dynamic programming.
    //But for now we use only string.
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
    
        string longestPalindrome(string s) {
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
    };