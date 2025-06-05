/* Leet Code: 51
51. N-Queens
The n-queens puzzle is the problem of placing n queens on 
an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to 
the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and 
an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens 
puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]
 
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
    void storeAns(vector<vector<char>>&board, vector<vector<string>>&ans)
    {   
        int n = board.size();
        vector<string> tempAns;
        //copying the board into string
        for(int i=0; i<n; i++)
        {   
            string output = "";
            for(int j=0; j<n; j++)
            {
                output.push_back(board[i][j]);
            }
            tempAns.push_back(output);
        }
        //Vector of string is ready.
        ans.push_back(tempAns);
    }

    bool isSafe(int row, int col)
    {   
        //Brute force
        //To check we have to travers the whole board, T.C - O(n^2)
        //Better approach:
        //Linear Time Complexity: O(n), by creating maps.
        if(m_rowCheck[row] == true)
        {//Queen already there on this row
            return false;
        }
        if(m_upperDiagonalCheck[row-col] == true)
        {
            return false;
        }
        if(m_lowerDiagonalCheck[row+col] == true)
        {
            return false;
        }
        //Else safe to return
        return true;
    }
    void solve(vector<vector<char>>&board, vector<vector<string>>&ans, int col, int n)
    {   
        //Base case
        if(col >= n)
        {   
            storeAns(board, ans);
            return;
        }

        //Lets place the queen in the row
        for(int row = 0; row<n; row++)
        {
            if(isSafe(row, col))
            {
                //1k Case mein solve karunga
                //1k queen hum rakhenge
                board[row][col] = 'Q';
                m_rowCheck[row] = true;
                m_upperDiagonalCheck[row-col] = true;
                m_lowerDiagonalCheck[row+col] = true;
                //Baaki recursion sambhalega
                solve(board, ans, col+1, n);
                //Backtrack
                board[row][col] = '.';
                m_rowCheck[row] = false;
                m_upperDiagonalCheck[row-col] = false;
                m_lowerDiagonalCheck[row+col] = false;
            }
            
        }
    }

    vector<vector<string>> solveNQueens(int n) {
     //lets have a board of nxn size and fill it with .
     vector<vector<char>> board(n, vector<char>(n, '.'));
     vector<vector<string>> ans;
     int col = 0; //Start placing queen with zero pos
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