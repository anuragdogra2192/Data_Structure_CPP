/* Leet code 680.
680. Valid Palindrome II

Given a string s, return true if the s can be palindrome 
after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

Time Comlexity - O(N)
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        
        bool checkPalindrome(string str, int s, int e)
        {
            while(s<=e)
            {
                if(str[s]!=str[e])
                {
                    return false;
                }
                s++;
                e--;
            }
            return true;    
        }
    
        bool validPalindrome(string s) {
            int i = 0;
            int j = s.length() - 1;
    
            while(i<=j)
            {
                if(s[i] == s[j])
                {
                    i++; 
                    j--;
                }
                else
                {//different
                //At MOST ONE deletion is allowed
                //So we can delete only one time to check.
                //This means this else part hit only once. Therefore T.C O(N)
                    //First try to delete ith character
                    bool ansOne = checkPalindrome(s, i+1, j);
                    if( ansOne == true) 
                        return true;
                    //Then try to delete jth character.
                    bool ansTwo = checkPalindrome(s, i, j-1);
                    return ansOne || ansTwo;
                }
            }
    
            return true;
        }
    };