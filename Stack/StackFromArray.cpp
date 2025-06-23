#include<iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top;

        Stack(int capacity)
        {
            arr = new int[capacity];
            size = capacity;
            top =  -1;
            // Initialize array elements to 0 for clean print
            for(int i = 0; i < size; i++) arr[i] = 0;
        }
        void push(int val)
        {
            if(top == size-1)
            {//Stack is full
                cout<<"Stack Overflow"<<endl;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }

        void pop()
        {   
            if(top==-1)
            {//Stack is empty
                cout<<"Stack Underflow"<<endl;
            }
            else{
                arr[top] = 0;
                top--;
            }
        }

        int getSize()
        {//top is index
            return top+1;
        }

        bool isEmpty()
        {
            return top == -1;
        }

        int getTop()
        {
            if(top==-1)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else 
            {
                return arr[top];  
            }
        }

        void displayStack()
        {   
            cout<<"Stack: ";
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
    //Creating a stack of size 5
    Stack s(5);
    s.displayStack();
    s.push(10);
    s.displayStack();
    s.push(20);
    s.displayStack();
    s.push(30);
    s.displayStack();
    s.push(40);
    s.displayStack();
    s.push(50);
    s.displayStack();
    s.push(60); // Should print overflow
    s.displayStack();
    //
    cout<<"Current size: "<<s.getSize()<<endl;
    cout<<"Top element: "<<s.getTop()<<endl;
    cout<<"Is empty: "<<(s.isEmpty() ? "Yes" : "No")<<endl;
    //
    s.pop();
    s.displayStack();
    s.pop();
    s.pop();
    s.displayStack();
    //
    cout<<"Current size: "<<s.getSize()<<endl;
    cout<<"Top element: "<<s.getTop()<<endl;
    cout<<"Is empty: "<<(s.isEmpty() ? "Yes" : "No")<<endl;
    //
    s.pop();
    s.pop();
    s.displayStack();
    s.pop(); // Should print underflow
    cout<<"Is empty: "<<(s.isEmpty() ? "Yes" : "No")<<endl;

    return 0;
}