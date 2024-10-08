/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side. Return the right view as a list. 

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Examples :

Input:
       1
    /    \
   3      2
Output: 1 2
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
*/

#include<iostream>
#include<vector>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Should return  right view of tree
class Solution
{
    public:
    
    void solve(Node* root, int level, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(level == ans.size())
        {
            ans.push_back(root->data);
        }
        
        //Right call
        solve(root->right, level+1, ans);
        //Left call
        solve(root->left, level+1, ans);
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans = {};
       solve(root, 0, ans);
       return ans;
    }
};