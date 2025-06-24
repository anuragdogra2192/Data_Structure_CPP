/** Leet Code 907.
 * 907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges
over every (contiguous) subarray of arr. Since the answer may be large,
return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

Time Complexity: O(n) 
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

 class Solution {
public:

    void prevSmallerElement(vector<int>& v, vector<int>& prevAns)
    {
        stack<int> st;
        st.push(-1); 

        for(int i=0; i< v.size(); i++)
        {
            int element = v[i];
            while(st.top()!=-1 && v[st.top()] > element)
            //Doing v[st.top()] > element) instead of  v[st.top()] >= element)
            // Beacuse we want to avoid extra repeations of mins of same element, in subarrays, 
            //Hard to explain but with dry run its easier.
            {
                st.pop();
            }
            //Store the index of smaller element in ans
            prevAns.push_back(st.top());
            //Stor the current element index in stack for comparisions.
            st.push(i);
        }        
    }

    void nextSmallerElement(vector<int>& v, vector<int>& nextAns)
    { 
        stack<int> st;
        st.push(-1); 
        int n = v.size() - 1;
        for(int i=n; i>=0; i--)
        {
            int element = v[i];
            while((st.top()!=-1) && v[st.top()] >= element)
            {
                st.pop();
            }
            //Store the index of smaller element in ans
            nextAns.push_back(st.top());
            //Stor the current element index in stack for comparisions.
            st.push(i);
        }        
        //reverse it to get the correct sequence
        reverse(nextAns.begin(), nextAns.end());
        //Replacing -1 with the lastindex + 1, to rectify the boundary index
        for(int i=0; i<nextAns.size(); i++)
        {
            if(nextAns[i]==-1)
            {
                nextAns[i] = nextAns.size();
            }
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prevAns;
        vector<int> nextAns;
        prevSmallerElement(arr, prevAns);
        nextSmallerElement(arr, nextAns);

        int sum = 0;// sum of all sub array's minimum elements
        const int mod = 1e9 + 7;

        for(int i = 0; i<arr.size(); i++)
        { //for each index element, need to find  how many time this element
         //is contributing to the sum.
            int left = i - prevAns[i];
            int right = nextAns[i] - i;
            long long no_of_times = (left%mod * right%mod) % mod;
            long long total = (no_of_times * arr[i]) % mod;
            sum = (sum + total)%mod;
        }

        return sum;
    }
};