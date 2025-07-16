/* Leet code 1373.
1373. Maximum Sum BST in Binary Tree

Given a binary tree root, return the maximum sum of all keys of any 
sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:
The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104

Time Complexity: O(n)
Space Complexity: O(n) Recursion.
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

class Info
{   
    public:
    int minVal;
    int maxVal;
    bool isBST;
    int sum;
};

class Solution {
public:
    Info solve(TreeNode* root, int& sumAns)
    {
        //Base case
        if(root == NULL)
        {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.isBST = true;
            temp.sum = 0;
            sumAns = max(temp.sum, sumAns);
            return temp;
        }
        //Leaf node condition not required , optional.
        // if(root->left == NULL && root->right == NULL)
        // {
        //     Info temp;
        //     temp.minVal = root->val;
        //     temp.maxVal = root->val;
        //     temp.isBST = true;
        //     temp.sum = root->val;
        //     sumAns = max(temp.sum, sumAns);
        //     return temp;
        // }
        //LRN
        Info leftAns = solve(root->left, sumAns);
        Info rightAns = solve(root->right, sumAns);
        //N lets process on the current node
        Info currentAns;
        currentAns.minVal = min(min(leftAns.minVal, rightAns.minVal), root->val);
        currentAns.maxVal = max(max(leftAns.maxVal, rightAns.maxVal), root->val);
        currentAns.sum = leftAns.sum + rightAns.sum + root->val;
        currentAns.isBST = (leftAns.isBST && rightAns.isBST && (root->val > leftAns.maxVal) && (root->val < rightAns.minVal));

        if(currentAns.isBST)//True
        {
            sumAns = max(currentAns.sum, sumAns);
        }
        return currentAns;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};