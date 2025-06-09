/* Leet Code: 79
79: Word Case 
Given an m x n grid of characters board and a string word, 
return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and 
uppercase English letters.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int row, int col, int i)
    {
        //base case
        if(i == word.length()) // all char matched
        {
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        {
            return false;
        }
        if (board[row][col] != word[i])
        {
            return false;
        }
        //Lets check if already visited
        if(board[row][col] == '%')
        { 
            return false;
        }

        //If I have reach here means, current ith word char is matched. 
        //And now we mark it visited.
        char saved = board[row][col];
        board[row][col] = '%';

        //1 case -  Movement kaise hoti hai
        //    Up  Down    Left    Right
        //dr  -1   +1      0       0
        //dc   0    0     -1      +1
              
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k= 0; k<4; k++)
        {
            bool ans = solve(board, word, row+dr[k], col+dc[k], i+1);
            if(ans == true)
            {
                return true;
            }
        }
        //BackTracking
        board[row][col] = saved; //Set back to original
        return false;
    }   

    bool exist(vector<vector<char>>& board, string word) {
         for(int row = 0; row<board.size(); row++)
         {
            for(int col = 0; col<board[0].size(); col++)
            {
                if(solve(board, word, row, col, 0))
                {
                    return true;
                }
            }
         }
         return false;
    }
};