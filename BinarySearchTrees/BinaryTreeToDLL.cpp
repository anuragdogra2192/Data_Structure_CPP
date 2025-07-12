/** Geek for geeks
 * Binary Tree to DLL

 Interview question.

 Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. 
The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
Time Complexity: O(n)
Not extra sapce is used.
 */

#include<iostream>
using namespace std;
// Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    } 
};


// This function should return head to the DLL
class Solution {
  public:
    //RNL Approach
    void solve(Node* root, Node*& head)
    {
        if(root == NULL)
        { 
            return;
        }
        //R
        solve(root->right, head);
        //assume karke chal raha huin ki right mein LL bangayi hai
        //N
        root->right = head;
        if(head != NULL)
        {
            head->left = root;
        }
        head = root;
        //L
        solve(root->left, head);
    }
    //LNR Apporach - inorder
    void solve(Node* root, Node*& head, Node*& tail)
    {
        if(root == NULL)    
        {
            return;
        }
        //L
        solve(root->left, head, tail);
        //Assumption: left wali LL ban gayi hai
        //Head and Tail ko upfate karna hoga 
        //connect Karne hoga 
        //N
        if(tail != NULL)
        {
            tail->right = root;
            root->left = tail;
            tail = root;
        }
        else
        {//ab tak ki LL empty hai, yaani first node hai
            //Ab first node insert hogi. 
            tail = root;
            head = root;
        }
        //R
        solve(root->right, head, tail);
    }
    
    Node* bToDLL(Node* root) {
        // code here
       Node* head = NULL;
       //RNL
       //solve(root, head);
       Node* tail = NULL; 
       solve(root, head, tail);
       return head;
    }
};