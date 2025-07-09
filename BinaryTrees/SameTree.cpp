/** Leet Code: 100.
 * 100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 
Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

Time Complexity: O(n)
Space Comlexity: O(n)

Time Complexity
Each node in both trees is visited exactly once.
For n nodes, the function does O(1) work per node.
Total Time Complexity:
O(n), where n is the total number of nodes in the trees.

Space Complexity
The recursion stack can go as deep as the height of the tree.
Worst case (skewed tree): O(n)
Best/average case (balanced tree): O(log n)
Total Space Complexity:
O(n) (worst case, due to recursion stack)

Summary:

Time Complexity: O(n)
Space Complexity: O(n) (worst case)
*/

#include<iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Case 1: if both are NULL
        if(p==NULL && q==NULL)
        {
            return true;
        }
        //Case 2: Both are not null
        if(p && q)
        {   
            //Check both val are same
            bool sameVal = false;
            if(p->val == q->val)
            {
                sameVal = true;
            }
            bool sameLeft = isSameTree(p->left, q->left);
            bool sameRight = isSameTree(p->right, q->right);
            return (sameVal && sameLeft && sameRight);
        }
        //Case 3: If one is NULL and other is not.
        //if((!p && q) || (p && !q))
        //means false;
        return false;
    }
};