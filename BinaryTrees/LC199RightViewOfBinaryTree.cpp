/* Leet Code 199.
199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:


Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:

Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
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
    void solve(TreeNode* root, int level, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == ans.size())
        {
            ans.push_back(root->val);
        }
        //As we need right side view
        solve(root->right, level+1, ans);
        solve(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};