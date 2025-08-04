#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

//list container implements a doubly linked list
using namespace std;

class Graph
{
    public:
    //first int - u
    //second int - v
    //third int - weight
    unordered_map<int, list< pair<int, int> > > adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        if(direction == 0)
        {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight}); 
        }
        else
        {//directed edge
            adjList[u].push_back({v, weight});
        }
    }

    void printAdjList(int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<< i <<": {";
            list<pair<int, int> > temp = adjList[i];
            for(auto j : temp)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<"}"<<endl;
        }
        // for(auto i : adjList)
        // {
        //     cout<< i.first << ": {";
        //     for(auto j : i.second)
        //     {
        //         cout<< j <<", ";
        //     }
        //     cout<<"}"<<endl;
        // }
    }

    void bfsTraversal(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        //initial state
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int frontNode = q.front();
            cout<<frontNode<<", ";
            q.pop();

            for(auto neighbour : adjList[frontNode])
            {
                //neighbour -> pair
                //first -> node
                //second -> weight
                int node = neighbour.first;
                int weight = neighbour.second;
                if(!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }

    void dfsHelper(int src, unordered_map<int, bool>& visited)
    {
        visited[src] = true;
        cout<< src<<", ";
        for(auto neighbour : adjList[src])
        {
            //neighbour -> pair
            //first -> node
            //second -> weight
            int node = neighbour.first;
            if(!visited[node])
            {
                dfsHelper(node, visited);
            }
        }
    }

    void dfsTraversal(int n)
    {
        int src = 0;
        unordered_map<int, bool> visited;
        //Also work for disconnected components
        for(int src=0; src < n; src++)
        {
            if(!visited[src])
            {
                dfsHelper(src, visited);                                                           
            }
            //cout<<endl;
        }
    }
};



int main()
{
    Graph g;
    // g.addEdge(0, 1, 3, 1);
    // g.addEdge(0, 2, 4, 1);
    // g.addEdge(1, 2, 1, 1);
    // g.addEdge(2, 3, 16, 1);
    g.addEdge(0, 3, 6, 1);
    g.addEdge(0, 5, 5, 1);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(2, 5, 3, 1);
    g.addEdge(3, 5, 1, 1);
    g.addEdge(4, 1, 1, 1);
    g.addEdge(5, 4, 1, 1);
    g.addEdge(5, 6, 2, 1);
    g.addEdge(6, 1, 3, 1);
    
    int n = 7;
    g.printAdjList(n);
    g.bfsTraversal(0);

    cout<<"DFS"<<endl;
    g.dfsTraversal(n);

    return 0;
}