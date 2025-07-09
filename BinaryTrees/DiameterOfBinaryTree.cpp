/*
LEET CODE 543.
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of EDGES between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

TIME COMPLEXITY - O(N^2)

### Time Complexity

Your current implementation of `diameterOfBinaryTree` is **O(N²)**.
- For each node, you recursively compute the diameter for left and right subtrees (**O(N)** calls).
- For each node, you also call `getHeight` on its left and right children, and each `getHeight` is **O(N)** in the worst case.
- So, for each node, you may traverse the subtree multiple times, leading to **O(N²)** total time.

---
### Space Complexity

- The space complexity is **O(h)**, where **h** is the height of the tree (due to the recursion stack).
    - In the worst case (skewed tree): **O(N)**
    - In the best case (balanced tree): **O(log N)**

---

**Summary:**
- **Time Complexity:** O(N²)
- **Space Complexity:** O(h), where h is the height of the tree (worst case O(N), best case O(log N))
*/

/**
 * Definition for a binary tree node.*/

#include<iostream>
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

    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left =  getHeight(root->left);
        int right =  getHeight(root->right);

        int maxHeight = max(left, right);
        int totalHeight = maxHeight + 1;

        return totalHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        //Post order traversal 
        int option1 = diameterOfBinaryTree(root->left); //L
        int option2 = diameterOfBinaryTree(root->right); //R
        int option3 = getHeight(root->left) + getHeight(root->right);

        int maxDiameter = max(option1, max(option2, option3));

        return maxDiameter; //Here we didnot add +1 becuase in question it is asked to claclutae the edges b/w two nodes.
    }
};
//Optimized and fast method: 
//Time Complexity: O(n)
class Solution {
public:
    int D = 0;
    int height(TreeNode* root)
    {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        //Diameter
        int currD = lh + rh;
        D = max(D, currD); 
        return (max(lh, rh)+1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);    
        return D;
    }
};