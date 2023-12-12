#include<iostream>
using namespace std;

//Binary Tree Class
class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int val)
    {
        this->data = val; 
        this->left = NULL;
        this->right = NULL;
    }
};

//Lets create a Tree
// Return the root of the Tree
Node* CreateTree()
{
    cout<<"Enter the value: "<<endl;
    int data;
    cin>>data;

    //Base Case or exit case 
    // If the value is -1, we will return
    if(data == -1)
    {
        return NULL;
    }
    
    //Step 1: Create the root Node
    Node* root = new Node(data);
    // Remaining will be taken care by recursion
    //Step 2: Create left subtree 
    root->left = CreateTree();
    //Step 3: Create right subtree
    root->right = CreateTree();

    return root;

    /*
    IMPORTANT NOTE:
    First left subtree will be created 
    then only right subtree will be created
    */
}


void PreOrderTraversal(Node* root)
{
    /* 
    Pre order traversal == N L R 
    */
   // Base Case
   if(root==NULL)
   {
        return;
   }
   //N L R
   //N - This I will handle
   cout<< root->data<<" ";
   //Rest recursion will handle
   //L - The Left node
   PreOrderTraversal(root->left);
   //R - The Right node
   PreOrderTraversal(root->right);
}

void InOrderTraversal(Node* root)
{
    /*
    In order traversal == L N R
    */
   if(root == NULL)
   {
        return;
   }

   //L
   InOrderTraversal(root->left);
   //N
   cout<< root->data<<" ";
   //R
   InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
    /*
    Post order traversal == L R N
    */
   if(root==NULL)
   {
        return;
   }
   //L
   PostOrderTraversal(root->left);
   //R
   PostOrderTraversal(root->right);
   //N
   cout<< root->data <<" ";
}
/*
The above traversal has the:
    Time complexity - BigO O(N), worst case scenario the tree will a SKEW TREE
    Space Complexity - O(N), Recursion on Stack

    Moris traversal is the only one which takes Space Complexity O(1) and Time Complexity of O(N)
*/

//LEVEL ORDER TRAVERSAL

int main()
{
    Node* root = CreateTree();
    cout<<root->data<<endl;

    cout<<"Printing PreOrder: "<<endl;
    PreOrderTraversal(root);
    cout<<endl;

    cout<<"Printing InOrder: "<<endl;
    InOrderTraversal(root);
    cout<<endl;

    cout<<"Printing PostOrder: "<<endl;
    PostOrderTraversal(root);
    return 0;
}
