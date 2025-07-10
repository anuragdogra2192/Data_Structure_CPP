/** Leet code: 94.
 * 94. Binary Tree Inorder Traversal

 Morris traversal for Inorder
Space Complexity: O(1), Time Complexity: O(n)

Given the root of a binary tree, return the inorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include<iostream>
#include<vector>

using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 //Morris traversal - Space Complexity: O(1), Time Complexity: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return ans;
        TreeNode* curr = root;
        while(curr)
        {
            //L left is null
            if(curr->left == nullptr)
            {   //N 
                ans.push_back(curr->val);
                //R mein jao
                curr = curr->right;
            }
            else
            {//agar left hai toh
                //Step1: Find the predecessor, ek baar LEFT jao 
                //then RIGHT jate jao till null mil jaye.
                TreeNode* predecessor = curr->left;
                while(predecessor->right != curr && predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                //Step2: If Right node of predecessor is null then
                //establish the link FROM predecessor TO curr Node.
                //Finally curr go left.
                if(predecessor->right == nullptr)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else //agar Right node is not null
                {
                    //left is already visited, go right after visiting the curr and remove the Link.
                    predecessor->right = nullptr;//remove link
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};