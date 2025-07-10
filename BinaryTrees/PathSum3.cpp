/** Leet Code 437.
 * 437. Path Sum III
 * 
Given the root of a binary tree and an integer targetSum,
return the number of paths where the sum of the values
along the path equals targetSum.

The path does not need to start or end at the root or a leaf,
but it must go downwards (i.e., traveling only from parent nodes to child nodes).


Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000

Time Complexity
For each node, you call pathFromOneRoot, which traverses all nodes in its subtree.
For a tree with n nodes, this results in O(n) work per node in the worst case.
So, the total time complexity is O(n²).
Space Complexity
The maximum recursion depth is the height of the tree, which is O(h).
In the worst case (skewed tree), h = n ⇒ O(n)
In the best case (balanced tree), h = log n
No extra data structures are used apart from recursion.
Total Space Complexity:
O(h) (worst case O(n), best case O(log n))

Summary:

Time Complexity: O(n²)
Space Complexity: O(h) (worst case O(n), best case O(log n))
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
    int ans = 0;
    void pathFromOneRoot(TreeNode* root, long long sum)
    {
        if(!root) return;
        if(sum == root->val)
        {
            ans++;
        }
        
        pathFromOneRoot(root->left, sum- root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        if(root!=NULL)
        {   
            //NLR
            pathFromOneRoot(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};