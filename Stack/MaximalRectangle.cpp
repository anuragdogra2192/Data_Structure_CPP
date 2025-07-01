/* Leet Code 85.
85. Maximal Rectangle
Solved
Hard
Topics
premium lock icon
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 
Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

Time Complexity: O(m) * O(n) + O(m) * O(n) = O(mn)
Let’s clarify the time complexity for the Maximal Rectangle problem using your approach:

O(m × n) (if you create a new int matrix for heights)
O(n) (if you reuse the input matrix for heights and only use auxiliary vectors/stacks)

Analysis
For each row, you update the histogram in O(n) time.
For each row, you call largestRectangleArea, which also runs in O(n) time (since all stack operations are amortized O(n)).
There are m rows.
So, the total time complexity is:

Can be optmized with DP.
*/
#include<iostream>
#include<vector>
#include<stack>
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v;
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        for(int i=0; i<row_size; i++)
        {
            vector<int>t;
            for(int j=0; j<col_size; j++)
            {
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }    

        int area = largestRectangleArea(v[0]);// First row
        for(int i=1; i<row_size; i++)
        {
            for(int j=0; j<col_size; j++)
            {
                if(v[i][j])//==1
                {
                   v[i][j] += v[i-1][j]; //Update current row i + with previous row (i-1) only for 1
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};