#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

//list container implements a doubly linked list
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction)
    {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        if(direction == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }
        else
        {//directed edge
            adjList[u].push_back(v);
        }
    }

    void printAdjList(int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<< i <<": {";
            list<int> temp = adjList[i];
            for(auto j : temp)
            {
                cout<< j <<", ";
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

    bool cycleDetectionUnDirectedBFS(int src, unordered_map<int, bool>& visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;
        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        //Main logic
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
                //cycle detection case
                else if(visited[nbr] == true && parent[frontNode] != nbr)
                {//cycle found
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    //Undirected Graph
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(2, 3, 0);
    int n = 4;
    g.printAdjList(n);
    
    unordered_map<int, bool> visited;
    bool ans = false;
    //handling disconnected components
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            ans = g.cycleDetectionUnDirectedBFS(i, visited);
            if(ans == true)
            {
                break;
            }
        }
    }

    if(ans == true)
    {
        cout<<"Cycle is present" <<endl;
    }
    else
    {
        cout<<"Cycle is absent" <<endl;
    }
    return 0;
}