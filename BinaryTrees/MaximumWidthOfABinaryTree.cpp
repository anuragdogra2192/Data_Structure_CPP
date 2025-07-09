/** Leet Code: 662.
 * 662. Maximum Width of Binary Tree
 * 
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:
The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100

Time Complexity
The algorithm performs a level order traversal (BFS) of the tree.
Each node is visited exactly once.
All queue operations (push/pop) are O(1) per node.
Total Time Complexity:
O(n), where n is the number of nodes in the tree.

Space Complexity
The queue stores at most all nodes at the widest level of the tree.
In the worst case (a complete binary tree), the queue can hold up to O(n/2) = O(n) nodes at the last level.
Total Space Complexity:
O(n)

Summary:

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include<iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */

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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth = 0;
        //Edge case if root is null
        if(!root) return NULL;
        queue<pair<TreeNode*, int>> q;
        //maintaining the initial state
        q.push({root, 1});
        while(!q.empty())
        {
            unsigned long long size = q.size();//current level, number of nodes
            unsigned long long leftMostNodeIndex = q.front().second;
            unsigned long long rightMostNodeIndex = q.back().second;
            unsigned long long currentLevelWidth = rightMostNodeIndex - leftMostNodeIndex + 1;
            maxWidth = max(maxWidth, currentLevelWidth);

            //Traverse over all nodes at the current level
            for(unsigned long long i=0; i<size; i++)
            {
                auto front = q.front();
                q.pop();
                auto node = front.first;
                unsigned long long index = front.second;
                //process its child and assign its index
                if(node->left)
                {
                    q.push({node->left, index*2});
                }
                if(node->right)
                {
                    q.push({node->right, (index*2+1)});
                }
            } 
        }
        return maxWidth;
    }
};