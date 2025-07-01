#include<iostream>
using namespace std;

class DeCircularQueue
{
    public:
    int* arr;
    int n;
    int front;
    int rear;

    DeCircularQueue(int size)
    {
        n = size;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void pushFront(int val)
    {
        //OverFlow
        if((front == 0 && rear ==n-1) || rear == front-1)
        {//rear == front-1 bhul jata huin.
            cout<<"overflow"<<endl;
        }
        //First Element
        else if(front == -1  && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        //Circular nature
        else if(front ==0 && rear !=n-1)
        {
            front = n-1;
            arr[front] = val;
        }
        //normal flow
        else{
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val)
    {
        //4 cases:  Overflow, first Element, circular nature, normal flow.
        if((front == 0 && rear ==n-1) || rear == front-1)
        {//rear == front-1 bhul jata huin.
            cout<<"overflow"<<endl;
        }
        //First element
        else if(front == -1  && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        //Circular nature.
        else if(rear == n-1 && front !=0)
        {//front != 0 bhul jata huin
            rear = 0; 
            arr[rear] = val;
        }
        else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }

    void popFront()
    {
        //4 cases: Underflow, single elements, circular nature, normal flow.
        if(front == -1 && rear == -1)
        {
            cout<<"Underflow"<<endl;
        }
        else if(front == rear)
        {
            //single element 
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == n-1)
        {//circular nature
            arr[front] = -1;
            front = 0;//peeche se samne bhej diya.
        }
        else{
            //normal case
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        //4 cases: Underflow, single elements, circular nature, normal flow.
        if(front == -1 && rear == -1)
        {
            cout<<"Underflow"<<endl;
        }
        else if(front == rear)
        {
            //single element 
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0)//Pop mein front and rear ek saaath aa sakte hain.
        {
            arr[rear] = -1;
            rear = n-1;
        }
        else
        {//Normal case
            arr[rear] = -1;
            rear--;
        }
    }

    void print()
    {
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    DeCircularQueue dq(5);
    dq.pushFront(10);
    dq.print();
    dq.pushFront(20);
    dq.print();
    dq.pushBack(15);
    dq.print();
    dq.pushBack(35);
    dq.print();
    dq.pushFront(100);
    dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    // dq.print();
    // dq.popBack();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.pushFront(10);
    dq.pushFront(10);
    dq.pushFront(10);
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();
    dq.popBack();
    dq.print();
    return 0;
}