/**
 * @brief LeeeCode 1038. Binary Search Tree to Greater Sum Tree
 * 1038. Binary Search Tree to Greater Sum Tree
 
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 
Constraints:
The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.

Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/

// Definition for a binary tree node.
*/
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

class Solution {
public:
    //Time Complexity - O(N)
    void storeInOrder(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
        {
            return;
        }
        //LNR
        storeInOrder(root->left, inorder);
        inorder.push_back(root->val);
        storeInOrder(root->right, inorder);
    }
    //Time Complexity: O(N) - N is the number of nodes in the BST
    void updateTree(TreeNode* root, vector<int> inorder, int &index)
    {
        if(root == NULL)
        {
            return;
        }
        //LNR 
        updateTree(root->left, inorder, index);
        root->val = inorder[index];
        index++;
        updateTree(root->right, inorder, index);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }

        if(root->left == NULL && root->right == NULL)
        {
            return root;
        }
        //Step1: Store InOrder
        vector<int> inorder;
        storeInOrder(root, inorder);

        //Time Complexity: O(N) - N is the number of nodes in the BST
        //Step2: Update the InOrder as per question rules
        int n = inorder.size();
        for(int i = n-1; i >=0 ; i--)
        {
            int currentVal = inorder[i];
            int nextVal = 0;
            if(i+1 < n)
            {
                nextVal = inorder[i+1];
            }
            int sum = currentVal + nextVal;
            inorder[i] = sum;
        }        

        //Step3: Update tree using inorder
        int index = 0;
        updateTree(root, inorder, index);
        return root;
    }
};
