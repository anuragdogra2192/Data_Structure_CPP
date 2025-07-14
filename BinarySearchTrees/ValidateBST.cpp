/* Leet code 98.
98. Validate Binary Search Tree
MEGA BST CLASS
Important concept: Range checking.
IMPORTANT for INTERVIEW.

Given the root of a binary tree, determine if it is a 
valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

Time Complexity: O(n)
Space Complexity: O(n) Recurssion
 */

#include<iostream>
#include<limits.h>
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
    bool validate(TreeNode* root, long long lb, long long ub)
    {
        if(!root)
        {
            return true; //BST hai
        }
        //N
        //Range checking
        bool isCurrentNodeInRange = (root->val > lb && root->val < ub);
        if(isCurrentNodeInRange == false)
        {
            return false;
        }
        bool leftBST = validate(root->left, lb, root->val);
        bool rightBST = validate(root->right, root->val, ub);

        return (isCurrentNodeInRange && leftBST && rightBST);
    }

    //Short hand of the above code
    bool validate2(TreeNode* root, long long lb, long long ub)
    {
        if(!root) return true; //BST hai
        return (root->val > lb && root->val < ub) 
        && validate(root->left, lb, root->val)
        && validate(root->right, root->val, ub);
    }

    bool isValidBST(TreeNode* root) {
        //Range checking
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        //return validate(root, lb, ub);
        return validate2(root, lb, ub);
    }
};