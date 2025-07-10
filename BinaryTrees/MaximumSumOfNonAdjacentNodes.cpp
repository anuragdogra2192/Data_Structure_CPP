/** Geeks for geeks

Maximum sum of Non-adjacent nodes

Difficulty: MediumAccuracy: 55.35%Submissions: 90K+Points: 4Average Time: 45m
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105

Time and Space Complexity

Time Complexity

O(N), where N is the number of nodes in the tree.
Each node is visited exactly once, and all operations at each node take constant time.

Space Complexity

O(H), where H is the height of the tree (due to recursion stack).
In the worst case (skewed tree), H = N ⇒ O(N).
In the best case (balanced tree), H = log N ⇒ O(log N).
No extra data structures are used except for recursion.
Summary:

Time: O(N)
Space: O(H) (recursion stack)
*/

#include<iostream>

using namespace std;

// Node Structure
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    pair<int, int> getMaxSumHelper(Node* root)
    {
        if(!root) return {0,0};
        auto left = getMaxSumHelper(root->left);
        auto right = getMaxSumHelper(root->right);
        
        //Sum including the node.
        int sumA = root->data + left.second + right.second;
        //Sum excluding the node.
        int sumB = max(left.first, left.second) + max(right.first, right.second);
        
        return {sumA, sumB};
    }
    
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        // code here
        auto p = getMaxSumHelper(root);
        return max(p.first, p.second);
    }
};
