/* Geeks for geeks
Is Binary Tree Heap
https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.

Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<queue>
using namespace std;

// Structure of node
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
    bool isMax(Node* root)
    {//Post order
        if(root == nullptr) return true;
        if(root->left == NULL && root->right == NULL)
        {
            //means leaf node hai 
            return true;
        }
        //L
        bool leftAns = isMax(root->left);
        //R
        bool rightAns = isMax(root->right);
        //N
        //property check at curr node
        bool option1 = true;
        if(root->left && root->data < root->left->data)
        {
            option1 = false;
        }
        bool option2 = true;
        if(root->right && root->data < root->right->data)
        {
            option2 = false;
        }
        
        bool currAns = option1 && option2;
        if(currAns && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isComplete(Node* root)
    {
        if(root == nullptr) return true;
        queue<Node*> q;
        //Initial state
        q.push(root);
        bool nullFound = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            if(front == NULL)
            {//null mila hai
                nullFound = true;
            }
            else//front != NULL
            {   
                //agar phele kahi NULL mila hai toh
                if(nullFound == true)
                {
                    //CBT nahi hai
                    return false;
                }
                else
                {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        //agar yaha khai means CBT hai
        return true; 
    }
    bool isHeap(Node* tree) {
        // code here
        bool complete = isComplete(tree);
        bool max = isMax(tree);
        if(max && complete)
        {
            return true;
        }
        return false;
    }
};