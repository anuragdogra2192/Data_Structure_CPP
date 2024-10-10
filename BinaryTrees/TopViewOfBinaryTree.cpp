/*GEEKS FOR GEEKS
TOP VIEW OF A BINARY TREE
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Our Case its better.
Time Complexity: O(N)
Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105
 */

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>

//#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        //Queue to add Nodes at all levels
        queue<pair<Node*, int>> q;
        
        //Initial state  maintain, node and its distance
        q.push(make_pair(root, 0));
        
        //Mapping: At a particular dist --> a node
        unordered_map<int, Node*> dist_map;
        
        //rule => left(-1), right(+1) in distance
        /* 
        * Same verticle line nodes are in same distance
        * Sabse uppermost wala index lena hai
        */
        int min_dist = INT_MAX;
        int max_dist = INT_MIN;
        
        while(!q.empty())
        {
            //Front pair
            pair<Node*, int> front_pair = q.front();
            Node* frontNode = front_pair.first;
            int hd = front_pair.second;
            
            q.pop(); //removing from queue
            
            min_dist = min(hd, min_dist);
            max_dist = max(hd, max_dist);
            
            
            if(dist_map.find(hd) == dist_map.end()) //for this dist, there is no entry
            {
                dist_map[front_pair.second] = front_pair.first;
            }
            
            //Left 
            if(frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            //Right 
            if(frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        
        vector<int> topVal{};
        if(!dist_map.empty())
        {
            for(int i = min_dist; i <= max_dist; i++)
            {
                topVal.push_back(dist_map[i]->data);
            }    
        }
        return topVal;
    }

};