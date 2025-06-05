/* Leet Code 17.
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        void solve(string& output, string& digits, unordered_map<char, string>& mapping, vector<string>& ans, int i)
        {
            //base case
            if(i >= digits.length() && output.length()>0)
            {   
                ans.push_back(output);
                return;
            }
            //1k case mein karunga
            char digit = digits[i];
            string mappedString = mapping[digit];
            for(char ch : mappedString)
            {//For each character we have to do recursive call,
             //after including in output string.
                output.push_back(ch);
                //Baaki recursion sambhal lega
                solve(output, digits, mapping, ans, i+1);
                //Backtrack
                output.pop_back();
            }
            
        }
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            unordered_map<char, string> mapping;
            mapping['2'] = "abc";
            mapping['3'] = "def";
            mapping['4'] = "ghi";
            mapping['5'] = "jkl";
            mapping['6'] = "mno";
            mapping['7'] = "pqrs";
            mapping['8'] = "tuv";
            mapping['9'] = "wxyz";
    
            int i = 0;
            string output = "";
            solve(output, digits, mapping, ans, i);
    
            return ans;
        }
    };
/*
Time Complexity:
The time complexity of the letterCombinations function is O(4^n), 
where n is the length of the input string digits. Here's why:

Each digit in the input string maps to 3 or 4 letters 
(e.g., '2' maps to "abc", '7' maps to "pqrs").
For each digit, the function explores all possible combinations 
of letters recursively.

In the worst case, every digit maps to 4 letters
(e.g., '7' or '9'), and there are n digits. 
This results in 4^n combinations.

Space Complexity:
The space complexity is O(n) for the recursion stack and O(4^n) 
for storing the results:

Recursion Stack: The depth of the recursion is equal to the length of the input string digits, so the recursion stack uses O(n) space.
Result Storage: 
The function stores all possible combinations in the ans vector.

In the worst case, there are 4^n combinations, 
and each combination has a length of n. 
Thus, the space required for storing results is O(n * 4^n).

Summary:
Time Complexity: O(4^n)
Space Complexity: O(n * 4^n)
*/