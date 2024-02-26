#include<iostream>
/*
Stay motivated and Don't give.  You got this.

Array has a continous memory and sometimes memory used to be wasted for example
in case of vector, its always allocate extra mem.

Here comes the linked list to help us

Linked List:
* Its a linear data structure
* Non continous memory allocation
* LL has less memory wastage than array
* Insert / Shift has Time Complexity of O(1), be we need to go to the location
* Run time / dynamically grow and shrink
* It is the collection of nodes

Remember linkedlist is like a language, we talk what we code. 

Normally, in coding problem, we only miss a simple edge case.
*/

using namespace std;
class Node
{
    public:
        int data;
        Node* next;
    
    Node()
    {
        this->next = NULL;
        cout<<"I am at the default constructor\n";
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        cout<<"I am at the parameterized constructor\n";
    }

    ~Node()
    {
        cout<<"Destructor called for: "<<this->data<<endl;
    }
};

//Lets print LL
//void printLL(Node** temp)//call by reference
void printLL(Node* head)
{
    Node* temp = head;
    /* Tip: A good practice
    Whenever the node* is given to us, head, tail or any
    we should not use the original pointer, 
    we always make a temp pointer out of it.
    */
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//"Insertion"
//Insert at the head
void insertAtHead(Node* &head, int data)
{
    /*
    Tip: 
    Always do pass by reference.
    Node*& head
    */
    if(head != NULL)
    {
        Node* newNode = new Node(data);// 100->
        newNode->next =  head;// 100->10
        head = newNode;
    }
    else//if LL is empty
    {
        Node* newNode = new Node(data);
        head = newNode;
    }
}

/*
Empty LL means Head and Tail are both NULL
Single Element means Head and Tail are SAME.
*/
//Insert at the tail
void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

//Insert at the position,
void insertAtPosition(Node* &head, Node* &tail, int data, int pos)
{
    int length = getLength(head);

    if(pos <= 1)
    {
        insertAtHead(head, data);
    }
    else if(pos > length)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        //Insert in the middle
        //step1: create a new node
        Node* newNode = new Node(data);
        //step2: traverse prev to new Node
        Node* prev = NULL;
        Node* curr = head;

        while(pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = newNode;
        newNode->next = curr;
    }

}

/*
 * Deletion
 * Deletion from head
 * Deletion from tail
 * Deletion from middle
*/
void deleteNode(Node* &head, Node* &tail, int pos)
{
    int length = getLength(head);
    //empty list 
    if(head == NULL)
    {
        cout<<"Can't delete, Linked list is empty"<<endl;
        return;
    }
    //handling single element case
    if(head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    if(pos == 1)//delete the first node
    {
        Node* temp = head;
        //second node will be the head now
        head = head->next;
        //Disconnect / detach the old head
        temp->next = NULL;
        //Lets delete the old head
        delete temp;
    }
    else if(pos == length) // delete the last node
    {
        //To delete the last node we need to go to previous node to the last node
        Node* prev = head;
        while(prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    else //delete 
    {
        Node* prev = NULL;
        Node* curr = head;
        while(pos!=1)
        {
            prev=curr;
            curr=curr->next;
            pos--;
        }
        prev->next = curr->next;
        //detach the curr
        curr->next = NULL;
        //delete
        delete curr;
    }
}

int main()
{
   //Creating the Nodes 
    Node* first = new Node(10);
    //Node a; //Static allocated objected 
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth =  new Node(50);

    //let connect the nodes to create a LL
    Node* head = first;
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* tail = fifth;

    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    insertAtHead(head, 100);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    // Node* head2 = NULL;
    // insertAtHead(head2, 100);
    // printLL(head2);
    // cout<<" Length of the LL: "<< getLength(head2) <<endl;

    insertAtTail(head, tail, 100);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    insertAtPosition(head, tail, 1000, 7);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    insertAtPosition(head, tail, 1100, 9);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    insertAtPosition(head, tail, 1200, 3);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    insertAtPosition(head, tail, 0, 1);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    deleteNode(head, tail, 1);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    deleteNode(head, tail, 10);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    deleteNode(head, tail, 8);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    return 0;
}

/**
 * Circular Linked list
 * tail->next = head; 
*/