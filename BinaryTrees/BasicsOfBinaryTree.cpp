#include<iostream>
#include<queue>
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
            this->left = NULL;
            this->right = NULL;
        }
};

/* 
Fact:
Trees: A non-linear data structure which is basically a
combination of nodes in hierarchical form or order.

Nodes are connected using pointers.

Binary Tree has at most 2 children, it cannot have more than
2 (binary know :) ). 

Sub part of a tree is called subtree.

Implementation of Binary tree:
Tu tree mein ek node laga de baki Recursion sambhalega.

Input: 
10, 
    10L-20      
    10R-30
20,
    20L-40
    20R-50
40,
    40->-1 or NULL
50, 
    50L-90
    50R-100 
30,
    30L-60
    30R-70

                 10
               /    \
              20     30
             /  \    /  \
           40    50 60   70
                /  \
               90  100

Root node: 10
Leaf nodes: 40, 90, 100, 60, 70
Sibling nodes: They are the ones who have same parent.
               Example: 20 and 30 are siblings with parent 10.
Ancestors of 90: 50, 20 and 10
Descendent of 30: 60 and 70
50 and 60 are neighbours
*/ 

//Lets create a Tree
//Return the root of the Tree
Node* CreateTree()
{
    cout<<"Enter the value: "<<endl;
    int data;
    cin>>data;
    
    //Base Case
    // In our case if the user provide -1 as an input
    // means user doesnot want to add a node, se we add/set to NULL. 
    //-1 input karnege toh exit karenge 
    if(data == -1)
    {
        return NULL;
    }
    
    //1k case hum karenge
    //Step 1: Create the root Node
    Node* root = new Node(data);
    //Baki Recursion Sambhal lega
    //Step 2: Create the left subtree
    cout<<"Left of Node: "<<root->data<<endl;
    root->left = CreateTree();
    //Step 3: Create the right subtree
    cout<<"Right of Node: "<<root->data<<endl;
    root->right = CreateTree();

    return root;
    /*
    IMPORTANT NOTE:
    First left subtree will be created 
    then only the right subtree will be created.
    */
}


/*
Traversals in Binary tree
N - current Node
L - Left Node
R - Right Node

1) Pre-Order - N L R
2) In-Order -  L N R
3) Post- Order L R N
*/
void PreOrderTraversal(Node* root)
{
    //NLR
    //base case
    if(root == NULL)
    {
        return;       
    }
    //N L R
         //N - ye mein karunga
    /*N*/cout<< root->data <<" ";
        //L and R baaki recursion sambhalega
    /*L*/PreOrderTraversal(root->left);
    /*R*/PreOrderTraversal(root->right);
}

void InOrderTraversal(Node* root)
{
//LNR
    //Base Case:
    if(root == NULL)
    {
        return;
    }
    /*L*/InOrderTraversal(root->left);
    /*N*/cout<<root->data<<" ";
    /*R*/InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
//LRN
    //Base case
    if(root == NULL)
    {
        return;
    }
    /*L*/PostOrderTraversal(root->left);
    /*R*/PostOrderTraversal(root->right);
    /*N*/cout<<root->data<<" ";
}
/*
Time Complexity of Traversals:
BigO(N) 
//stack pe recurssion ki wajah se Space Complexity:
O(N)

Worst case scenario mein SKEW Tree Traverse kar rahe ho
Example of Skew Tree:
    O
     \
      O
       \
        O
         \
          O
Moris traversal is the only traversal which takes
space complexity of O(1) and time complexity of O(N).
*/

/*
NEXT TOPIC:
    Level order traversal
    * For Level we use the "queue"  
    * Initial state will be mainted by pushing the root node in the queue at the beginning
    * Steps:
    * A) Take the node out of queue
    * B) Print the node val
    * C) Then put/push its children in the queue 
*/

void LevelOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*> q;

    //maintain intial state
    q.push(root);
    //To print in levels let add "NULL" to break the level 
    q.push(NULL);

    //Now lets follow the steps A, B and C
    while(!q.empty())
    {
        //Step A: Take the node out of queue
        Node* front = q.front();
        //remove the node from the queue
        q.pop();
        //Let put some condition for print node nicely in levels
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
            //Step B Print the node val
            cout<<front->data<<" ";
            //Step C Then put/push its children in the queue 
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

int main()
{
    Node* root = CreateTree();
    cout<<"Root val: "<<root->data<<endl;
    /*
    Input - 10,20,40,-1,-1,-1,30,50,-1,-1,60,-1,-1
    */
    cout<<"\n Pre Order Traversal: "<<endl;
    PreOrderTraversal(root);
    cout<<"\n In Order Traversal: "<<endl;
    InOrderTraversal(root);
    cout<<"\n Post Order Traversal: "<<endl;
    PostOrderTraversal(root);
    cout<<"\n Level Order Traversal: "<<endl;
    LevelOrderTraversal(root);
    return 0;
}

