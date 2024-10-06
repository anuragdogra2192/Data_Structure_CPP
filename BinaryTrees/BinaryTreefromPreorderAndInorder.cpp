/* LEET CODE
105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int& preOrderIndex, int inOrderStart, int inOrderEnd,int size, unordered_map<int, int>& valMap) 
    // valMap by reference pass kiya hai other wise it will take to much time ==> Time Limit Exceeded
    {
        //base case
        if(preOrderIndex >= size)
        {
            return NULL;
        }
        if(inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        //Step1: process first element of a "preorder" as root
        //Get the element from preOrder and create root as a node for it.
        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);

        //Step2: Find this element inside inOrder and call for left and right
        int elementIndexInsideInOrder = valMap[element];
        //int elementIndexInsideInOrder = getIndex(inorder, element);

        //inorder left part --> index: inOrderStart to elementIndexInsideInOrder-1
        //inorder right part --> index: elementIndexInsideInOrder+1 to inOrderEnd
        root->left = constructTree(preorder, inorder, preOrderIndex, inOrderStart, elementIndexInsideInOrder-1, size, valMap);

        root->right = constructTree(preorder, inorder, preOrderIndex, elementIndexInsideInOrder+1, inOrderEnd, size, valMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd =  inorder.size()-1;
        int size = preorder.size();

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);
        TreeNode* root = constructTree(preorder, inorder, preIndex, inOrderStart, inOrderEnd, size, valMap);
        
        return root;
    }
};