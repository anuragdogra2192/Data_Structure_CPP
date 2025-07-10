/* Leet Code: 987.
987. Vertical Order Traversal of a Binary Tree

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 
Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000

Time Complexity
BFS Traversal: Each node is visited exactly once: O(n)
Insertion into map/multiset: For each node, inserting into map<int, map<int, multiset<int>>>:
map insertion is O(log C), where C is the number of columns (≤ n)
multiset insertion is O(log k), where k is the number of nodes at that (row, col)
In the worst case, each insertion is O(log n)
Building the answer: Iterating over the map structure is O(n) (since each node is inserted once).
Total Time Complexity:
O(n log n)

Space Complexity
Map structure: Stores each node once: O(n)
Queue: O(n) in the worst case (BFS)
Answer vector: O(n)
Total Space Complexity:
O(n)

Summary:

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;
//Definition for a binary tree node.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        //.        Nodes.          row. col.    
        queue<pair<TreeNode*, pair<int, int>>> q;
        //Intial state
        q.push({root,{0,0}});

        map<int, map<int, multiset<int>>> mp; //col -> {row, multiset}
        
        while(!q.empty())
        {
            auto frontPair = q.front();
            q.pop();
            auto* frontNode = frontPair.first;
            auto& coordinate = frontPair.second;
            int& col = coordinate.second;
            int& row = coordinate.first;

            //Add in them map
            mp[col][row].insert(frontNode->val);

            if(frontNode->left)
            {
                q.push({frontNode->left,{row+1, col-1}});
            }
            if(frontNode->right)
            {
                q.push({frontNode->right,{row+1, col+1}});
            }
        }
        //finally store vertical order to ans 
        for(auto it:mp)
        {
            auto &colMap = it.second;
            vector<int> vLine;
            for(auto colMapIt : colMap)
            {
                auto& mset = colMapIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};