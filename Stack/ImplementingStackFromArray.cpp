#include<iostream>

//Implementing Stack using Array
class Stack
{
    public:
        int* arr;
        int size;
        int top;
    
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    bool isEmpty();
    void pop();
    int getTop();
    void push(int data);
    int getSize();
    void print();
};

bool Stack::isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
        return false;
}

void Stack::pop()
{
    if(top == -1)
    {
        std::cout << "Stack Underflow: "<<std::endl;  
        return;
    } 
    else
    {
        top--; 
    }
}

int Stack::getTop()
{   
    if(top == -1)
    {
        std::cout<<"Stack Empty"<<std::endl;
    }
    else
    {
        return arr[top];
    }
}

void Stack::push(int data)
{
    if(top == size-1)
    {
        std::cout<<"Stack Overflow"<<std::endl;
    }
    else
    {
        top++;
        arr[top] = data;
    }
}

int Stack::getSize()
{
    return top+1;
}

void Stack::print()
{
    if(top==-1)
        std::cout<<"The Stack is Empty"<<std::endl;
    int temp = top;
    std::cout<<" The Stack looks: "<<std::endl;
    while(temp!=-1)
    {
        std::cout<<arr[temp]<<" "<<std::endl;
        temp--;
    }
}

int main()
{
    Stack st(8);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    st.push(90);
    st.push(100);

    st.print();
    return 0;
}