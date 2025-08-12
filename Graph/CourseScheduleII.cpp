/*Leet code 210.
210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Solution {
public:
//Google asked.
//T.C. O(V+E)
    vector<int> topologicalSortBFS(unordered_map<int, list<int> >&adj, int n)
    {
        unordered_map<int, int> indegree;
        vector<int> topoOrder;
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
            topoOrder.push_back(front);
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
            reverse(topoOrder.begin(), topoOrder.end());
            return topoOrder;
        }
        vector<int> temp;
        return temp;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int> > adj;
        //T.C. O(V+E)
        for(auto i : prerequisites)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        //T.C. O(V+E)
        vector<int> ans = topologicalSortBFS(adj, numCourses);
        return ans;
    }
};