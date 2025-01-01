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
        left = NULL;
        right = NULL;
    }
};

Node* buildBST(Node* root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    else
    {// Maintaing the BST property
        if(val < root->data)
        {//val --> left subtree 
            root->left = buildBST(root->left, val);
        }
        else //val > root->data --> right subtree
        {
            root->right = buildBST(root->right, val);
        }
    }
    return root;
}

void createTree(Node*& root)
{
    cout <<"Enter the root element of the tree: "<<endl;
    int val; 
    cin>>val;

    while(val != -1)
    {
        root = buildBST(root, val);
        cout << "Element to be inserted: "<<endl;
        cin >> val;
    }
}

void levelOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if(front==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }        
        else //front != NULL 
        {
            cout<<front->data<<" ";
            if(front->left != NULL)
            {
                q.push(front->left);
            }
            if(front->right !=NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int getMax(Node* root)
{//Extreme right contains the maximum element
    if(root == NULL)
    {
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }
    //Now we are at the rightmost node
    return root->data;
}

//Time Complexity of deleteNode() = O(N) - Average Case, O(N^2) - Worst Case
Node* deleteNode(Node* root, int target)
{
    if(root == NULL) return NULL;

    //Node found
    if(root->data == target)
    {
        //Case1 - No children left and right
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //Case2 - Left child
        if(root->left != NULL && root->right == NULL)
        {
            Node* leftNode = root->left;
            delete root;
            return leftNode; 
        }
        //Case3 - Right child
        if(root->left == NULL && root->right != NULL)
        {
            Node* rightNode = root->right;
            delete root;
            return rightNode;
        }
        //Case4 - Both children available
        if(root->left != NULL && root->right != NULL)
        {   
            //Predecessor
            //target node ke left subtree ka maximum element
            int leftMax = getMax(root->left);
            root->left = deleteNode(root->left, leftMax);
            root->data = leftMax;
            return root;
            
            //Similarly, we can also use the successor
            //Successor
            //target node ke right subtree ka minimum element
            //int rightMin = getMin(root->right);
            //root->right = deleteNode(root->right, rightMin);
            //root->data = rightMin;
            //return root;
        }
    }
    else
    {
        if(target < root->data)
        {
            root->left = deleteNode(root->left, target);
        }
        else //target > root->data
        {   
            root->right = deleteNode(root->right, target);
        }
    }
    return root;
}


int main()
{
    Node* root = NULL;
    createTree(root);
    levelOrderTraversal(root);
    cout<<endl;
    int target;
    cout<<"Enter the element to be deleted: "<<endl;
    cin>>target;
    while(target != -1)
    {
        root = deleteNode(root, target);
        levelOrderTraversal(root);
        cout<<endl;
        cout<<"Enter the element to be deleted: "<<endl;
        cin>>target;
    }
    return 0;
}

//Input: 100 90 500 80 400 70 85 300 450 470 -1
//LeetCode 450. Delete Node in a BST - https://leetcode.com/problems/delete-node-in-a-bst/
