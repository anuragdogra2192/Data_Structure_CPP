/* Geeks for geeks.
Inorder Successor in BST

https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

Given a BST, and a reference to a Node k in the BST. 
Find the Inorder Successor of the given node in the BST. 
If there is no successor, return -1. 

Examples :

Input: root = [2, 1, 3], k = 2
      2
    /   \
   1     3
Output: 3 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.
Input: root = [2, 1, 3], k = 3
      2
    /   \
   1     3
Output: -1 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 3 is null.
Constraints:
1 <= n <= 105, where n is the number of nodes

Using property of BST,
Time Complexity: O(log n) or O(h)
Space Complexity: O(1) 
*/

#include<iostream>
using namespace std;

//The structure of Node
struct Node {
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
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        Node* succ = nullptr;
        Node* curr = root;
        while(curr)
        {
            if(curr->data > x->data)
            {
                succ = curr; //Store and compute
                curr = curr->left;
            }
            else//curr->data < x->data
            {
                curr = curr->right;
            }
        }
        if(succ)
        {
            return succ->data;
        }
        return -1;
    }
};