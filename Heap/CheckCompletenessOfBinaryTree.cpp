/* Leet Code: 958.

958. Check Completeness of a Binary Tree

teda question hai and important hai. it doesnot require heap.
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last,
is completely filled, and all nodes in the last level are
as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 

Constraints:
The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000

Time Complexity
The algorithm performs a level-order traversal (BFS) of the tree.
Each node is visited once.
Total time complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity
The queue can hold up to O(n) nodes in the worst case (for a complete binary tree).
No other significant extra space is used.
Total space complexity:
O(n)
Summary:

Time: O(n)
Space: O(n)
*/

#include<iostream>
#include<queue>
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
    int nodeCount(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l = nodeCount(root->left);
        int r = nodeCount(root->right);
        return 1+l+r ;
    }

    bool isCBT(TreeNode* root, int i,int n)
    {//PreOrder - NLR
        //base case
        if(!root) return true;
        //N
        if(i > n) return false;
        //L
        bool leftAns = isCBT(root->left, 2*i, n);
        bool rightAns = isCBT(root->right, ((2*i)+1), n);
        return leftAns && rightAns;
    }

    bool solve(TreeNode* root)
    {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        //Initial state
        q.push(root);
        bool nullFound = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            if(front == NULL)
            {//null mila hai
                nullFound = true;
            }
            else//front != NULL
            {   
                //agar phele kahi NULL mila hai toh
                if(nullFound == true)
                {
                    //CBT nahi hai
                    return false;
                }
                else
                {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        //agar yaha khai means CBT hai
        return true; 
    }

    bool isCompleteTree(TreeNode* root) {
        int n = nodeCount(root);
        int index = 1;
        return isCBT(root, index, n);
        //return solve(root);
    }
};