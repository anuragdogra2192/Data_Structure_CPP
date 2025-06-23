/** Leet Code 221. 
 * 221. Maximal Square
 * Interview Question
Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and 
return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
Time Limit Exceeded, Should be improved with DP
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int& row, int& col, int& maxi)
    {
        //base case
        if(i>=row || j>=col)
        { //Out odf bound No square outside 
            return 0;
        }
        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int rightDowndiagonal = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        //Check can we build square from current position.
        if(matrix[i][j] == '1')
        {           // 1+ for jis square pe khade ho wo.
            int ans = 1 + min(right, min(rightDowndiagonal, down));
            //yaha bhi galti karoge
            maxi = max(maxi, ans);
            return ans; //Yeah bhul jata huin;
        }
        else
        {//Agar mein 0 hi khade ho toh ans bhi 0
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0;
        int j = 0;
        int maxi = 0;// For [['0']]
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = solve(matrix, i, j, row, col, maxi); 
        return maxi*maxi; //Return its area;
    }
};