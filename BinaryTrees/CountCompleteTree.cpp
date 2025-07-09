/** Leet code: 222
 * 222. Count Complete Tree Nodes
Important - Interview type.

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

Time Complexilty: O((log n)^2) ~ O(log^2 n) ~ always less < O(n) 
*/

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
    int findLeftHeight(TreeNode* root)
    {
        int count = 0;
        while(root)
        {   
            count++;
            root = root->left;
        }
        return count;
    }

    int findRightHeight(TreeNode* root)
    {
        int count = 0;
        while(root)
        {   
            count++;
            root = root->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh)
        {
            return (1 << rh)-1; //2^rh - 1  in bitwise.
        }
        //if lh!= rh
        //ans = 1 + (lans) + (lans)
        int lans = countNodes(root->left);
        int rans = countNodes(root->right);

        return lans + rans + 1;
    }
};