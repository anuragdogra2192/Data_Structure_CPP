#include<iostream>
//STL queue has priority queue that is for HEAP.
#include<queue>
using namespace std;

int main()
{
    //creation of Max Heap by default
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(40);
    pq.push(5);
    pq.push(60);
    pq.push(50);
    
    cout<<"Size of Heap: "<< pq.size() <<endl;
    
    //access the element 
    cout<<pq.top()<<endl;
    //Remove the element
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<"Size of Heap: "<< pq.size() <<endl;
    
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<"Size of Heap: "<< pq.size() <<endl;

    if(!pq.empty())
    {
        cout<<"Not empty"<<endl;
    }

    cout<<"Min Heap creation"<<endl;

    //Lets create min heap, means priority to minimum element
    priority_queue<int, vector<int>, greater<int> > min_pq;
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(40);
    min_pq.push(5);
    min_pq.push(60);
    min_pq.push(50);
    
    cout<<"Size of Min Heap: "<< min_pq.size() <<endl;
    
    //access the element 
    cout<<min_pq.top()<<endl;
    //Remove the element
    min_pq.pop();
    cout<<min_pq.top()<<endl;
    cout<<"Size of Min Heap: "<< min_pq.size() <<endl;
    
    min_pq.pop();
    cout<<min_pq.top()<<endl;
    cout<<"Size of min Heap: "<< min_pq.size() <<endl;
    
    if(!min_pq.empty())
    {
        cout<<"Not empty"<<endl;
    }

    return 0;
}