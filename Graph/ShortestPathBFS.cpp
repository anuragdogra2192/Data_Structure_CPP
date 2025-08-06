#include<iostream>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if(!direction)
            adjList[v].push_back(u);
    }

    void printAdjList(int n)
    {
        for(int i=0; i<n; i++)
        {   
            cout<< i <<" : { ";
            for(auto j : adjList[i])
            {
                cout<< j <<", ";
            }
            cout<<" } ";
        }
    }
    //Time complexity - O(V+E)
    void shortestPathBFS(int src, int dest)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        //main logic

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
            }
        }
        //parent array ready
        vector<int> path;
        int node = dest;
        while(node != -1)
        {   
            //1) Store in path
            path.push_back(node);
            //2) Update the node in path
            node = parent[node];
        }
        //reverse 
        reverse(path.begin(), path.end());
        
        //print path
        cout<<"Printing the path: "<<endl;
        for(auto p : path)
        {
            cout<<p<<"->"; 
        }
        cout<<endl;
    }

    void topoSortDFS(int src, unordered_map<int, bool>& visited, stack<int>& ans)
    {
        visited[src] = true;
        for(auto nbr : adjList[src])
        {
            if(!visited[nbr])
            {
                topoSortDFS(nbr, visited, ans); 
            }
        }
        //backtrack
        ans.push(src);
    }
    //Directed Acyclic Graph
    void shortestPathDFS(int src)
    {
        stack<int> topoOrder;
        unordered_map<int, bool> vis;
        topoSortDFS(src, vis, topoOrder);

        int n = topoOrder.size();
        vector<int> dist(n, INT_MAX);
        //Initial State Maintian
        dist[src] = 0;
        //And src ke neighbour ke dist update karte ho
        for(auto nbr : adjList[src])
        {
            
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 3, 0);
    int src = 0;
    int dest = 3; 
    g.shortestPathBFS(src, dest);
    return 0;
}