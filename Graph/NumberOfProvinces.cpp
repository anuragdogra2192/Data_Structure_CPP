/* Leet code 547.
547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    void dfs(int src, vector<vector<int> >& isConnected, vector<bool>& visited)
    {
        visited[src] = true;
        //check all the cities that are connected to the curr city. 
        for(int j=0; j<isConnected.size(); j++)
        {
            if(isConnected[src][j] && !visited[j])
            {
                dfs(j, isConnected, visited);      
            }
        }
    }

    //online and interview question.
    void bfs(int src, vector<vector<int> >& isConnected, vector<bool>& visited)
    {
        queue<int>q;
        //Initial state maintain Karenge 
        q.push(src);
        visited[src] = true;
        //Main logic
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            //check all the cities that are connected to the curr city. 
            for(int j=0; j<isConnected.size(); j++)
            {
                if(isConnected[curr][j] && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n, false);    
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                //bfs(i, isConnected, visited);
                dfs(i, isConnected, visited);
                ans++;
            }
        }   
        return ans;
    }
};