/*
GEEK FOR GEEKS
LEFT VIEW OF BINARY TREE

Given a Binary Tree, return its Left view. The left view of a Binary Tree is a set of nodes 
visible when the tree is visited from the Left side. 
If no left view is possible, return an empty array.

Examples :

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, 8]
          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   
Output: [1, 2, 4, 8]
Explanation: When we view the tree from the left side, we can only see the nodes 1, 2, 4, and 8.
Input: root[] = [1, 3, N, N, 4]
Output: [1, 3, 4]
Input: root[] = [N]
Output: []
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105 
*/

/* A binary tree node */
#include<iostream>
#include<vector>

using namespace std;

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

//Function to return a list containing elements of left view of the binary tree.
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
    
    //Left call 
    solve(root->left, level+1, ans);
    
    //right call
    solve(root->right, level+1, ans);
}

vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    solve(root, 0, ans);
    
    return ans;
}