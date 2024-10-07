/* LEET CODE
106. Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1] 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
TIME COMPLEXITY : O(N)
SPACE COMPLEXITY : O(N)
*/


#include<iostream>
#include <unordered_map>
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

    void createMapping(unordered_map<int, int>& valMap, const vector<int>& inorder) {
        valMap.reserve(inorder.size()); 
        for (int i = 0; i < inorder.size(); ++i) {
            valMap[inorder[i]] = i;
        }
    }

    int getIndex(vector<int> inorder, int element)
    {
        for(int i = 0; i<inorder.size(); i++)
        {
            if(inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& postorder, vector<int>& inorder, int& postOrderIndex, int inOrderStart, int inOrderEnd,int size, unordered_map<int, int>& valMap) 
    // valMap by reference pass kiya hai other wise it will take to much time ==> Time Limit Exceeded
    {
        //base case
        if(postOrderIndex < 0)
        {
            return NULL;
        }

        if(inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        //Step1: process first element of a "preorder" as root
        //Get the element from preOrder and create root as a node for it.
        int element = postorder[postOrderIndex];
        postOrderIndex--;
        TreeNode* root = new TreeNode(element);

        //Step2: Find this element inside inOrder and call for right and left R-->L
        int elementIndexInsideInOrder = valMap[element];
        //int elementIndexInsideInOrder = getIndex(inorder, element);

        //inorder right part --> index: elementIndexInsideInOrder+1 to inOrderEnd
        //inorder left part --> index: inOrderStart to elementIndexInsideInOrder-1

        //right call
        root->right = constructTree(postorder, inorder, postOrderIndex, elementIndexInsideInOrder+1, inOrderEnd, size, valMap);
        //left call
        root->left = constructTree(postorder, inorder, postOrderIndex, inOrderStart, elementIndexInsideInOrder-1, size, valMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1; //last index to 0; R --> L
        int inOrderStart = 0;
        int inOrderEnd =  inorder.size()-1;
        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);
        int size = inorder.size();

        TreeNode* root = constructTree(postorder, inorder, postIndex, inOrderStart, inOrderEnd, size, valMap);
        
        return root;
    }
};