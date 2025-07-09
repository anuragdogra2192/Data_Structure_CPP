/** Leet Code 739.
739. Daily Temperatures

Topics - Monotonic Stack

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

Time Complexity
Each temperature index is pushed and popped from the stack at most once.
The loop runs for all N days.
Total Time Complexity:
O(N), where N is the length of the temperatures array.

Space Complexity
The stack stores at most N indices: O(N)
The answer vector is also of size N: O(N)
Total Space Complexity:
O(N)

Summary:

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int>st;//keeping index
        for(int i=0; i<temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};