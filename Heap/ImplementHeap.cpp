#include<iostream>
using namespace std;

class Heap
{
    public:
    int* arr;
    int capacity;
    int index;
    
    Heap(int n)
    {
        this->capacity = n;
        arr = new int[n];
        index = 0;
        //jab bhi mujhe insert karna hoga,
        //tab index+1 karke insert kr denge
    }
    void printHeap()
    {
        for(int i=0; i<capacity; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //Time Complexity: O(log n) or O(h),  as it is CBT, h = log n 
    void insert(int val)
    {
        if(index == capacity - 1)
        {
            cout<<" Overflow "<<endl;
            return;
        }
        //if there is a space left
        index++;
        arr[index] = val;

        //now put val at correct position
        //by comparing with parent node
        int currIndex = index;
        while(currIndex > 1)// if index == 1 means root element
        {
            int parentIndex = currIndex/2;
            if(arr[parentIndex] < arr[currIndex])//Max Heap rule
            {
                swap(arr[parentIndex], arr[currIndex]);
                currIndex = parentIndex;
            }
            else
            {//agar parent already bada hai, no need to do anything  
                break;
            }
        }
    }

    //Time complexity: O(log n)
    void deleteFromHeap()//Max heap
    {
        if(index == 0)
        {
            cout<<"Underflow "<<endl;
            return;
        }
        //replacement root ko lastnode se
        swap(arr[1], arr[index]);//O(1) //index must be at the last inserted node;
        //size decrease
        index--;//O(1)
        //heapify
        heapify(arr, index, 1);//O(log n)
    }

    void heapify(int* arr, int n, int currIndex)
    {
        //n is the number of elements
        int i = currIndex;
        int rightIndex = (2*i) + 1;
        int leftIndex = 2*i;
        int largestKaIndex = i;
        //Assume that i_th value is the largest for now
        //but the right or left value can be too
        
        //check fo left, compare with largestKaIndex
        if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
        {
            //left mein badi value mil gayi
            //so store karao
            largestKaIndex = leftIndex;
        }
        
        //check for right, compare with largestKaIndex
        if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) 
        {
            //right mein badi value mil gayi hai, so store karo
            largestKaIndex = rightIndex;
        }
        
        //jab yaha aaoge, tb we have the largest val index

        //if largestValue still i wali hai, then no need to do anything
        //else swap logic
        if(largestKaIndex != i)
        {
            swap(arr[i], arr[largestKaIndex]);
            //update i 
            i = largestKaIndex;
            //baaki recursion sambhal lega
            heapify(arr, n, i);
        }
    }

    ~Heap()
    {
        delete[] arr;        
    }
};

int main()
{
    Heap pq(10); //Max heap is also called as priority queue.
    pq.insert(10);
    pq.printHeap();
    pq.insert(20);
    pq.printHeap();
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);
    pq.printHeap();

    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    return 0;
}

/*
Note: In Heap the "root node" will give you 
always:
1) Max value in Max Heap
2) Min value in Min Heap

Array to Heap in-place 
takes only Time Complexity O(n)
*/