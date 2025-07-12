/* 
Leet code 230. Kth Smallest Element in a BST

230. Kth Smallest Element in a BST

Interview Question. 

Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) 
and you need to find the kth smallest frequently, how would you optimize?

Time complexity: O(n)

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

class Solution {
public:
    void solve(TreeNode* root, int k, int &count, TreeNode*& ans)
    {
        if(root == NULL)
        {
            return;
        }
        //LNR
        //L
        solve(root->left, k, count, ans);
        //N
        count++;
        if(count == k)
        {
            ans = root;
        }
        //R
        solve(root->right, k, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* ans = NULL;

        solve(root, k, count, ans);
        return ans->val;
    }
};

//Other way:
class Solution {
public:
    void inOrder(TreeNode* root, int& k, int& ans)
    {
        if(root == NULL)
        {
            return;
        }
        //L
        inOrder(root->left, k, ans);
        //N
        k--; //yaha mistake hui thi
        if(k == 0)
        {
            ans = root->val;
            return;
        }
        //R
        inOrder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        if(root == NULL)
        {
            return ans;
        }
        inOrder(root, k, ans);
        return ans;
    }
};