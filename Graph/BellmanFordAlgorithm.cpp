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

    //Single Source Shotest path (SSSP)
    //Directed and Undirected Graph
    //Can detect for -ve weights.
    //Time Complexity O(N)(N-1)

    void BellmanFordAlgo(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        //n-1 times 
        dist[src] = 0;
        for(int i=0; i<n-1; i++)
        {//Hr edge pr jao ans relaxation step karo
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
                    //Remember dist[u] != INT_MAX
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        //Checking for negetive cycle
        bool negativeCyclePresent = false;
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
                //Remember dist[u] != INT_MAX
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    negativeCyclePresent = true;
                    break;
                }
            }
        }
        if(negativeCyclePresent)
        {
            cout<<"-ve cycle present"<<endl;
        }
        else
        {
            cout<<"-ve cycle not present"<<endl;
        

            for(int i=0; i<n; i++)
            {
                cout<<dist[i] <<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, -1, 1);
    g.addEdge(1, 4, 2, 1);
    g.addEdge(0, 2, 4, 1);
    g.addEdge(3, 2, 5, 1);
    g.addEdge(4, 3, -3, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(1, 3, 2, 1);
    g.addEdge(3, 1, 1, 1);
    
    int V = 5;
    g.BellmanFordAlgo(0, V);

    Graph g1;
    g1.addEdge(0, 1, -1, 1);
    g1.addEdge(1, 0, -2, 0);
    g1.BellmanFordAlgo(0, 2);
    return 0;
}