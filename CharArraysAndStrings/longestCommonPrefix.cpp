/* Leet Code 14.
14. Longest Common Prefix

Write a function to find the longest common prefix 
string amongst an array of strings.

If there is no common prefix, return an empty string "". 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters 
if it is non-empty.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int i = 0;
            string ans = "";
            while(true) //infinite loop or one possiblity is to (i<200) as each str length can be max 200
            {   
                char curr_char = 0;
                for(auto str: strs)
                {
                    //Any of str is fully traversed then we need to break
                    if(i>=str.length())
                    {   
                        curr_char = 0;
                        break;
                    }
                    //Just started
                    if(curr_char == 0)
                    {
                        curr_char = str[i];
                    }
                    else if(str[i] != curr_char)
                    {
                        curr_char = 0;
                        break;
                    }
                }
                if(curr_char == 0)
                {
                    break;
                }
                ans.push_back(curr_char);
                i++;    
            }
            return ans;
        }
    };
    
    /*
    Big O	Reasoning
    O(n*m)	The time complexity of the code is O(n*m) 
    where n is the number of strings in the input vector 'strs' and
    m is the average length of the strings. 
    The code iterates through each character of the strings 
    in the input vector to find the longest common prefix.
    The worst-case scenario is that it needs to traverse all characters 
    of all strings in the input vector, resulting in a time complexity of O(n*m).
    */