/* Leet code 1631.
1631. Path With Minimum Effort
Question is important and tricky to understand.

You are a hiker preparing for an upcoming hike. 
You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Constraints:
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue < pair<int, pair<int, int>>, vector< pair<int, pair<int, int> >>
        , greater< pair<int, pair<int, int> >> > pq;   
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int> > dist (rows, vector<int>(cols, INT_MAX));
        
        //Initial state maintain
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        //main logic (Dijkstra)
        while(!pq.empty())
        {
            pair<int, pair<int, int> > frontNode  = pq.top();
            pq.pop();

            int currAbsDiff = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;

            //check for destination
            if(x==rows-1 && y==cols-1)
            {
                return dist[x][y]; //yaha galti hui thi
            }
            else
            {//destination tak nahi pahuche hai
             //then do up, down, left and right.
                //          L   U  R  D
                int dx[] = {0, -1, 0, 1};//row
                int dy[] = {-1, 0, 1, 0};//col
                for(int i=0; i<4; i++)
                {
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    //check boundaries
                    if(newX >=0 && newY >=0 && newX<rows && newY<cols)
                    {//Means safe
                        int newAbsDiff = abs(heights[x][y] - heights[newX][newY]);
                        //as per question, abs difference main MAXIMUM wala store karna chahta huin
                        int newMaxDiff = max(currAbsDiff, newAbsDiff);
                        //As per question, effort(dist) mein MINIMUM wala store karna chahta huin.
                        if(newMaxDiff < dist[newX][newY])
                        {
                            dist[newX][newY] = newMaxDiff;
                            //jb bhi app koi naya new max diff calculate karte hai
                            //toh usse pq mein push karo
                            pq.push({newMaxDiff,{newX, newY}});
                        }
                    }
                }
            }

        }
        return 0;
    }
};