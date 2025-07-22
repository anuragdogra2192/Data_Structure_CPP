/*Geeks for geeks
Largest subarray of 0's and 1's

https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 1

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
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int>map; //Sum and index
        int ans = 0;
        int currSum = 0;
        for(int i=0; i<arr.size(); i++)
        {   int val = (arr[i] == 0 ? -1 : 1);
            currSum += val;
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