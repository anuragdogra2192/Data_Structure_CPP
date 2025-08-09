#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<vector>
#include<limits.h>

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

    //Multiple Source Shotest path (SSSP)
    //Directed and Undirected Graph
    //Time Complexity O(N^3)
    void FloydWarshallAlgo(int n)
    {
        vector<vector<int> > dist(n, vector<int>(n, 1e9));
        //step1: diagonal set to zero
        for(int i=0; i<n; i++)
        {
            dist[i][i] = 0;
        }
        //step2: copy all distance to the matrix
        for(auto a : adjList)
        {
            for(auto b : a.second)
            {//a -> <pair<int, list< pair<int, int> > >;
             //a.first = u
             //a.second -> nbr of u -> list <pair <int, int>>;
            //b -> pair<int, int>
            //b.first -> v;
            //b.second -> weight;
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
        //Main logic
        for(int helper=0; helper<n; helper++)
        {
            for(int u=0; u<n; u++)
            {
                for(int v=0; v<n; v++)
                {
                    dist[u][v] = min(dist[u][v], dist[u][helper] + dist[helper][v]);
                }
            }
        }
        cout<<"printing result of the FW algo: "<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }   

};

int main()
{
    Graph g;
    g.addEdge(0, 2, -2, 1);
    g.addEdge(1, 0, 4, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(3, 1, -1, 1);
    g.addEdge(2, 3, 2, 1);
    
    int V = 4;
    g.FloydWarshallAlgo(V);

    return 0;
}