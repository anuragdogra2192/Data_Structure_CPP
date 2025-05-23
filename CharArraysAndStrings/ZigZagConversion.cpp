/* Leet code 6
6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and 
make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1) //Edge case
                return s;
    
            vector<string>zigzag(numRows);
            int i = 0;
            bool TopToBottom = true;
            while(i < s.length()) //Reasonable condition to stop loop.
            {   
                if(TopToBottom)
                {
                    for(int row=0; row<numRows && i < s.length(); row++)//Imp
                    {
                        zigzag[row].push_back(s[i++]);
                    }
                    TopToBottom = false;
                }
                else
                {   //BottomToTop
                    for(int row=numRows-2; row>0 && i < s.length(); row--)//Imp
                    {
                        zigzag[row].push_back(s[i++]);
                    }
                    TopToBottom = true;
                }
                
            }
            string ans="";
            for(const string& str : zigzag)
            {
                ans+=str;
            }
            return ans;
        }
    };
    /*
    Big O	Reasoning	Timestamp
    O(n)	The time complexity of the given code is O(n) where n is the 
    length of the input string 's'. 
    The code iterates through each character of the input string once 
    and performs constant time operations for each character. 
    Therefore, the overall time complexity is linear in terms of the input size.
    */