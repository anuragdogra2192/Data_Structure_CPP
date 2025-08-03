/* Leet code 337.
337. House Robber III

The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, 
return the maximum amount of money the thief can rob 
without alerting the police.

Example 1:
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

Constraints:
The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
*/
//Definition for a binary tree node.

#include<iostream>
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
    int solveRec(TreeNode* root)
    {
        //base case
        if(root == NULL)
        {
            return 0;
        }
        int robThisHouse = 0;
        int dontRobThisHouse = 0;
        //Include, rob current house 
        robThisHouse += root->val;
        if(root->left)
        {
            robThisHouse += solveRec(root->left->left) + solveRec(root->left->right);
        }
        if(root->right)
        {
            robThisHouse += solveRec(root->right->left) + solveRec(root->right->right);
        }
        //Exclude
        dontRobThisHouse += solveRec(root->right) + solveRec(root->left);
        return max(robThisHouse, dontRobThisHouse);
    }
    
    int solveMem(TreeNode* root, unordered_map<TreeNode*, int>& dp)
    {
        //base case
        if(root == NULL)
        {
            return 0;
        }
        if(dp.find(root) != dp.end())
        {
            return dp[root];
        }

        int robThisHouse = 0;
        int dontRobThisHouse = 0;
        //Include, rob current house 
        robThisHouse += root->val;
        if(root->left)
        {
            robThisHouse += solveMem(root->left->left, dp) + solveMem(root->left->right, dp);
        }
        if(root->right)
        {
            robThisHouse += solveMem(root->right->left, dp) + solveMem(root->right->right, dp);
        }
        //Exclude
        dontRobThisHouse += solveMem(root->right, dp) + solveMem(root->left, dp);
        return dp[root] = max(robThisHouse, dontRobThisHouse);
    }

    int rob(TreeNode* root) {
        //return solveRec(root);
        /* For non continuous Data Structure 
            We use non continues DP.
            We use map here
        */
        //1d dp
        unordered_map<TreeNode*, int> dp;
        //Time Complexity: O(n)
        //Space Complexity: rec stack O(n) + dp O(n)
        return solveMem(root, dp);
        /*
        Note: Tree is a top down data structure 
        so there is no point of bottom up approach as we have no link for botton up
        */
    }
};