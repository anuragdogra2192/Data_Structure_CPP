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
    //Shotest path
    //Directed and Undirected Graph
    //Cannot work for -ve weights.
    void sortestDistanceDijkstra(int src, int n)
    {
        vector<int> dist(n+1, INT_MAX);
        set<pair<int, int> > st;
        
        //initial state
        dist[src] = 0;
        st.insert({0, 0});

        //main logic
        while(!st.empty())
        {
            auto topElement = *(st.begin());
            int topTopDist = topElement.first;
            int topNode = topElement.second;

            //pop this node
            st.erase(st.begin());

            //neighbour pr jao
            for(auto nbr : adjList[topNode])
            {
                //nbr is a pair
                //nbr = {a, b}
                //a->node b->wt
                int nbrNode = nbr.first;
                int nbrDist = nbr.second; 
                //Chota hai toh update karo
                if(dist[topNode] + nbrDist < dist[nbrNode])
                {//2 kaam karte hai
                 //set ko update karna hai
                 //purani entry ko delete karo and fir se new add karo
                 auto result = st.find({dist[nbrNode], nbrNode});
                 if(result != st.end())
                 {//entry found 
                  //Remove this entry
                  st.erase(result);
                 }
                 //dist array ko update karna hai
                 dist[nbrNode] = dist[topNode] + nbrDist;
                 //now new entry in set
                 st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            cout<<dist[i]<<", ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 5, 9, 1);
    g.addEdge(0, 3, 6, 1);
    g.addEdge(5, 4, 2, 1);
    g.addEdge(5, 1, 14, 1);
    g.addEdge(4, 3, 11, 1);
    g.addEdge(4, 1, 9, 1);
    g.addEdge(4, 2, 10, 1);
    g.addEdge(3, 2, 15, 1);
    g.addEdge(2, 1, 7, 1);
    
    int V = 6;
    
    g.sortestDistanceDijkstra(0, V);

    return 0;
}