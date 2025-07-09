/** Leet Code 402:
 * 402. Remove K Digits

Given string num representing a non-negative integer num, and
an integer k, return the smallest possible integer after removing k digits from num.

Topic: Monotonic Stack

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.

Time Complexity--
The algorithm iterates through each digit of num once: O(N)
Each digit is pushed and popped from the stack at most once: O(N)
Removing leading zeros and reversing the answer: O(N)
Total Time Complexity:
O(N), where N is the length of num.

Space Complexity--
The stack can store up to N digits: O(N)
The answer string uses up to N space: O(N)
Total Space Complexity:
O(N)

Summary:

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;
        for(auto digit:num)
        {
            if(k>0)
            {
                while(!st.empty() && st.top() > digit)
                {
                    st.pop();
                    k--;
                    if(k == 0)
                    {
                        break;
                    }
                }
            }
            st.push(digit);
        }

        //if (k>0)
        while(!st.empty() && k>0)
        {   
            st.pop();
            k--;
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        //Removing all trailling zeroes in the reversed ans coming from stack.
        while(ans.size() > 0 && ans.back() == '0')
        {
            ans.pop_back();
        } 

        //get real ans.
        reverse(ans.begin(), ans.end());

        return ans == "" ? "0" : ans;
    }
};