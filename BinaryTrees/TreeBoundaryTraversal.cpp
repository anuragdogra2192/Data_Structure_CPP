//Geeks for Geeks
//Tree Boundary Traversal
//QUESTION BEGINS HERE:
/*

Tree Boundary Traversal 

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:
Input:
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

As you can see we have not taken the right subtree. 
Your Task:
This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

#include<iostream>
#include<vector>
using namespace std;

// A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    
    void LeftBoundary(Node* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        //Avoiding the leaf nodes
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        
        //Pushing the nodes
        ans.push_back(root->data);
        
        if(root->left != NULL)
        {
            LeftBoundary(root->left, ans);   
        }
        else//if not left then rightsub of the left side
        {
            LeftBoundary(root->right, ans);
        }
    }
    
    void RightBoundary(Node* root, vector<int>& ans)
    { 
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return; //leaf nodes
        }
        
        if(root->right != NULL)
        {
            RightBoundary(root->right, ans);   
        }
        else //if not right then leftsub of the right side
        {
            RightBoundary(root->left, ans);
        }
        
        //Pushing the nodes while goinf backward --> backtrack
        //As we need to store the value reversively
        
        ans.push_back(root->data);
    }
    
    void LeafBoundary(Node* root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        //Let's store now the leaf nodes data
        if(root->left == NULL && root->right == NULL)
        {
            //Leaf Node
            ans.push_back(root->data);
        }
        
        LeafBoundary(root->left, ans);
        LeafBoundary(root->right, ans);
    }
    
    
    
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root == NULL)
        {
            return ans;
        }
        
        //Step A: Root Node
        ans.push_back(root->data);
        //Step B: Left Subtree --> left boundary
        LeftBoundary(root->left, ans);
        //Step C: Left Subtree, --> Leaf boundary
        LeafBoundary(root->left, ans);
        //Step D: Right Subtree, --> Leaf boundary
        LeafBoundary(root->right, ans);
        //Step E: Right Subtree, --> Right Boundary
        RightBoundary(root->right, ans);
        
        return ans;
    }
};