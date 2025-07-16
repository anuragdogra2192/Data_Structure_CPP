/** Leet Code 783.
 * 783. Minimum Distance Between BST Nodes
Nice Interview question.
Given the root of a Binary Search Tree (BST),
return the minimum difference between the values of any two 
different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
 
Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 
Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
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
 
class Solution {
public:
    void solve(TreeNode* root, int& ans, TreeNode*& prev)//prev by ref bhejna imp hai.
    {//Inorder
        if(root == nullptr){return;}
        //L 
        solve(root->left, ans, prev);
        //N
        if(prev != nullptr) //not null hai tabhi karo
        {
            ans = min(ans, (root->val - prev->val));
        }
        //update prev ko
        prev = root;

        //R
        solve(root->right, ans, prev);
    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;//Min Diff
        TreeNode* prev = nullptr;
        solve(root, ans, prev);
        return ans;
    }
};
