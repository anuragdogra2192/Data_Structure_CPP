/* Leet code
74. Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

//TIME COMPLEXITY: O(logbase2 (rows*cols))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        while(s<=e)
        {
            //mid use karke we will find rowIndex and colIndex
            int rowIndex = mid/cols;
            int colIndex = mid%cols;

            if(target == matrix[rowIndex][colIndex])
            {
                return true;
            }
            if(target > matrix[rowIndex][colIndex])
            {//Right
                s = mid + 1;
            }
            else
            {//left jao
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};