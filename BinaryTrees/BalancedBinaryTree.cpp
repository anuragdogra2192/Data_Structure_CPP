/*
Balanced Binary Tree
Height-Balanced
A height-balanced binary tree is a binary tree in which the depth of the two subtrees 
of every node never differs by more than one.

Given a binary tree, determine if it is 
height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 
Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
 */

#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node. */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // TIME COMPLEXITY O(N^2)
class Solution {

// balanced means each node has abs(leftHeight - rightHeight)<=1
public:
    int getHeight(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        //LRN Post Order Traversal
        int lh = getHeight(root->left); //L
        int rh = getHeight(root ->right); //R
        int ansLength = max(lh, rh) + 1; //N

        return ansLength;
    }

    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
        {
            return true;
        }

        // NLR PreOrder Traversal

        // N -->  current node pe aake ne check karte hai 
        //current node check
        //Lets take care of one case and remaining will be done by recurssion

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int absDiff = abs(lh - rh);
        bool status = (absDiff <= 1);

        //L --> Left subtree check
        bool leftAns = isBalanced(root->left);

        //R --> Right subtree check
        bool rightAns = isBalanced(root->right);

        /*
        I can say tree is balanced or not
        When: currNode is balanced
            & leftSubtree is balanced
            & rightSubtree is balanced 
        */

        if(status && leftAns && rightAns)
        {
            return true;
        }
        else
            return false;
    }

};

//Optimized and Best&fast way to solve.
//Time Complexity: O(n)
class Solution {
public:
    int getHeight(TreeNode* root, bool& isBalanced)
    {
        if(root == NULL) return 0;
        int lh = getHeight(root->left, isBalanced);
        int rh = getHeight(root->right, isBalanced);
        //check for current node, is it balanced?
        //by default I assumed that its true.
        if(isBalanced && abs(lh - rh)>1)
        {
            isBalanced = false;
        }
        return (max(lh, rh) + 1);
    }

    bool isBalanced(TreeNode* root) {   
        if(root == NULL) return true;
        bool isBalanced = true;
        int height = getHeight(root, isBalanced);
        return isBalanced;
    }
};