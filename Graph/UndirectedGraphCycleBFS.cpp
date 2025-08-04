/* Geeks for geeks
Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 615K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    bool cycleDetectionUnDirectedBFS(int src, unordered_map<int, bool>& visited, unordered_map<int, vector<int>>& adjList)
    {
        queue<int> q;
        unordered_map<int, int> parent;
        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        //Main logic
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for(auto nbr : adjList[frontNode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                //cycle detection case
                else if(visited[nbr] == true && parent[frontNode] != nbr)
                {//cycle found
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, bool> visited;
        unordered_map<int, vector<int>> adjList;
        //From edges we need to build the AdjList
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); //undlirected.
        }
        
        bool ans = false;
        //handling disconnected components
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                ans = cycleDetectionUnDirectedBFS(i, visited, adjList);
                if(ans == true)
                {
                    break;
                }
            }
        }
        return ans;
    }
};