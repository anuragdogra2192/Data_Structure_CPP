/* Leet code 8.
8. String to Integer (atoi)
Implement the myAtoi(string s) function, 
which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and
 the caret is the current reader position.

Step 1: "42" (no characters read because there is no 
leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isDigit(char ch)
        {
            if(ch >= '0' && ch <= '9')
            {
                return true;
            }
            return false;
        }
    
        int myAtoi(string s) {
            int num=0, i = 0;
            int sign = 1; //+ve
            int n = s.length();
            //Step 1: Leading whitespaces. 
            while(i<n && s[i] == ' ')
            {
                i++;
            }
            //Step 2: Check for a sign
            if(i<n && (s[i] == '-' || s[i] == '+'))
            {  
                sign = (s[i] == '-') ? -1 : 1; 
                ++i;
            }
    
            while(i<n && isDigit(s[i]))
            {   //ASCII of '1' -  49
                //ASCII of '0' -  48
                //2147483647 is INT_MAX 
                //if num * 10 == 2147483640
                //      --> then + '8' or + '9' will exceed the limit.
                if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7'))
                {
                    return sign == -1 ? INT_MIN : INT_MAX;
                } 
                //if(num < INT_MIN)
                //    return INT_MIN;
                //If num*10 = INT_MAX,
                //then num * 10 -> signed integer overflow: 912834723 * 10 
                //therfore we need to check earlier.
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            num = sign * num;
            return num;
        }
    };
    /*
    Big O	
    O(n)	The time complexity of the myAtoi function is O(n)
            where n is the length of the input string 's'. 
            The function iterates through the characters of 
            the string once to perform the necessary operations,
            such as skipping leading whitespaces, 
            checking for a sign, and converting digits 
            to an integer. Each character is processed once,
            leading to a linear time complexity.
    */