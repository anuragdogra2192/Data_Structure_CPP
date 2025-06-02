/* GFG:
Rat in a Maze Problem - I
Difficulty: MediumAccuracy: 35.75%Submissions: 338K+Points: 4Average Time: 25m
Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1
*/
/*
Time Complexity
Recursive Calls:
Each cell is visited once, and for each cell, up to 4 directions are explored.
Total complexity: O(4^(n*n)) in the worst case.
Sorting:
Sorting the result vector takes O(k * log k), where k is the number of paths.

Space Complexity
Visited Array:

Requires O(n^2) space for the visited array.
Recursion Stack:

Requires O(n) space for the recursion stack.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
      bool isSafe(int r, int c, 
              vector<vector<int>>& maze, vector<vector<bool>>& visited)
      {
          if(r <= -1 || c <= -1 || r >= maze.size() || c >= maze[0].size())
          {//Out of bound
              return false;
          }
          if(visited[r][c] == true)
          {//Already visited
              return false;
          }
          if(maze[r][c] == 0)
          {//blocked
              return false;
          }
          //valid case
          return true;
      }
      
      void solve(vector<vector<int>>& maze, vector<vector<bool>>& visited,
                vector<string>& ans, string output,int src_r, int src_c, 
                int dest_r, int dest_c){
              //base case:
              if(src_r == dest_r && src_c == dest_c)
              {
                  //store the path
                  ans.push_back(output);
                  return;
              }

              //1K case mein solve karunga 
              
              //1 case -  Movement kaise hoti hai
              //    Up  Down    Left    Right
              //dr  -1   +1      0       0
              //dc   0    0     -1      +1
              
              int dr[] = {-1, 1, 0, 0};
              int dc[] = {0, 0, -1, 1};  
              char move[] = {'U', 'D', 'L', 'R'};

              for(int i = 0; i<4; i++)
              {
                int new_r = src_r + dr[i];
                int new_c = src_c + dc[i];
                if(isSafe(new_r, new_c, maze, visited))
                {
                  visited[new_r][new_c] = true;
                  //Baaki recursion shambhal lega
                  solve(maze, visited, ans, output+move[i], new_r, new_c, dest_r, dest_c);
                  //Wapas aake visited ko revert karna padega
                  //Yeah hai backtracking
                  visited[new_r][new_c] = false;
                }
              }

              //Up
            //   int new_r = src_r - 1;
            //   int new_c = src_c;
            //   if(isSafe(new_r, new_c, maze, visited))
            //   {
            //       visited[new_r][new_c] = true;
            //       //Baaki recursion shambhal lega
            //       solve(maze, visited, ans, output+'U',new_r, new_c, dest_r, dest_c);
            //       //Wapas aake visited ko revert karna padega
            //       //Yeah hai backtracking
            //       visited[new_r][new_c] = false;
            //   }
              //Down
            //   new_r = src_r + 1;
            //   new_c = src_c;
            //   if(isSafe(new_r, new_c, maze, visited))
            //   {
            //       visited[new_r][new_c] = true;
            //       //Baaki recursion shambhal lega
            //       solve(maze, visited, ans, output+'D', new_r, new_c, dest_r, dest_c);
            //       //Wapas aake visited ko revert karna padega
            //       //Yeah hai backtracking
            //       visited[new_r][new_c] = false;
            //   }
              //Left
            //   new_r = src_r;
            //   new_c = src_c - 1;
            //   if(isSafe(new_r, new_c, maze, visited))
            //   {
            //       visited[new_r][new_c] = true;
            //       //Baaki recursion shambhal lega
            //       solve(maze, visited, ans, output+'L', new_r, new_c, dest_r, dest_c);
            //       //Wapas aake visited ko revert karna padega
            //       //Yeah hai backtracking
            //       visited[new_r][new_c] = false;
            //   }
              //Right
        //       new_r = src_r;
        //       new_c = src_c + 1;
        //       if(isSafe(new_r, new_c, maze, visited))
        //       {
        //           visited[new_r][new_c] = true;
        //           //Baaki recursion shambhal lega
        //           solve(maze, visited, ans, output+'R', new_r, new_c, dest_r, dest_c);
        //           //Wapas aake visited ko revert karna padega
        //           //Yeah hai backtracking
        //           visited[new_r][new_c] = false;
        //       }
        }
        
      vector<string> ratInMaze(vector<vector<int>>& maze) {
          vector<string> ans;
          // code here
          if(maze[0][0] == 0)
          {//Rat's start pos is blocked
              return ans;
          }
          int n = maze.size();// n x n size.
          vector<vector<bool>>visited(n, vector<bool>(n, false));
          //First/Start cell 
          //is always visited so marked true
          visited[0][0] = true;
          int srcx = 0;
          int srcy = 0;
          int destx = n-1;
          int desty = n-1;
          string output = "";
          
          solve(maze, visited, ans, output, srcx, srcy, destx, desty);
          //Note: Return the final result vector in lexicographically smallest order.
          sort(ans.begin(), ans.end());
          return ans;
      }
  };