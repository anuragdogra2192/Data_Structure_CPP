/*Leet code 787.
787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
 
Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.

The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 
Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

Using Dijkstra algo.
//Also can be done using Bellmann Ford. Hint relaxation steps = k+1; only.
*/
#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //lets make the adjList
        unordered_map<int, list<pair<int, int> > > graph;
        for(auto& f : flights)//by ref is always better
        {
            int u = f[0];
            int v = f[1];
            int price = f[2];
            graph[u].push_back({v, price});
        }
        //priorityqueue (minHeap) to select the next city with minimal cost
        //each element would be: {cost so far, current city, stops so far}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        //maintiaining intial state
        pq.push({0, src, 0});
        
        //Array storing the minimum number of stops to reach to a city
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;  

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0]; //total cost so far
            int currCity = curr[1];// current city
            int stops = curr[2];//number of stops so far
            if(currCity == dst)
            {
                return cost;
            }
            //if stops exceed k than we skip this path, means continue
            if(stops > k)
            {
                continue;
            }
            //if we have already visited the city with fewer stops, then we skip this path.
            if(visited[currCity] < stops)
            {
                continue;
            } 
            
            //update the minimum stops for the current city.
            visited[currCity] = min(visited[currCity], stops);

            //explore all neighbour cities.
            for(auto nbr : graph[currCity])
            {
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost+price, nextCity, stops + 1});
            }
        }
        return -1;
    }
};