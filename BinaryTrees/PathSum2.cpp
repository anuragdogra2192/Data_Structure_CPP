/*
Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)
*/

#include<iostream>
#include<vector>
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
    void solve(TreeNode* root, int targetSum, int sum, 
               vector<int>& path, vector<vector<int>>& ans)
    {
        //Pre Order Traversal
        if(root == NULL)
        {
            return;
        }

        // N
        //root is not null
        sum = sum + root->val;
        path.push_back(root->val);

        //check for the leaf node
        if(root->left == NULL && root->right==NULL)
        {
            if(sum == targetSum)
            {
                ans.push_back(path);
            }
            //backtrack
            path.pop_back();
            return;
        }

        solve(root->left, targetSum, sum, path, ans); //L
        solve(root->right, targetSum, sum, path, ans); //R
        
        //backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {   
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, sum, path, ans);

        return ans;     
    }
};