#include<iostream>
/*
Stay motivated and Don't give. You got this.
*********************************************
Add 1 to a number represented as linked list
https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
Add one to the Linked List

One approach:
* reverse + addone + reverseAgain
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

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head; 

    while(curr != NULL)
    {
        Node* nextNode = curr->next; //Don't forget this step
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void addOne(Node* &head)
{
    int carry = 1;
    Node* temp = head;
    while(temp->next!=NULL)
    {
        int total_sum =  temp->data + carry;
        int digit = total_sum % 10;
        carry =  total_sum / 10;
        temp->data = digit;
        
        if(carry == 0)
        {
            break;
        }

        temp = temp->next;
    }

    //process Last node
    if(carry!=0)
    {
        int total_sum =  temp->data + carry;
        int digit = total_sum % 10;
        carry =  total_sum / 10;
        temp->data = digit;
        
        if(carry != 0)
        {
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
}

int main()
{
    Node* head = new Node((9));
    insertAtHead(head, 8);
    //printLL(head);
    //cout<<" Length of the LL: "<< getLength(head) <<endl;
    insertAtHead(head, 1);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;

    head = reverse(head);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;
    
    addOne(head);
    head = reverse(head);
    printLL(head);
    cout<<" Length of the LL: "<< getLength(head) <<endl;
    

    Node* head1 = new Node(9);
    insertAtHead(head1, 9);
    insertAtHead(head1, 9);
    printLL(head1);
    head1 = reverse(head1);
    addOne(head1);
    head1 = reverse(head1);
    printLL(head1);

    Node* head2 = new Node(0);
    insertAtHead(head2, 9);
    insertAtHead(head2, 1);
    printLL(head2);
    head2 = reverse(head2);
    addOne(head2);
    head2 = reverse(head2);
    printLL(head2);

    return 0;
}









