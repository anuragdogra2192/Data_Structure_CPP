#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
#include<vector>
//Bridge in Graph 
//Tarjan's Algorithm 
using namespace std;
class Graph
{
    public:
    unordered_map<int, list<int> >adjList;

    void addEdge(int u, int v, bool direction)
    {
        //direction = 1, directed edge
        if(direction == 1)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList(int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<< i << "-> { ";
            for(auto nbr : adjList[i])
            {
                cout<<nbr<<", ";
            }
            cout<<"}"<<endl;
        }
    }

    void countBridges(int src, int parent, vector<int>& tin, vector<int>& low, 
        unordered_map<int, bool>& vis, int timer)
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
                countBridges(nbr, src, tin, low, vis, timer);
                //ab mein yaha se wapas aya toh, let check for the bridge.
                low[src] = min(low[src], low[nbr]);//yeah bhul jata huin
                if(low[nbr] > tin[src])
                {//bridge exists
                    cout<<"Bridge found"<<endl;
                    cout<< nbr << "-" << src <<endl;
                }
            }
            else
            {//already visited and not a parent 
             //low time ko update kardo if possible
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    
    int n = 5;
    g.printAdjList(n);

    cout<<"Lets find the bridge(s) "<<endl;  
    int src = 0;
    int parent = -1;
    vector<int>tin(n, 0);
    vector<int>low(n, 0); 
    unordered_map<int, bool>vis;
    int timer;
    g.countBridges(src, parent, low, tin, vis, timer);
    
    return 0;
}
/*
Output 
0-> { 1, 2, }
1-> { 0, 2, 3, }
2-> { 1, 0, }
3-> { 1, 4, }
4-> { 3, }
Lets find the bridge(s) 
Bridge found
4-3
Bridge found
3-1 
*/