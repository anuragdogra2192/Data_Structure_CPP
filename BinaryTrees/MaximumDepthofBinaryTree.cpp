/* LEET CODE 104

104. Maximum Depth of Binary Tree / Height of the Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

Time Complexity: O(N)
The space complexity of the maxDepth function is O(h), where h is the height of the binary tree.

This is due to the recursion stack. In the worst case (a skewed tree), the stack can go as deep as the number of nodes (O(n)).
In the best/average case (a balanced tree), the stack depth is O(log n).
Summary:

Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree (worst case O(n), best case O(log n))

Dry Run with Post Order to understand
*/


#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.*/

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
    int maxDepth(TreeNode* root) {

        //base case
        if(root == NULL)
        {
            return 0;
        }

        //LRN -- Post Order Traversal
        int leftSubtreeHeight = maxDepth(root->left); //Left
        int rightSubtreeHeight = maxDepth(root->right); //Right

        int maxHeight = max(leftSubtreeHeight, rightSubtreeHeight); //Node
        int totalHeight = maxHeight + 1;

        return totalHeight;
    }
};

