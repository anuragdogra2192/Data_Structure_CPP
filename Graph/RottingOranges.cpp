/*Leet code 994.
994. Rotting Oranges
//Highly important, Interview question, Very famous.

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

//Highly important, Interview question, Very famous.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //keeping the corrdinates
        queue<pair<int,int>> q;
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        int freshOranges = 0;
        //Step 1:
        //Initial state maintain x, y coordinates
        //Saare rotten oranges ko queue mein dal do
        for(int i=0; i<n_rows; i++)
        {
            for(int j=0; j<n_cols; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        //If there are no fresh oranges at t = 0 then return 0
        if(freshOranges == 0) return 0;
        
        //Step 2:
        int mins = 0;
        //Direction       L   R   U   D 
        vector<int> dx { -1,  1,  0,  0};
        vector<int> dy {  0,  0,  1, -1};
        //Main logic
        while(!q.empty())
        {
            int n = q.size();// #rotten oranges at current level 
            bool hasRottenNew = false;
            //processing current level
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                for(int d = 0; d < 4; d++)
                { 
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    //Check boundary conditons
                    if(newX >= 0 && newX < n_rows 
                        && newY >= 0 && newY < n_cols
                        && grid[newX][newY] == 1)
                    {//Find fresh 
                        grid[newX][newY] = 2; //Rotted
                        freshOranges--;
                        q.push({newX, newY});//for next level
                        hasRottenNew = true;
                    }
                }
            }
            if(hasRottenNew)    
            {
                mins++;
            }
        }
        //Step 3: Check freshOranges
        if(freshOranges > 0)
        {//Impossible case
            return -1;
        }

        return mins;
    
    }

};