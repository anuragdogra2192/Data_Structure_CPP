/*Leet code 207.
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
//Google asked.
//T.C. O(V+E)
    bool topologicalSortBFS(unordered_map<int, list<int> >&adj, int n)
    {
        unordered_map<int, int> indegree;
        stack<int> topoOrder;
        for(int i=0; i<n; i++)
        {
            indegree[i] = 0;
        }
        //now calculate indegree of each node
        for(auto i : adj)
        {
            int u = i.first;
            for(auto j : i.second)
            {
                int v = j;
                indegree[v]++;
            }
        }

        //BFS logic
        queue<int> q;
        //initial state, if indegree 0 toh queue mein push kar do
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
            int front = q.front();
            topoOrder.push(front);
            q.pop();
            //nbr check
            for(auto nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        if(topoOrder.size() == n)
        {//not cycle 
            return true;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int> > adj;
        //T.C. O(V+E)
        for(auto i : prerequisites)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        //T.C. O(V+E)
        return topologicalSortBFS(adj, numCourses);
    }
};