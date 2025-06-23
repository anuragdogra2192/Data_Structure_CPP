/* 2 Stacks in one array
arr: | | | | | | | | | | | | | | | | | | | | | | 
  -1  0 1 2 3 4 .............................n-1 n
    top1->                                 <-top2
    stack1---> 
                                        <---stack2
Intial State:
top1 = -1;
top2 = n;
*/

#include<iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top1;
        int top2;
    Stack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top1 = -1;
        top2 = size; 
    }
    
    void push1(int value)
    {
        //if space available hai 
        //toh push karo bhai
        if((top2-top1)==1)
        { //cannot insert
            cout<<"Stack1 Overflow "<<endl;
        }
        else
        {//Can insert
            top1++;
            arr[top1] = value;
        }
    }
    
    void push2(int value)
    {
        if((top2-top1)==1)
        {
            cout<<"Stack2 Overflow" <<endl;
        }
        else
        {
            top2--;
            arr[top2] = value;
        }
    }
    
    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack1 undeflow"<<endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2()
    {
        if(top2==size)
        {
            cout<<"Stack2 underflow"<<endl;
        }
        else
        {
            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout<<"Top1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    ~Stack()
    {
        delete[] arr; 
    }
};

int main()
{   
    Stack s(5);
    s.push1(10);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.pop1();
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(80);
    s.print();
    s.push1(100);
    s.push2(100);
    return 0;
}