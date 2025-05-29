/* Leet Code:
120. Triangle

Given a triangle array, return the minimum path sum 
from top to bottom.

For each step, you may move to an adjacent number 
of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

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
    
        int minimumTotal(vector<vector<int>>& triangle) {
            return solve(triangle, 0, 0);
        }
    };