#include<iostream>
using namespace std;

class Queue //First In First Out
{
    int* arr;
    int n; //Size of Queue
    int front; //Index for removal
    int rear; //Index to insert
    public:
    Queue(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    };

    void push(int val)
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

    void pop()
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

    int getFront()
    {
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if(rear < n && rear!=-1)
        {
            return arr[rear];
        }
        return -1;
    }

    int getSize()
    {
        if(front == -1 && rear == -1)
        {
            return 0;
        }
        //Number of elements inside a queue.
        return (rear - front + 1);
    }

    bool IsEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    cout<<q.getRear()<<endl;
    cout<<q.getFront()<<endl;
    q.push(20);
    q.push(30);
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    q.push(40);
    cout<<q.getRear()<<endl;
    q.push(40);
    q.push(40);
    cout<<q.getSize()<<endl;
    // cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;
    return 0;
}