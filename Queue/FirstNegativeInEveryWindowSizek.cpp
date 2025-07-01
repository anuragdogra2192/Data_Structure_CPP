/** Geek For Geeks
Question: First negative in every window of size k

Really important concept
"Sliding window"

Difficulty: MediumAccuracy: 48.61%Submissions: 191K+Points: 4Average Time: 15m
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.
Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window [12, -1, -7] First negative integer is -1.
Window [-1, -7, 8] First negative integer is -1.
Window [-7, 8, -15] First negative integer is -7.
Window [8, -15, 30] First negative integer is -15.
Window [-15, 30, 16] First negative integer is -15.
Window [30, 16, 28] No negative integers, output is 0.
Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0] 
Explanation:
Window [12, 1, 3] No negative integers, output is 0.
Window [1, 3, 5] No negative integers, output is 0.

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
1 <= k <= arr.size()

Time Complexity: O(N)
Space Complexity: O(k) (auxiliary), O(N) (output)
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        //Sliding Window Concept
        deque<int> q; 
        //index store karnege hum queue mein because it will tell us
        //about that the current element is in the Window or not.
        //Step1: process first window
        for(int i=0; i<k; i++)
        {
            int element = arr[i];
            if(element < 0)
            {
                q.push_back(i);
            }
        }
        //The above window stores the index of all the -ve numbers inside the first window.
        //Step2: process remaining windows -> ans/removal/addition
        for(int i=k; i<arr.size(); i++)
        {
            //Step A - ans store
            if(q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                int index = q.front();
                int element = arr[index];
                ans.push_back(element);
            }
            //Step B - Removal of element which are not inside current window
            if(!q.empty() && i-q.front() >= k)
            {
                q.pop_front();
            }
            //step C - Addition of new element
            int element = arr[i];
            if(element < 0)
            {
                q.push_back(i);//Index
            }
        }
        //Step 3: last window ka answer store karo
        if(q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int index = q.front();
            int element = arr[index];
            ans.push_back(element);
        }
        
        return ans;
    }
};