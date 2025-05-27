#include<iostream>

using namespace std;

//Ek mein print Karuga 
//baaki recursion pront karega

void printArray(int arr[], int size, int index)
{
    //Base case
    if(index == size)
    {
        //Array se bahar aa agaye ho
        return;
    }
    //Recursive relation
    //1k case mein solve karunga
    cout<< arr[index]<<" "; 
    //baaki recursion karega
    printArray(arr, size, index+1);
}

int main()
{
    int arr[] = {10, 20 , 30 , 40, 50, 60};
    int size = 6;
    printArray(arr, size, 0);
    cout<<endl;
    return 0;
}
