/* Geeks for geeks

Burning Tree

Difficulty: HardAccuracy: 53.53%Submissions: 119K+Points: 8
Given a binary tree and a target node, 
determine the minimum time required to burn the entire tree if the target node is set on fire. 
In one second, the fire spreads from a node to its left child, right child, and parent.

Note: The tree contains unique values.

Examples : 

Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Time Complexity
O(N), where N is the number of nodes in the tree.
The algorithm traverses the tree twice:
Once to build the parent map and find the target node (BFS, O(N)).
Once to simulate the burning process (BFS, O(N)).
Each node is visited a constant number of times.
Space Complexity
O(N):
The parentMap and isBurnt hash maps both store up to N entries.
The queue used in BFS can hold up to O(N) nodes in the worst case (for a complete binary tree).
No recursion is used, so no recursion stack overhead.
Summary:

Time: O(N)
Space: O(N)
*/
#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* findTargetAndMakeNodeToItsParent(Node* root, int target, 
    unordered_map<Node*, Node*>& parentMap)
    {
        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);
        parentMap[root] = nullptr;
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            if(front->data == target)
            {
                targetNode = front;
            }
            if(front->left)
            {
                q.push(front->left);
                parentMap[front->left] = front;
            }
            if(front->right)
            {
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }
        return targetNode;
    }
    
    int burnTheTree(Node* targetNode,
    unordered_map<Node*, Node*>& parentMap)
    {
        unordered_map<Node*, bool> isBurnt; //already burnt / visited
        queue<Node*> q;
        int T = 0;
        q.push(targetNode);
        isBurnt[targetNode] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto front = q.front();
                q.pop();
                if(front->left && (isBurnt.find(front->left) == isBurnt.end()))
                {
                    q.push(front->left);
                    isBurnt[front->left] = true;
                }
                if(front->right && (isBurnt.find(front->right) == isBurnt.end()))
                {
                    q.push(front->right);
                    isBurnt[front->right] = true;
                }
                if(parentMap[front] && (isBurnt.find(parentMap[front]) == isBurnt.end()))
                {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]];
                }
            }
            if(!q.empty())
            {
                T+=1;
            }
        }
        return T;
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parentMap; //node -> its parent pointers
        Node* targetNode = findTargetAndMakeNodeToItsParent(root, target, parentMap);
        return burnTheTree(targetNode, parentMap);
    }
};