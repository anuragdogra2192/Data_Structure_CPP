/*Leet code 973.
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] 
represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is 
the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. 
The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:
1 <= k <= points.length <= 104
-104 <= xi, yi <= 104

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class DistComp
{
    public:
    bool operator()(pair<int, int>& a, pair<int,int>& b) 
    {//comparing the distance more closer to origin (0, 0)
        int distA = ((a.first * a.first) + (a.second * a.second));
        int distB = ((b.first * b.first) + (b.second * b.second));
        return (distA > distB);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

       vector<vector<int>> ans;

       priority_queue<pair<int,int>, vector<pair<int,int>>, DistComp>minHeap;

        for(auto p : points)
        {
            minHeap.push({p[0], p[1]});
        }
        while(!minHeap.empty() && k>0)
        {
            auto& top = minHeap.top();
            ans.push_back({top.first, top.second});
            minHeap.pop();
            k--;
        }
        return ans;
    }
};