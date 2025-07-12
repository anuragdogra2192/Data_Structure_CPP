/* Leet code 235.
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2
 
Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.

Time Complexity: O(log n)
*/


#include<iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        //Case A:
        //p and q both on left side
        //right --> neglect and left ---> select
        if(p->val < root->val && q->val < root->val)
        {// go to the left
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            if(leftAns != NULL)
            {//valid ans
                return leftAns;
            }
        }
        //Case B:
        //p and q both on right side
        if(p->val > root->val && q->val > root->val)
        {// go to the right
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            if(rightAns != NULL)
            {//valid ans
                return rightAns;
            }
        }
        //Case C: 
        //p is on the left and q is on the right
        //Case D: 
        //q is on the right and p is on the left
        return root;
    }
};