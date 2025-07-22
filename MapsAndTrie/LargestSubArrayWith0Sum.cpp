/*Geeks for geeks.
Largest subarray with 0 sum

Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int, int>map; //Sum and index
        int ans = 0;
        int currSum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            currSum += arr[i];
            if(currSum == 0)//if csum is itself zero
            {
                ans = max(ans, i+1);
            }
            else if(map.find(currSum) == map.end())
            {//Store karo sum and index ko
                map[currSum] = i; 
            }
            else
            {//map has sum already
                ans = max(ans, i - map[currSum]);
            }
        }
        return ans;
    }
};