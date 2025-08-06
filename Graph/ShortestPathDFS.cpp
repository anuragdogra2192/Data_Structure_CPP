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
    unordered_map<int, list<pair<int,int> > > adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        adjList[u].push_back({v, weight});
        if(!direction)
            adjList[v].push_back({u, weight});
    }

    // void printAdjList(int n)
    // {
    //     for(int i=0; i<n; i++)
    //     {   
    //         cout<< i <<" : { ";
    //         for(auto j : adjList[i])
    //         {
    //             cout<< j <<", ";
    //         }
    //         cout<<" } ";
    //     }
    // }

    void topoSortDFS(int src, unordered_map<int, bool>& visited, stack<int>& ans)
    {
        visited[src] = true;
        for(auto nbr : adjList[src])
        {   
            int i = nbr.first;
            if(!visited[i])
            {
                topoSortDFS(i, visited, ans); 
            }
        }
        //backtrack
        ans.push(src);
    }

    //Directed Acyclic Graph, Different Weights.
    //DFS SSP 
    //A Greedy way :)
    //T.C. O(V+E) + O(V+E)(TopoSort)
    void shortestPathDFS(int src)
    {
        stack<int> topoOrder;
        unordered_map<int, bool> vis;
        unordered_map<int, int> parent;//to print path

        topoSortDFS(src, vis, topoOrder);

        int n = topoOrder.size();
        vector<int> dist(n, INT_MAX);
        src  = topoOrder.top();
        topoOrder.pop();
        //Initial State Maintian
        dist[src] = 0;//src to src dist 0.
        parent[src] = -1;
        //And src ke neighbour ke dist update karte ho
        for(auto nbr : adjList[src])
        {   
            //nbr -> pair{a, b}
            //a -> node
            //b -> weight
            int node = nbr.first;
            int weightDistance = nbr.second;
            if(dist[src] + weightDistance < dist[node])
            {
                dist[node] = dist[src] + weightDistance;
                parent[node] = src;
            }
        }

        //Now lets follow the topological ordering
        //Main logic
        while(!topoOrder.empty())
        {
            int frontNode = topoOrder.top();
            topoOrder.pop();
            //Now we will update the dist of its nbr.
            for(auto nbr : adjList[frontNode])
            {
                //nbr -> pair{a, b}
                //a -> node
                //b -> weight
                int node = nbr.first;
                int weightDistance = nbr.second;
                if(dist[frontNode] + weightDistance < dist[node])
                {
                    dist[node] = dist[frontNode] + weightDistance;
                    parent[node] = frontNode;
                }
            }
        }
        //Now we have all dist
        cout<<"Printing Array of weight distance:"<<endl;
        for(auto i : dist)
        {   
            //from to src to dest
            cout<< i <<", ";
        }
        cout<<endl;
        
        //Lets print the path for dest.
        int dest = 2;
        while(dest != -1)
        {
            cout<< dest << " <- ";
            dest = parent[dest]; 
        }
        cout<<endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 13, 1);
    g.addEdge(0, 4, 3, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(1, 4, 1, 1);
    g.addEdge(4, 3, 6, 1);
    g.addEdge(3, 2, 2, 1);
    
    g.shortestPathDFS(0);
    return 0;
}