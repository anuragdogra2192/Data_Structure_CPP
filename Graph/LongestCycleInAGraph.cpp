/* Leet code 2360.

2360. Longest Cycle in a Graph

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

Example 1:
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
Example 2:


Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
 
Constraints:
n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i

Solved using dfs.
Can also be done using bfs.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>&edges, vector<bool>&visited,
        vector<bool>&dfsTracker, vector<int>&dist, int currLength, int& longestCycleLength)
    {
        if(node == -1) return;

        visited[node] = true;
        dfsTracker[node] = true;
        dist[node] = currLength;

        int nextNode = edges[node];
        if(nextNode != -1)
        {
            if(!visited[nextNode])
            {   
                dfs(nextNode, edges, visited, dfsTracker, dist, currLength + 1, longestCycleLength);
            }
            else if(dfsTracker[nextNode])
            {//visited hai and dfsTracker mein bhi hai
                //cycle is there.
                //dist[nextNode] - dist of node we pointing to
                int cycleLength = currLength - dist[nextNode] + 1;
                longestCycleLength = max(longestCycleLength, cycleLength);
            }
        }
        //Backtrack 
        dfsTracker[node] = false;
        dist[node] = 0;
    }
    
    int longestCycle(vector<int>& edges) {
        unordered_map<int, list<int>> adjList;
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> dfsTracker(n, false);
        vector<int> dist(n, 0);// we will record distances.
        int longestCycleLength = -1;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i, edges, visited, dfsTracker, dist, 0, longestCycleLength);
            }
        }
        return longestCycleLength;
    }
};