/** Leet code 450.
 * 450. Delete Node in a BST
 * 
Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?
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
    int getMin(TreeNode* root)
    {
        if (root == NULL)
        {
            return -1;
        }
    
        while(root->left != NULL)
        {
            root = root->left;
        }
        // Now we have reached the leftmost node
        return root->val;
    }

    int getMax(TreeNode* root)
    {//Extreme right contains the maximum element
        if(root == NULL)
        {
            return -1;
        }
        while(root->right != NULL)
        {
            root = root->right;
        }
        //Now we are at the rightmost node
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
       if(root == NULL) 
       {
            return NULL;
       }
       if(root->val == key)
       {//Now we need to delete the node
        //cases:
        //with 0 child
        if(root->left == NULL && root->right==NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        //with left child only
        if(root->left != NULL && root->right==NULL)
        {
            TreeNode* leftChild = root->left;
            root->left = NULL;//Isolate 
            delete root;
            root = leftChild;
            return root;
        }
        //with right child only
        if(root->left == NULL && root->right != NULL)
        {
            TreeNode* rightChild = root->right;
            root->right = NULL;//Isolate 
            delete root;
            root = rightChild;
            return root;
        }
        //with both left and right child
        if(root->left != NULL && root->right != NULL)
        {   
            //Predecessor way
            // //to find root ka just chota element 
            // int maxVal = getMax(root->left);
            // //replace root node's value with maxVal
            // root->val = maxVal;
            // //delete the actual node
            // root->left = deleteNode(root->left, maxVal);
            // return root;

            //Succesor way
            //to find root ka just bada element
            int minVal = getMin(root->right);
            root->val = minVal;
            root->right = deleteNode(root->right, minVal);
            return root;
        }
       }
       else //Not match
       {
            if(key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            if(key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            return root;
       }
       return NULL;
    }
};