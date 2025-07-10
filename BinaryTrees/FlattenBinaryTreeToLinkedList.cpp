/* Leet Code: 114.
114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode 
class where the right child pointer points 
to the next node in the list and the left child pointer is always null.

The "linked list" should be in the same order 
as a pre-order traversal of the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]
 
Constraints:
The number of nodes in the tree is 
in the range [0, 2000].
-100 <= Node.val <= 100

Time and Space Complexity
Time Complexity
The time complexity of the flatten function is O(N), where N is the number of nodes in the binary tree.

Each node is visited at most twice: once as curr, and possibly again as a predecessor in the inner while loop.
However, the total number of steps across all inner while loops is still O(N), because each right pointer is traversed only once as the tree is being flattened.
Space Complexity
The space complexity is O(1) (constant extra space).

The algorithm uses only a few pointers (curr, predecessor) and does not use recursion or any additional data structures.
The transformation is done in-place, modifying the tree structure directly.
Summary:

Time: O(N)
Space: O(1)
*/

#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left==nullptr)
            {
                curr = curr->right;
            }
            else
            {//left is not null
                TreeNode* predecessor = curr->left;
                while(predecessor->right)
                {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == nullptr)
                {
                    predecessor->right = curr->right;
                    curr->right = curr->left;
                    curr->left = nullptr; 
                    curr = curr->right;
                }
            }
        }   
    }
};