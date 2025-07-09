/** Geeks for geeks
    Bottom View of Binary Tree
Difficulty: MediumAccuracy: 54.18%Submissions: 310K+Points: 4Average Time: 45m
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

For the above tree, the output should be 5 8 34 22 25

Examples :

Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input: root[] = [10, 20, 30, 40, 60]
         
Output: [40 20 60 30]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        //to maintain intial state
        q.push({root, 0}); //root ka dist 0 hai
        
        unordered_map<int, Node*> distMap;//To keep O(1) search complexity
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        //Level Order Traversal
        while(!q.empty())
        {
            pair<Node*, int> frontPair = q.front();
            q.pop();
            Node* frontNode = frontPair.first;
            int horizontalDist = frontPair.second;
            
            minDist = min(minDist, horizontalDist);
            maxDist = max(maxDist, horizontalDist);
            
            
            //Update Node belong to that horizontalDist
            distMap[horizontalDist] = frontNode;
            
            //Rule: left -1 and right +1
            if(frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left, horizontalDist-1));
            }
            
            if(frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right, horizontalDist+1));
            }
        }
        
        vector<int> ans;
        for(int i=minDist; i<=maxDist; i++)
        {
            Node* root = distMap[i];
            ans.push_back(root->data);
        }
        return ans;
    }
};