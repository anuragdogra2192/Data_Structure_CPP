/** Geeks for geeks
 Sum of nodes on the longest path
Difficulty: MediumAccuracy: 52.39%Submissions: 124K+Points: 4
Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

Examples:

Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
Output: 13
Explanation:

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Input: root[] = [1, 2, 3, 4, 5, 6, 7]

Output: 11
Explanation: 

The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

Output: 19
Explanation: 

The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104

Time complexity: O(n)
Space compllexity: O(n)
*/

#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    pair<int,int> height(Node* root)
    {
        if(root == nullptr) return {0,0};
        auto lh = height(root->left);
        auto rh = height(root->right);
        int sum = root->data;
        if(lh.first == rh.first)
        {
            sum += lh.second > rh.second ? lh.second : rh.second;
        }
        else if(lh.first > rh.first)
        {
            sum += lh.second;    
        }
        else
        {
            sum += rh.second;
        }
        return {max(lh.first, rh.first) + 1, sum};
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        auto h = height(root);
        return h.second;
    }
};