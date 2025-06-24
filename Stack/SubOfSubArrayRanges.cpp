/* Leet code 2104
2104. Sum of Subarray Ranges
You are given an integer array nums.
The range of a subarray of nums is the difference 
between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 
Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109

Time complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<stack>
#include<vector>

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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> prevAns;
        vector<int> nextAns;
        prevSmallerElement(arr, prevAns);
        nextSmallerElement(arr, nextAns);

        long long sum = 0;// sum of all sub array's minimum elements
        const int mod = 1e9 + 7;

        for(int i = 0; i<arr.size(); i++)
        { //for each index element, need to find  how many time this element
         //is contributing to the sum.
            long  left = i - prevAns[i];
            long right = nextAns[i] - i;
            //long long no_of_times = (left%mod * right%mod) % mod;
            //long long total = (no_of_times * arr[i]) % mod;
            //sum = (sum + total)%mod;
            sum += left * right * arr[i];
        }

        return sum;
    }

    void prevGreaterElement(vector<int>& v, vector<int>& prevAns)
    {
        stack<int> st;
        st.push(-1); 

        for(int i=0; i< v.size(); i++)
        {
            int element = v[i];
            while(st.top()!=-1 && v[st.top()] < element)
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

    void nextGreaterElement(vector<int>& v, vector<int>& nextAns)
    { 
        stack<int> st;
        st.push(-1); 
        int n = v.size() - 1;
        for(int i=n; i>=0; i--)
        {
            int element = v[i];
            while((st.top()!=-1) && v[st.top()] <= element)
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

    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> prevAns;
        vector<int> nextAns;
        prevGreaterElement(arr, prevAns);
        nextGreaterElement(arr, nextAns);

        long long sum = 0;// sum of all sub array's maximums elements
        const int mod = 1e9 + 7;

        for(int i = 0; i<arr.size(); i++)
        { //for each index element, need to find  how many time this element
         //is contributing to the sum.
            long long left = i - prevAns[i];
            long long right = nextAns[i] - i;
            //long long no_of_times = (left%mod * right%mod) % mod;
            //long long total = (no_of_times * arr[i]) % mod;
            //sum = (sum + total)%mod;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        auto sumofMaximums = sumSubarrayMax(nums);
        auto sumofMinimums = sumSubarrayMins(nums);

        return sumofMaximums - sumofMinimums;
    }
};