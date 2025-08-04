/* Leet code 1312.

1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.


Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    //Leet code: 516. Longest Palindromic Subsequence
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
    int longestPalindromeSubseq(string& s) {
        string first = s;
        string second = s;
        reverse(second.begin(), second.end());
        return solveTabSpaceOptimize(first, second);
    }

    int minInsertions(string s) {
        int LPS_len = longestPalindromeSubseq(s);
        int insertionToDo = s.size() - LPS_len;
        return insertionToDo;
    }
};

