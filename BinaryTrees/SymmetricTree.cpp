/** Leet Code 101.
 * 101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

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
    bool isMirror(TreeNode* p, TreeNode* q)
    {   
        //Case 1: Both are NULL
        if(!p && !q)
        {
            return true;
        }
        //Case 2: Both are not NULL
        if(p != NULL & q != NULL)
        {
            bool sameVal = false;
            if(p->val == q->val)
            {
                sameVal = true;
            }
            bool pLeft_qRight = isMirror(p->left, q->right);
            bool pRight_qLeft = isMirror(p->right, q->left);
            return (sameVal && pLeft_qRight && pRight_qLeft);
        }
        //if one of them is null and other not null
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};