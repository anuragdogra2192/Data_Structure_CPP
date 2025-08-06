/*Geeks for Geeks

Shortest Path in Undirected Graph
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :
Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]
 
Input: adj[][]= [[3], [3], [], [0, 1]], src=3
Output: [1, 1, -1, 0]

Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
Output: [-1, 0, -1, -1, -1, -1, -1] 
Constraint:
1<=adj.size()<=104
0<=edges<=adj.size()-1

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
  public:
  //Uneighted and same weighted.
  
    vector<int> shortestPathBFS(int src, vector<vector<int>>& adj)
    {
        unordered_map<int, bool> visited;
        int n = adj.size(); //number of vertices
        vector<int> dist(n, -1);
        queue<int> q;
        //initial state
        q.push(src);
        visited[src] = true;
        dist[src] = 0;
        //main logic
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adj[frontNode])
            {
                if(!visited[nbr])
                {   
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[frontNode] + 1;
                }
            }
        }
        
        return dist;
    }
    
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        return shortestPathBFS(src, adj);
    }
};