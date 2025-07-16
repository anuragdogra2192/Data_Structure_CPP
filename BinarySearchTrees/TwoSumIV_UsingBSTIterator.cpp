/* Leet Code 653.
 * 653. Two Sum IV - Input is a BST
 
 Highly important - Interview Asked frequently

 MEGA BST CLASS - Really a good one.
 
Given the root of a binary search tree and an integer k, 
return true if there exist two elements in the BST 
such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false 

Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
 */

#include<iostream>
#include<stack>
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

//Solving using BST Iterator.
//Space complexity:
//Average case mein now; O(h) - height
//Worst case O(n)

//MEGA BST CLASS.
class BSTIterator {
    stack<TreeNode*> st;
    stack<TreeNode*> rst;
    void pushLeftNodes(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
    void pushRightNodes(TreeNode* root)
    {
        while(root)
        {
            rst.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
        pushRightNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();
        if(top->right != NULL)
        {
            pushLeftNodes(top->right);
        }
        return top->val;
    }

    int before()
    {   
        auto top = rst.top();
        rst.pop();
        if(top->left != NULL)
        {
            pushRightNodes(top->left);
        }
        return top->val;
    }

    bool hasNext() {
        if(st.empty())
        {
            return false;
        }
        return true;
    }

    bool hasBefore()
    {
        if(st.empty())
        {
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);
        int i = it.next(); //smallest L-R 
        int j = it.before(); //Largest R-L

        while(i<j)
        {
            int sum = i+j;
            if(sum == k)
            {
                return true;
            }
            else if(sum < k)
            {
                i = it.next();
            }
            else
            {
                j = it.before();
            }
        }
        return false;
    }
};