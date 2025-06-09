/* Leet code 52.
52. N-Queens II

The n-queens puzzle is the problem of placing n queens
on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions
to the n-queens puzzle.

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens 
puzzle as shown.

Example 2:

Input: n = 1
Output: 1

Constraints:

1 <= n <= 9
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    unordered_map<int, bool> m_rowCheck;
    unordered_map<int, bool> m_upperDiagonalCheck;
    unordered_map<int, bool> m_lowerDiagonalCheck;
public:
    bool isSafe(int row, int col)
    {
        //Better approach:
        //Linear Time Complexity: O(n), by creating maps.
        if(m_rowCheck[row] || m_upperDiagonalCheck[row-col] || m_lowerDiagonalCheck[row+col])
        {//Queen already there
            return false;
        }
        //Else safe to return
        return true;
    }

    void solve(vector<vector<char>>&board, int& ans, int col, int& n)
    {
        if(col>=n)
        {   
            ans += 1;
            return; 
        }
        //Lets place the queen in row.
        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col))
            {
                //1k case hum solve karenge 
                //1k queen hium rakhenge
                board[row][col] = 'Q';
                m_rowCheck[row] = true;
                m_upperDiagonalCheck[row-col] = true; 
                m_lowerDiagonalCheck[row+col] = true;  
                //bakki recursion sambhalega 
                solve(board, ans, col+1, n);
                //Backtrack
                board[row][col] = '.';
                m_rowCheck[row] = false;
                m_upperDiagonalCheck[row-col] = false; 
                m_lowerDiagonalCheck[row+col] = false;  
            }
        }
    }
    int totalNQueens(int n) {
        //Lets have a board of nxn size and fill it with '.'
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int ans = 0;
        int col = 0; //Start placing the queen with 0th column
        solve(board, ans, col, n);
        return ans;
    }
};

/*
Time Complexity 
The N-Queens problem involves placing n queens on an n x n chessboard such that no two queens attack each other. The time complexity can be analyzed as follows:

Recursive Backtracking:

At each column, the algorithm tries to place a queen in one of the n rows.
For the first column, there are n choices.
For the second column, there are at most n-1 valid choices (since some rows may already be blocked).
For the third column, there are at most n-2 valid choices, and so on.
In the worst case, the number of recursive calls is proportional to n! (factorial of n).
Checking Safety:

The isSafe function uses hash maps (m_rowCheck, m_upperDiagonalCheck, m_lowerDiagonalCheck) to check if a queen can be placed in constant time O(1).
This optimization avoids the brute-force O(n^2) traversal of the board.
Storing the Solution:

When a valid configuration is found, the board is converted into a vector of strings and stored in the result. Copying the board takes O(n^2) time for each solution.
Overall Time Complexity:

The recursive backtracking generates O(n!) configurations in the worst case.
For each configuration, storing the solution takes O(n^2).
O(n! * n^2)

Space Complexity
Board Storage:

The board is an n x n 2D vector, which requires O(n^2) space.
Hash Maps:

The hash maps (m_rowCheck, m_upperDiagonalCheck, m_lowerDiagonalCheck) store information about rows and diagonals. Each hash map can store up to 2n-1 entries (for rows and diagonals), so the total space required is O(n).
Recursion Stack:

The recursion depth is equal to the number of columns, which is n. Each recursive call adds a frame to the stack, so the recursion stack requires O(n) space.
Result Storage:

The result vector (ans) stores all valid configurations. In the worst case, there can be n! solutions, and each solution requires O(n^2) space to store the board.
Therefore, the space required for storing the result is O(n! * n^2).
Overall Space Complexity:
O(n! * n^2)
*/