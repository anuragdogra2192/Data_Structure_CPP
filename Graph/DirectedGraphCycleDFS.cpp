/*
Directed Graph Cycle

Difficulty: MediumAccuracy: 27.88%Submissions: 511K+Points: 4

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0

Examples:
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]
Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105
u ≠ v

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V + E)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    bool dfsHelper(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsTracker, unordered_map<int, vector<int> >& adjList)
    {
        visited[node] = true;
        dfsTracker[node] = true;
        
        for(auto nbr : adjList[node])
        {
            if(!visited[nbr])
            {
                bool ans = dfsHelper(nbr, visited, dfsTracker, adjList);
                if(ans == true)
                {
                    return true;
                }
            }
            else if(visited[nbr] == true && dfsTracker[nbr] == true)
            {//cycle present
                return true;
            }
        }
        //Backtrack
        dfsTracker[node] = false;
        return false;
    } 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int> >adjList;
        //Directed graph
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        bool ans = false;
        int n = V;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;
        
        //Diff components ko handle karna hai
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                ans = dfsHelper(i, visited, dfsTracker, adjList);
                if(ans == true)
                {
                    break;
                }
            }
        }
        return ans;
    }
};

