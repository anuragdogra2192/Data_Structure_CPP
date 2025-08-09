#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
//Time Complexity: O(V+E) + O(V+E) + O(V+E )
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

    void topologicalSortDFS(stack<int>& st, int node, unordered_map<int, bool>& vis)
    {
        vis[node] = true;
        for(auto nbr : adjList[node])
        {
            if(!vis[nbr])
            {
                topologicalSortDFS(st, nbr, vis);
            }
        }
        //backtrack 
        st.push(node);
    }

    void dfs(int src,  unordered_map<int, bool>& visited, unordered_map<int, list<int> >& adjNew)
    {
        visited[src] = true;
        cout<<src<<"-";
        for(auto nbr : adjNew[src])
        {
            if(!visited[nbr])
            {
                dfs(nbr, visited, adjNew);//yaha mistake hui thi
            }
        }
    }

    int countSCC(int n)
    {
        //find topo Ordering
        stack<int> st;
        unordered_map<int, bool> vis;
        //saare components chahiye
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                topologicalSortDFS(st, i, vis);
            }
        }
        // cout<<"printing the topo sort"<<endl;
        // while(!st.empty())
        // {
        //     cout<<st.top()<<", ";
        //     st.pop();
        // }
        // cout<<endl;

        //Now stack has all the topo ordering
        //step2: Reverse all the edges. so create virtual disconnection.
        unordered_map<int, list<int> > adjNew; //resversed one
        for(auto i : adjList)
        {
            for(auto j : i.second)
            {
                int u = i.first;
                int v = j;
                //u->v edge thi and now reverse it.
                //iska matlab v->u edge banana hai
                adjNew[v].push_back(u);       
            }   
        }

        //traversal
        int count = 0;
        unordered_map<int, bool> visited;

        while(!st.empty())
        {
            int src = st.top();
            st.pop();
            if(!visited[src])
            {
                cout<<"SCC: ";
                dfs(src, visited, adjNew);
                //ek poora component traverse ho chuka hai
                //like find the number of islands wala question.
                cout<<endl;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 3, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    
    int n = 7;
    g.printAdjList(n);

    cout<<"Let us count";

    int sccCount = g.countSCC(n);
    
    cout<<"\n Count: "<<sccCount<<endl;

    
    return 0;
}
