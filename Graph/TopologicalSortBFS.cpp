/* Geeks for geeks.

Topological sort

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
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
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> adjList;
        vector<int> ans;
        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            //Directed Graph
            adjList[u].push_back(v);
        }
        topoBFS(V, adjList, ans);
        return ans;
    }
};