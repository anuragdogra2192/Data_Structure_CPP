/* Leet code: 108
108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted 
in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

Time Complexity
Each element of the array is visited once to create a node.
The recursive function splits the array in half each time (like binary search).
Total time complexity:
O(n), where n is the number of elements in the array.
Space Complexity
O(log n) for the recursion stack (since the tree is height-balanced).
O(n) for the output tree nodes (but this is required for the result, not extra space).
Auxiliary space (excluding output):
O(log n) (recursion stack for a balanced tree).
Summary:

Time: O(n)
Space: O(log n) auxiliary (O(n) total including output tree)
*/

#include<iostream>
#include<vector>
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
    TreeNode* solve(vector<int>& inorder, int s, int e)
    {
        if(s > e)
        {
            return nullptr;
        }
        //1 case mein solve karta huin 
        int mid = s+((e-s)/2);
        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);
        //baaki recursion sambhal lega
        root->left = solve(inorder, s, mid-1);
        root->right = solve(inorder, mid+1, e);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& inorder) {
        int s = 0;
        int e = inorder.size()-1;
        
        TreeNode* root = solve(inorder, s, e);
        return root;
    }
};