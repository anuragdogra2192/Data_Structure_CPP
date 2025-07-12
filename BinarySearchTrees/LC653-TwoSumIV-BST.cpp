/*
Leet code 653. Two Sum IV - Input is a BST
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

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

Time Complexity: O(N) - N is the number of nodes in the BST + Two pointer O(n)
Space Complexity: O(N) - N is the number of nodes in the BST
*/

#include<iostream>
#include<vector>

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
    //Approach - InOrder traversal ---> gives sorted list and put it in a vector. Apply 2 pointers approach.
    
    //InOrder traversal - LNR
    void storeInOrder(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
        {
            return;
        }
        //L
        storeInOrder(root->left, inorder);
        //N
        //Store in vector
        inorder.push_back(root->val);
        //R
        storeInOrder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> inorder;
        storeInOrder(root, inorder);

        int s = 0;
        int e = inorder.size() - 1;
        while(s<e)
        {
            int sum = inorder[s] + inorder[e];
            if(sum == k)
            {
                return true;
            }

            if(sum > k)
            {
                e--;
            }

            if(sum < k)
            {
                s++;
            }
        }
        return false;
    }
};