#include<iostream>

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

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

void print(Node* head)
{
    Node* temp = head; 
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void insertAtHead(Node* &head, Node* &tail, int data)
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
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
}

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
        newNode->prev = tail;
        tail = newNode;
    }
}

//Time complexity - O(N), as we need to traverse to that point.
//Space complexity - O(1), we are only creating the temp nodes
void insertAtPosition(Node* &head, Node* &tail, int data, int pos)
{
    int length = getLength(head);
    if(pos<=1)
    {
        insertAtHead(head, tail, data);
    }
    else if(pos>length)
    {
        insertAtTail(head, tail, data);
    }
    else //in the middle or given position
    {
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* currNode = head;

        while(pos!=1)
        {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }   
}

/**
 * Deletion
 * from Head 
 * from tail 
 * from the given position
 * when there is single element 
*/

void deleteNode(Node* &head, Node* &tail, int pos)
{
    if(head == NULL)
    {
        std::cout<<"Cannot delete as the doubly linked list is empty"<<std::endl;
        return;
    }

    if(head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    
    int length = getLength(head);
    if(pos>length)
    {
        std::cout<<"Pos is > than length of DLL, can't delete "<<std::endl;
        return;
    }
    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        //Node isolation is a good practice
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    else if(pos == length)
    {
        Node* prevNode = tail->prev;
        //Node isolation
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        //Setting the new tail
        tail = prevNode;
    }
    else
    {
        Node* prevNode = NULL;
        Node* currNode = head;
        while(pos != 1)
        {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        //Let update the pointers
        Node* temp = currNode->next;
        prevNode->next = temp;
        temp->prev = prevNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }
}

int main()
{
    Node* head = new Node(20);
    Node* tail = head;
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 30);

    insertAtPosition(head, tail, 25, 3);
    insertAtPosition(head, tail, 35, 4);
    insertAtPosition(head, tail, 5, 1);
    insertAtPosition(head, tail, 40, 7);

    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;

    deleteNode(head, tail, 1);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;
    
    deleteNode(head, tail, 6);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;

    deleteNode(head, tail, 3);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;

    deleteNode(head, tail, 3);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;

    deleteNode(head, tail, 3);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;

    deleteNode(head, tail, 3);
    deleteNode(head, tail, 1);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;
    deleteNode(head, tail, 1);
    print(head);
    std::cout<<"Length of the LL: "<<getLength(head)<<std::endl;
    deleteNode(head, tail, 1);
    return 0;
}   

/**
 * Circular doubly linked list
 * tail->next = head;
 * head->prev = tail;
*/