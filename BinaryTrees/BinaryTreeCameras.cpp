/** Leet Code 968.
968. Binary Tree Cameras

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself,
and its immediate children.

Return the minimum number of cameras needed to monitor
 all nodes of the tree.

Example 1:
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes
of the tree. The above image shows one of the valid configurations of camera placement.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val == 0

Time Complexity
The algorithm visits every node exactly once (post-order traversal).
All operations inside the recursion are O(1) per node.
Total Time Complexity:
O(n), where n is the number of nodes in the tree.

Space Complexity
The recursion stack can go as deep as the height of the tree (h).
Worst case (skewed tree): O(n)
Best/average case (balanced tree): O(log n)
No extra space apart from recursion and a few variables.
Total Space Complexity:
O(h), where h is the height of the tree.

Summary:

Time Complexity: O(n)
Space Complexity: O(h) (worst case O(n), best case O(log n))

*/

#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
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
    int solve(TreeNode* root, int& cameras)
    {
        if(!root) return 1;// all nodes are assumed to be covered
        //Post Order Traversal -- Best One LRN
        int left = solve(root->left, cameras);
        int right = solve(root->right, cameras);

        if(left == 0 || right == 0)
        {
            cameras++;
            //installed camera
            return 2;
        }
        
        if(left == 2 || right == 2)
        {
            return 1; //I am already covered by the child.
        }
        return 0;
    }

    int minCameraCover(TreeNode* root) {
       
       int cameras = 0;
       int rootState = solve(root, cameras);
       if(rootState == 0)// not covered, in case we have only one root.
       {
         cameras++; //Need a camera at root.
       }
       return cameras;
    }
};