/*
Property of Binary Search Tree:
1) Left node is always smaller than the root node and right node is always greater than the root node.
   (left node -> val) < (root node -> val) < (right node -> val)
2) Inorder traversal of a BST gives a sorted array.
*/

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

//O(logN) - Average Case, O(N) - Worst Case
Node* buildBST(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }
    else
    {
        if(val < root->data)
        {
            root->left = buildBST(root->left, val);
        }
        else if(val > root->data)
        {
            root->right = buildBST(root->right, val);
        }
    }
    return root;
}

//O(N) - Average Case, O(N^2) - Worst Case
void createTree(Node*& root)
{
    cout<<"Enter the root element of the tree: "<<endl;
    int val;
    cin>>val;

    while (val != -1)
    {    
        root = buildBST(root, val);
        cout<<"Enter the element to be inserted: "<<endl;
        cin >> val;
    }
}

//O(N) - Time Complexity and O(N) - Space Complexity
void levelOrderTraversal(Node* root)
{
    if(root ==NULL)
    {
        return;
    }

    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<< front->data<<" ";
            if(front->left != NULL)
            {
                q.push(front->left);
            }
            if(front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}


//PreOrderTraversal - NLR
void preOrderTraversal(Node* root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//InOrderTraversal - LNR
void inOrderTraversal(Node* root)
{
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//PostOrderTraversal - LRN
void postOrderTraversal(Node* root)
{
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

//ReverseInOrderTraversal - LNR
void reverseInOrderTraversal(Node* root)
{
    if(root == NULL) return;
    reverseInOrderTraversal(root->right);
    cout<<root->data<<" ";
    reverseInOrderTraversal(root->left);
}

int main()
{
    Node* root = NULL; //Empty Tree, the line Node* root = NULL; does not call any constructor. It simply declares a pointer to a Node object and initializes it to NULL
    createTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder Traversal: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"NOTE: InOrder Traversal gives always a sorted tree: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    postOrderTraversal(root);
    cout<<endl;
    cout<<"ReverseInOrder Traversal gives decreasing (reverse sorted) tree: ";
    reverseInOrderTraversal(root);
    cout<<endl;
    return 0;
}