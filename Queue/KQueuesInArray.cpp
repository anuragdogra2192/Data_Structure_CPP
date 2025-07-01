#include<iostream>
using namespace std;

class KQueue
{
public: 
int n, k, freeSpot;
int *arr, *front, *rear,*next;

KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0)
{
    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];

    for(int i=0; i<k; i++)
    {
        front[i] = rear[i] = -1;
    }
    for(int i=0; i<n; i++)
    {
        next[i] = i+1;
    }
    next[n-1] = -1;
}

//push x into the qith queue
bool push(int x, int qi)
{
    //overflow
    if(freeSpot == -1)
    {   
        cout<<"Overflow"<<endl;
        return false;
    }
    //find first free index
    int index = freeSpot;
    //update freeSpot
    freeSpot = next[index];
    //if first element in qi
    if(front[qi] == -1)
    {
        front[qi] = index;
    }
    else
    {//link new element to that Q's rearest element
        next[rear[qi]] = index;
    }
    //update next 
    next[index] = -1;
    //Update rear
    rear[qi] = index;
    arr[index] = x;
    return true;
}

int pop(int qi)
{
    //underflow
    if(front[qi] == -1)
    {   
        cout<<"underflow"<<endl;
        return -1;
    }
    //Find index to pip
    int index = front[qi];
    //update front
    front[qi] = next[index];
    //Update next
    next[index] = freeSpot;
    //Update freeSpot
    freeSpot = index;
    return arr[index];
}

};

int main()
{
    KQueue Kq(6, 3);
    cout<<Kq.push(10,0)<<endl;
    cout<<Kq.push(11,0)<<endl;
    cout<<Kq.push(12,0)<<endl;
    cout<<Kq.push(20,1)<<endl;
    cout<<Kq.push(21,1)<<endl;
    cout<<Kq.push(21,1)<<endl;
    cout<<Kq.push(21,2)<<endl;
    cout<<Kq.push(21,2)<<endl;

    cout<<"Popping: "<<endl;
    cout<<Kq.pop(0)<<endl;
    cout<<Kq.pop(0)<<endl;
    cout<<Kq.pop(0)<<endl;
    cout<<Kq.pop(0)<<endl;
    
    cout<<Kq.pop(1)<<endl;
    cout<<Kq.pop(1)<<endl;
    cout<<Kq.pop(1)<<endl;
    cout<<Kq.pop(1)<<endl;

    cout<<Kq.pop(2)<<endl;
    cout<<Kq.pop(2)<<endl;
    cout<<Kq.pop(2)<<endl;

    return 0;
}