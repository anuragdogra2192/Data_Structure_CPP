/**
 * Leet Code 103.
103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

Time Complexity
Each node is visited exactly once during the traversal.
All queue operations (push/pop) are O(1) per node.
For each level, filling the currLevelAns vector is O(width of level), which sums to O(n) over all levels.
Total Time Complexity:
O(n), where n is the number of nodes in the tree.

Space Complexity
The queue can hold up to the maximum number of nodes at any level (the tree's width), which is O(n) in the worst case.
The answer vector stores all node values: O(n).
The currLevelAns vector is O(width of current level), but this is O(n) over all levels.
Total Space Complexity:
O(n)

Summary:

Time Complexity: O(n)
Space Complexity: O(n)

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        //Maintaining the initial state
        bool LeftToRight = true;
        q.push(root);
        while(!q.empty())
        {   
            int curr_level_width = q.size(); 
            vector<int> currLevelAns(curr_level_width);
            for(int i=0; i<curr_level_width; i++)
            {//Travese all the nodes at this level
                auto front = q.front(); q.pop();
                int index = LeftToRight ? i : curr_level_width-i-1;
                //LeftToRight -> true means index : 0 -> width-1
                //LeftToRight -> false means index : width-i-1 --> 0
                currLevelAns[index] = front->val;

                if(front->left != NULL)
                {
                    q.push(front->left);
                }
                if(front->right != NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(currLevelAns);
            //Now toggle the direction
            LeftToRight = !LeftToRight;
        }
        return ans;
    }
};