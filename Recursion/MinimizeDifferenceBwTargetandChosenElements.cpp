/* Leet code: 
1981. Minimize the Difference Between Target and Chosen Elements

You are given an m x n integer matrix mat and an integer target.

Choose one integer from each row in the matrix such that the absolute difference between target and the sum of the chosen elements is minimized.

Return the minimum absolute difference.

The absolute difference between two numbers a and b is the absolute value of a - b.

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
Output: 0
Explanation: One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.
Example 2:


Input: mat = [[1],[2],[3]], target = 100
Output: 94
Explanation: The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.
Example 3:


Input: mat = [[1,2,9,8,7]], target = 6
Output: 1
Explanation: The best choice is to choose 7 from the first row.
The absolute difference is 1.
 
Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 70
1 <= mat[i][j] <= 70
1 <= target <= 800
Time Complexity: O(M^N) exponentially
As we are using only recursion.
DP might make it better.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int MinAbsDiffRec(vector<vector<int>>& mat, int row, int col,int sum, int& target)
        {
           //Base Case
            if(row >= mat.size())
            {
                return abs(sum - target);
            }
            //Base Case
            if(col >= mat[0].size())
            {
                return INT_MAX;
            }
            //Include
            //Include: Select the current element and move to the next row
            //when we move to the next row (row + 1), 
            //we need to start evaluating all columns in that new row from the first column 
            //(col = 0). 
            //This ensures that the recursion explores all possible combinations of 
            //elements across rows.
    
            int includeMinDiff = INT_MAX;
            includeMinDiff = MinAbsDiffRec(mat, row+1, 0, sum+mat[row][col], target);
            //Exclude
            //Exclude: Skip the current element and move to the next column:
            int excludeMinDiff = INT_MAX;
            excludeMinDiff = MinAbsDiffRec(mat, row, col+1, sum, target);
    
            return min(includeMinDiff, excludeMinDiff);
        }
    
        int MinAbsDiff(vector<vector<int>>& mat, int row, int sum, int& target)
        {
            //Base Case
            if(row >= mat.size())
            {
                return abs(sum - target);
            }
            //Include
            int MinDiffAns = INT_MAX;
            //For columns we use for loop
            for(int col=0; col<mat[0].size();col++)
            {
                int recMinDiff = MinAbsDiff(mat, row+1, sum+mat[row][col], target);
                MinDiffAns = min(recMinDiff, MinDiffAns);
            } 
            return MinDiffAns;
        }
    
        int minimizeTheDifference(vector<vector<int>>& mat, int target) {
            return MinAbsDiffRec(mat, 0, 0, 0, target);
            //return MinAbsDiff(mat, 0, 0, target);
        }
    };