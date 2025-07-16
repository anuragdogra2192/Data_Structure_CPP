/** Leet Code 1008.
 * 1008. Construct Binary Search Tree from Preorder Traversal
Important- Interview asked - Adobe. 
Given an array of integers preorder, which represents the 
preorder traversal of a BST (i.e., binary search tree), 
construct the tree and return its root.

It is guaranteed that there is always possible t
o find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, 
any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.

Time Complexity: O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* build(int& i, int lb, int ub, vector<int>& preorder)
    {
        //base case
        if(i >= preorder.size())
        {
            return nullptr;
        }
        //NLR - preorder
        TreeNode* root = nullptr;
        if(preorder[i] > lb && preorder[i] < ub)
        {
            //lets create a new node
            //N
            root = new TreeNode(preorder[i]);
            //i updated
            i++;
            //L
            root->left = build(i, lb, root->val, preorder);
            //R
            root->right = build(i, root->val, ub, preorder);
        }
        return root;
        //anurag dogra
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lb = INT_MIN;
        int ub = INT_MAX;
        int i = 0;//traverse over vector
        return build(i, lb, ub, preorder);
    }
};