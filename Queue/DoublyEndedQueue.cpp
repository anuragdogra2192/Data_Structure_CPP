#include<iostream>
using namespace std;

class Deque
{
    private:
        int *arr;
        int n;
        int front;
        int rear;
    public:
    Deque(int size)
    {
        this->n = size;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void pushFront(int val)
    {   
        //Overflow
        if(front == 0)
        {
           cout<<"Queue front is Overflow"<<endl; 
        }
        //Empty
        else if(front == -1 && rear == -1)
        {
            //First time
            rear++;
            front++;
            arr[front] = val;
        }
        else{
            //normal front insertion
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val)
    {
        //overflow
        if(rear == n-1)
        {
            cout<<"Queue is Overfow"<<endl;
        }
        else if(front == -1 && rear == -1)
        {
            //First time
            rear++;
            front++;
            arr[rear] = val;
        }
        else
        {
            //Otherwise normal insertion
            rear++;
            arr[rear] = val;    
        }
    }

    void popFront()
    {
        if((front == -1 && rear == -1))
        {
            cout<<"Queue is underflow"<<endl;
        }
        //Single element case
        else if(rear == front)
        {
            arr[front] = -1; //optional
            rear = -1;
            front = -1;
        }
        else//Pop always haapen from front;
        {   
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if((front == -1 && rear == -1))
        {
            cout<<"Queue is underflow"<<endl;
        }
        else if(rear == front)
        {//Single element
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    int getFront()
    {
        if(front == -1)
        {
            return -1;
        }
        return arr[front];
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
    Deque dq(5);
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
    return 0; 
}