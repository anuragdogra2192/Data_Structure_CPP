/** Leet Code: 109.
 * 109. Convert Sorted List to Binary Search Tree

Given the head of a singly linked list where elements are sorted 
in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []
 
Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105

Time complexity: O(n)
Space Complexlity: O(n)
*/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// Definition for a binary tree node.
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
    int getLength(ListNode* head)
    {
        int l = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    TreeNode* solve(ListNode*& head, int n)
    {
        if (head == NULL || n <= 0)
        {
            return NULL;
        }
        //LNR inorder
        //L
        TreeNode* leftSubTree = solve(head, n/2);
        //N
        //ab head mid pr khada hoga
        TreeNode* root = new TreeNode(head->val);
        root->left = leftSubTree;
        //head mid pe tha ab use aage bhejo
        head = head->next;
        //R
        //Ab head right part of LL ke start node pr hoga
        TreeNode* rightSubTree = solve(head, n-n/2-1);
        root->right = rightSubTree;
        return root;
    } 

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        TreeNode* root = solve(head, n);
        return root;
    }
};