/* Leet code 200.

200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        //Initially state maintian
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';

        //directions
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            //check all the neighbours of src
            for(int d=0; d<4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]=='1')
                {
                    grid[nx][ny] = '0'; //mark visited
                    q.push({nx, ny});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        //if(m==1 )
        //visited mark karne ke liye grid[][] = 0 ko mark kar denge.
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};