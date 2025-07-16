/**
 * BST with Dead End
 * https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

 You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.
Input: root[] = [8, 7, 10, 2, N, 9, 13]

Output: true
Explanation: Node 9 is a Dead End in the given BST.
Constraints:
1 ≤ number of nodes ≤ 3000
1 ≤ node->data ≤ 105

Time Complexity: O(n)

Time Complexity
The function traverses every node in the BST exactly once using recursion.
All operations at each node are O(1).
Total time complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity
The space used is mainly due to the recursion stack.
In the worst case (skewed tree), the recursion stack can go up to O(n).
In the best case (balanced tree), the recursion stack is O(log n).
No extra data structures are used.
Total space complexity:
O(n) worst case (O(log n) for balanced tree, due to recursion stack).
Summary:

Time: O(n)
Space: O(n) worst case (O(log n) for balanced tree)
*/

#include<iostream>
using namespace std;

//The Node structure is
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void solve(Node* root, int lb, int ub, bool& ans)
    {
        //pre Order
        if(root == nullptr) return;
        //N
        if(root->left == NULL && root->right == NULL)
        {//check deadEnd
            if((root->data - lb == 1) && (ub - root->data == 1))
            {
                ans = true;
                return;
            }
        }
        //L
        solve(root->left, lb, root->data, ans);
        //R
        solve(root->right, root->data, ub, ans);
    }
    
    bool isDeadEnd(Node *root) {
        // Code here
        int lb = 0; //as values are > 0
        int ub = INT_MAX;
        bool ans = false;
        solve(root, lb, ub, ans);
        return ans;
    }
};