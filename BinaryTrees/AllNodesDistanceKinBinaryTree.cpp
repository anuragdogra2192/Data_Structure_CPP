/** Leet code: 863
 * 863. All Nodes Distance K in Binary Tree
 *
Given the root of a binary tree, the value of a target node target,
and an integer k, return an array of the values of all nodes
that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
 
Constraints:
The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

Time Complexity
mapParent: Traverses all nodes once to build the parent map: O(n)
BFS from target: Visits each node at most once: O(n)
All other operations (queue, map lookups) are O(1) per node.
Total Time Complexity:
O(n), where n is the number of nodes in the tree.

Space Complexity
parentMap: O(n) (stores a parent pointer for each node)
visited map: O(n) (stores a visited flag for each node)
queue: O(n) in the worst case (if all nodes are at distance ≤ k)
ans vector: O(n) in the worst case (if all nodes are at distance k)
Total Space Complexity:
O(n)

Summary:
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void mapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left)
        {
            parentMap[root->left] = root;
        }
        if(root->right)
        {
            parentMap[root->right] = root;
        }
        mapParent(root->left, parentMap);
        mapParent(root->right, parentMap);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = NULL;
        mapParent(root, parentMap);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        //To maintain the inital state
        q.push(target);// kyunki target se shuru kar rahe hai
        visited[target] = true;

        int currentLevel = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(currentLevel == k)
            {
                break;
            }
            currentLevel++;
            //Traverse over all nodes at the current level
            for(int i=0; i<size; i++)
            {
                auto front = q.front(); q.pop();
                if(front->left && visited.find(front->left) == visited.end())
                {//front has its left child and it has not been visited.
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && visited.find(front->right) == visited.end())
                {//front has its right child and it has not been visited.
                    q.push(front->right);
                    visited[front->right] = true;
                }

                //lets process the parent of front
                auto parentNodeOfFront = parentMap[front];
                if(parentNodeOfFront && visited.find(parentNodeOfFront) == visited.end())
                {//front has its right child and it has not been visited.
                    q.push(parentNodeOfFront);
                    visited[parentNodeOfFront] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};