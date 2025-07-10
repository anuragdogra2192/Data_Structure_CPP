/** Leet Code: 652
 * 652. Find Duplicate Subtrees

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 
Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200

Time Complexity
Let n be the number of nodes in the tree.

Each node is visited once in the preOrder traversal: O(n)
At each node, you build a string representing the subtree rooted at that node.
In the worst case (highly unbalanced tree), the string can be up to O(n) in length.
But, for a balanced tree, the average string length is O(log n).
Inserting and searching in the unordered_map is O(1) on average, but the string hashing/comparison can take up to O(n) per node in the worst case.
Worst-case time complexity:

O(n²) (if the tree is skewed and subtree strings are long)
Average case: O(n) for balanced trees
Space Complexity
The unordered_map stores up to O(n) unique subtree strings, each of which can be up to O(n) in length (in the worst case).
The ans vector stores up to O(n) pointers to duplicate subtree roots.
The recursion stack can go up to O(n) deep (for a skewed tree).
Worst-case space complexity:

O(n²) (for the map storing all subtree strings)
Average case: O(n) (for balanced trees and short strings)
Summary:

Time: O(n²) worst case, O(n) average
Space: O(n²) worst case, O(n) average

*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
    vector<TreeNode*> ans;
    unordered_map<string, int> subTree;
public:
    string preOrder(TreeNode* root)
    {
        if(!root) return "N";
        string curr = to_string(root->val);//N
        string l = preOrder(root->left);//L
        string r = preOrder(root->right);//R
        string s = curr + "," + l + "," + r;

        //insert in map
        if(subTree.find(s) != subTree.end())
        {//already there
            if(subTree[s] == 1)
            {
                ans.push_back(root);
            }
            subTree[s]++;
        }
        else
        {// New entry
            subTree[s] = 1;
        }
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        preOrder(root);
        return ans;
    }
};