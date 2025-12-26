/* Leet code 7
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 
Constraints:
-231 <= x <= 231 - 1
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;//reversed x
        while(x != 0)
        {
            int remainder = x % 10; //current last digit
            x = x / 10; // new divident
            
            //INT_MAX is 2147483647, INT_MIN is -2147483648
            if (ans > INT_MAX/10 || (ans == (INT_MAX/10) && (remainder > 7))) 
                return 0;
            if (ans < INT_MIN/10 || (ans == (INT_MIN/10) && (remainder < -8))) 
                return 0;
            //Add to reverse
            ans = ans * 10 + remainder;
        }
        return ans;
    }
};