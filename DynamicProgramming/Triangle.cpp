/* Leet code 
120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally,
if you are on index i on the current row, 
you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10


Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
Follow up: Could you do this using only O(n) extra space, 
where n is the total number of rows in the triangle?
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col)
    {
        //Base Case
        if(row == triangle.size()-1)
        {
            return triangle[row][col];
        }

        int indexSum = 0;
        int indexPlusSum = 0;
        //Case: i
        indexSum = triangle[row][col] + solve(triangle, row+1, col);
        //Case: i+1
        indexPlusSum = triangle[row][col] + solve(triangle, row+1, col+1);
        //return Minimum among both    
        return min(indexSum, indexPlusSum);
    }
    //Top down approach
    int solveMem(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp)
    {
        //Base Case
        if(row == triangle.size()-1)
        {
            return triangle[row][col];
        }
        if(dp[row][col] > INT_MIN)
        {
            return dp[row][col];
        }
        int indexSum = 0;
        int indexPlusSum = 0;
        //Case: i
        indexSum = triangle[row][col] + solveMem(triangle, row+1, col, dp);
        //Case: i+1
        indexPlusSum = triangle[row][col] + solveMem(triangle, row+1, col+1, dp);
        //return Minimum among both    
        return dp[row][col] = min(indexSum, indexPlusSum);
    }

    //Bottom up appraoch
    int solveBottomUp(vector<vector<int>>& triangle)
    {
        vector<vector<int>> dp = triangle;//copy shape
        for (auto &row : dp)
        {
            fill(row.begin(), row.end(), INT_MIN);
        } 
        //Base Case
        int last_row = triangle.size()-1;

        for(int i = 0; i<triangle.size(); i++)
        {
            dp[last_row][i] =triangle[last_row][i]; 
        }

        for(int row=triangle.size()-2; row>=0; row--)
        {
            for(int col=row; col>=0; col--)
            {
                int indexSum = 0;
                int indexPlusSum = 0;
                //Case: i
                indexSum = triangle[row][col] + dp[row+1][col];//solveMem(triangle, row+1, col, dp);
                //Case: i+1
                indexPlusSum = triangle[row][col] + dp[row+1][col+1];//solveMem(triangle, row+1, col+1, dp);
                //return Minimum among both    
                dp[row][col] = min(indexSum, indexPlusSum);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        //return solve(triangle, 0, 0);
        // vector<vector<int>> dp = triangle;//copy shape
        // for (auto &row : dp)
        // {
        //     fill(row.begin(), row.end(), INT_MIN);
        // } 
        // return solveMem(triangle, 0, 0, dp);
        return solveBottomUp(triangle);
    }
};