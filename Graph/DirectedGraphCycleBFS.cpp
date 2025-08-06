/* Geeks for geeks.
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
    void topoBFS(int n, unordered_map<int,vector<int>>& adjList, vector<int>& ans)
    {
        unordered_map<int, int> indegree;
        queue<int> q;
        //Lets prepare indgree
        //Here we are also handling diff components
        for(int src=0; src<n; src++)
        {
            for(auto nbr : adjList[src])
            {//src->nbr
                indegree[nbr]++;//yaha galti hui thi
            }
        }
        //check for indegree 0 and push in q;
        //Maintain initial state in Queue
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        //Main logic
        while(!q.empty())
        {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();
            //kynki front node graph se hat chuki hai
            //Update the indegree of its children
            for(auto nbr : adjList[frontNode])
            {//remove the frontNode nbr
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int> >adjList;
        vector<int> ans;
        //Directed graph
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        topoBFS(V, adjList, ans);
        
        if(ans.size() == V)
        {//matlab saari node aayi hai, 
         //Means no cycle
            return false;
        }
        return true;//cycle present
    }
};