/** Geeks for geeks
 * Question:  Steps by Knight
 * https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
Difficulty: MediumAccuracy: 37.32%Submissions: 123K+Points: 4Average Time: 20m
Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

Examples:

Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation:
Knight takes 1 step to reach from 
(3, 3) to (1 ,2).
Input: n = 6, knightPos[] = [4, 5],targetPos[] = [1, 1]
Output: 3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
Constraints:
1 <= n<= 1000
1 <= knightpos ≤ [x, y], targertpos[x, y] ≤  n 

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n^2)
Company Tags
Flipkart Amazon Microsoft 
OYO Rooms MakeMyTrip 
Goldman Sachs Intuit 
Linkedin

Topic Tags
GraphBFS Data Structures Algorithms Queue
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
  
    bool explore(pair<int, int>&front, pair<int, int>& dest, queue<pair<int, int>>& q, vector<vector<bool>>& visit, int& n)
    {
        //8 possibilities.
        int x[] = {-1, -1, 1, 1, 2, 2, -2, -2}; //dx
        int y[] = {2, -2, 2, -2, -1, 1, -1, 1}; //dx
        
        for(int i=0; i<8; i++)
        {//exploring children
            int newX = front.first + x[i];
            int newY = front.second + y[i];
            
            //Boundary and visited check
            if(newX<0 || newX>=n || newY<0 || newY>=n || visit[newX][newY])
            {
                continue;
            }
            
            if(make_pair(newX, newY) == dest) //Reached destination
                return true;
            
            q.push({newX, newY});
            visit[newX][newY] = true;
        }
        return false; //Not reached to destination yet.
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        pair<int, int> src = {knightPos[0]-1, knightPos[1]-1};
        pair<int, int >dest = {targetPos[0]-1, targetPos[1]-1};
        
        if(src == dest) return 0;
        
        queue<pair<int, int>> q;
        q.push(src);
        q.push({-1, -1});
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        visit[src.first][src.second] = true;
        
        int step = 1;
        
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            if(front == make_pair(-1, -1))
            {
                step++;
                if(!q.empty())
                {
                    q.push({-1,-1});
                }
            }
            else//processing
            {
                if(explore(front, dest, q, visit, n))
                {
                    return step;
                }
            }
        }
        return -1;
    }
};