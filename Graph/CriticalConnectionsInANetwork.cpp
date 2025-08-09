/* Leet code 1192.
1192. Critical Connections in a Network
Highly important 
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>

using namespace std;
class Solution {
public:
/* Interview question.
A critical connection is a connection that, 
if removed, will make some servers unable to reach some other server.
The above line means find out the Bridges
*/
    void countBridges(int src, int parent, vector<int>& tin, vector<int>& low, 
        unordered_map<int, bool>& vis, int timer, vector<vector<int>>& ans, unordered_map<int, list<int> >& adjList)
    {   
        timer++;
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        //neighbour pe travel karte hai
        for(auto nbr : adjList[src])
        {
            //kynki undirected graph hai, toh 
            //neighbour me parent bhi ho sakta hai
            if(nbr == parent)
            {
                continue;
            }
            else if(!vis[nbr])
            {//normal traversal karo and check for bridges 
                countBridges(nbr, src, tin, low, vis, timer, ans, adjList);
                //ab mein yaha se wapas aya toh, let check for the bridge.
                low[src] = min(low[src], low[nbr]);//yeah bhul jata huin
                if(low[nbr] > tin[src])
                {//bridge exists
                    vector<int> temp;
                    //cout<<"Bridge found"<<endl;
                    //cout<< nbr << "-" << src <<endl;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            else
            {//already visited and not a parent 
             //low time ko update kardo if possible
                low[src] = min(low[src], low[nbr]);
            }
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        unordered_map<int, list<int> >adjList;
        for(auto edge :  connections)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int src = 0;
        int parent = -1;
        vector<int>tin(n, 0);
        vector<int>low(n, 0); 
        unordered_map<int, bool>vis;
        int timer;
        countBridges(src, parent, low, tin, vis, timer, ans, adjList);

        return ans;
    }
};