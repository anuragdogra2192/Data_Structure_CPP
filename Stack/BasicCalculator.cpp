/* Leet Code 224.
224. Basic Calculator
Hard.
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

Time Complexity
The function iterates through the string once.
Each stack operation (push/pop) is O(1).
Each character is processed in constant time.
Total Time Complexity:
O(N), where N is the length of the string s.

Space Complexity
The stack stores at most O(N) elements (in the worst case, all are parentheses).
Other variables use O(1) space.
Total Space Complexity:
O(N)

Time Complexity: O(N)
Space Complexity: O(N)
*/
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int sign = 1;
        int num = 0; //temp

       for(int i=0; i<s.length(); i++)
       {
            char ch = s[i];
            if(ch>='0' && ch<='9')
            {
                num = num*10 + (ch-'0'); //to handle this edge case "2147483647" -> 2147483647
            }    
            else if(ch == '+')
            {
                //update result with exsiting sign and num
                result += sign * num; 
                //Update sign and num
                sign = 1;
                num = 0;
            }
            else if(ch == '-')
            {
                //update result with exsiting sign and num
                result += sign * num; 
                //Update sign and num
                sign = -1;
                num = 0;
            }
            else if(ch == '(')
            {
                //push the curr result and sign into stack.
                st.push(result);
                st.push(sign);// Ans till this point in expression is stored.
                result = 0;
                sign = 1;
            }
            else if(ch == ')')
            {
                //update result with exsiting sign and num
                result += sign * num;
                //pop the sign and then, result jo push hua tha
                int sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                num = 0;
            }
       } 
       //Add the last num to the result.
       result += sign*num; 
       return result;
    }

};