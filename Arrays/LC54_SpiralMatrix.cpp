/*
Leet code 54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

Time Complexity: O(N)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int total_elements = m*n;

        int starting_row = 0;
        int ending_col = n-1;
        int ending_row = m-1;
        int starting_col = 0;

        int count = 0;
        while(count < total_elements)
        {
            //print staring row
            for(int i = starting_col; i<=ending_col && count<total_elements; i++)
            {
                ans.push_back(matrix[starting_row][i]);
                count++;
            }
            starting_row++;

            //print ending col
            for(int i = starting_row; i<=ending_row && count<total_elements; i++)
            {
                ans.push_back(matrix[i][ending_col]);
                count++;
            }
            ending_col--;
            
            //print ending row
            for(int i = ending_col; i>=starting_col && count<total_elements; i--)
            {
                ans.push_back(matrix[ending_row][i]);
                count++;
            }
            ending_row--;

            //print starting ka column
            for(int i = ending_row; i>=starting_row && count<total_elements; i--)
            {
                ans.push_back(matrix[i][starting_col]);
                count++;
            }
            starting_col++;
        }

        return ans;
    }
};