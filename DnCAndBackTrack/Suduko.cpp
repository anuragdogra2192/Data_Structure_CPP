/* Leet Code: 37
37. Sudoku Solver
Solved
Hard
Topics
premium lock icon
Companies
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

Time complexity: O(Exponential)
k = 81 cells
Aspect	Complexity
Time Complexity	O(9^k)
Space Complexity	O(k)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool isSafe(char digit, int row, int col, vector<vector<char>>& board)
        {
            //3 rules
            int n = board.size();
            //rowCheck
            for(int k=0;k<n;k++)
            {
                if(board[row][k] == digit)
                {   //Same digit phele se hi same row mein exist karta hai
                    return false;
                }
            }
            //colCheck
            for(int k=0;k<n;k++)
            {
                if(board[k][col] == digit)
                {///Same digit phele se hi exist karte hai
                    return false;
                }
            }
    
            //3X3 sub-board check
            for(int k=0; k<n; k++)
            {
                int zone_r = row/3;
                int zone_c = col/3;
                int i = (3*zone_r) + (k/3);// 0 0 0 1 1 1 2 2 2
                int j = (3*zone_c) + (k%3);// 0 1 2 0 1 2 0 1 2
    
                if(board[i][j] == digit)
                {
                    return false;
                }
            
            }
            //Note: for(int k=0;k<n;k++) can be used one time for all 3 checks.
    
            //Digit kahi bhi exist nai karti.
            return true;
        }
    
        bool solve(vector<vector<char>>& board)
        {
            //base case ?
            //1k case mein karunga
            //baaki recursion sambhalega
            //Lets first find the empty cell in the board
            //Empty cell -> '.'
            //Traverse
            for(int row=0; row<board.size(); row++)
            {
                for(int col=0; col<board[0].size(); col++)
                {
                    //Mein j and i th cell pe huin
                    //pata kaise chalega ki data fill karu ya nahi
                    //Sirf Empty cell pe fill karenge
                    if(board[row][col] == '.')
                    {// Lets fill 1-9 digits, hit and trial
                        for(char digit = '1'; digit<='9'; digit++)
                        {
                            //Konsa digit rakh sakta huin yeah kaise pata chalega.
                            //We just need to check which digit is Safe to place.
                            if(isSafe(digit, row, col, board))
                            {// Safe hai
                                //1k Digit mein rakhunga baaki
                                board[row][col] = digit;
                                bool aageSolveHoPaya = solve(board);
                                if(aageSolveHoPaya)
                                {//Poora board solve hoagya hai
                                    return true;
                                }
                                else
                                {//aage ka board solve nahi ho paya
                                 //Backtrack --> Iska matlab wrong digit rakh diya  
                                    board[row][col] = '.';
                                }
                            }    
                        }
                        //If we are here, 
                        //Iska matlab ye h->k, 1-9 tk koi bhi digit yaha pr fit nahi ho ra hai
                        //piche kahi pe galti kari h
                        return false;
                    }
                }
            }
            //Yaha hai iska matlab oura bord fill ho gaya hai.
            return true;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
    };