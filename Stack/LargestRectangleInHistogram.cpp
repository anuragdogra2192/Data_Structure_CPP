/*Leet Code 84.
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

Time Complexity: O(N)
Space Complexity: O(N)
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
void prevSmallerElement(vector<int>& heights, vector<int>& prevAns)
{
    stack<int>st;
    st.push(-1); //Warning :index handling 
    int n = heights.size();

    //Left to Right traverse.
    for(int i=0; i<n;i++)
    {
        int element = heights[i];
        while((st.top() != -1) && heights[st.top()]>=element)// '>=' wala sign bhul jata huin 
        {
            st.pop();
        }
        //Here element Index  >= st.top() index
        //Store ans Index
        prevAns.push_back(st.top());
        //push the element index in stack for next comparisons.
        st.push(i);
    }
}

//nextAns wale vector mein nextSmallerElement ka INDEX store karna hai, not ans 
void nextSmallerElement(vector<int>& heights, vector<int>& nextAns)
{
    stack<int>st;

    st.push(-1);//Stack keep index of next smaller elements, we have handle -1 carefully. 
    //In case of next, in the end.
    //we have to replace -1 with its lastindex+1, in the nextAns.
    //Right to Left traverse on v.
    int n = heights.size();
    for(int i = n-1; i>=0; i--)
    {
        int element = heights[i];

        while((st.top() != -1) && heights[st.top()] >= element)// '>=' wala sign bhul jata huin
        {
            st.pop();
        }
        //Here st.top() is index of smaller than element.
        //Lets store in the ans Index
        nextAns.push_back(st.top());
        //Add the current element index in the stack fot next comparisions
        st.push(i); //Store the current index.
    }
    //To get the correct sequence., reverse the ans;
    reverse(nextAns.begin(), nextAns.end());
}

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights, nextAns);
        //we have to replace -1 with heights lastindex+1 or size, in the nextAns.
        //To calculate the correct width.
        //yeah mein bhul jata huin.
        for(int i=0; i<nextAns.size(); i++)
        {
            if(nextAns[i] == -1)
            {
                nextAns[i] = heights.size();
            }
        }

        prevSmallerElement(heights, prevAns);
        //Both have ben popuated.

        //vector<int>area;
        int maxArea = INT_MIN;
        for(int i=0; i<nextAns.size(); i++)
        {
            int width = nextAns[i] - prevAns[i] - 1; 
            int height = heights[i];
            int currentArea = width * height;
            maxArea = currentArea > maxArea ? currentArea : maxArea;
            //area.push_back(currentArea);
        }

        // for(int i=0; i<area.size(); i++)
        // {
        //     maxArea = area[i] > maxArea ? area[i] : maxArea;
        // }
        return maxArea;
    }
};