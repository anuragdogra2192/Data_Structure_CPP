/* Geek for geeks:

Diagonal Tree Traversal 
Interview Based

Difficulty: Medium
Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree. 

Examples :

Input : root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : [8, 10, 14, 3, 6, 7, 13, 1, 4]
Explanation:
unnamed
Diagonal Traversal of binary tree : 8 10 14 3 6 7 13 1 4

Input: root = [1, 2, N, 3, N]
                1
               /
              2
             /
            3
Output: [1, 2, 3]
Constraints:
1 <= number of nodes<= 105
1 <= node->data <= 105

Time Complexity
Each node is visited exactly once.
All queue operations (push/pop) are O(1) per node.
Total Time Complexity:
O(n), where n is the number of nodes in the tree.

Space Complexity
The queue can hold up to O(n) nodes in the worst case (if all nodes are left children).
The answer vector stores all node values: O(n).
Total Space Complexity:
O(n)

Summary:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        //Level order style
        vector<int> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front(); q.pop();
            while(temp)
            {
                ans.push_back(temp->data);
                if(temp->left){
                    //baad mein dekhenge
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        return ans;
    }
};