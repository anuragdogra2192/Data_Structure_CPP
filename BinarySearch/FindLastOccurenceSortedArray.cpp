#include<iostream>
using namespace std;
//find last occurence of a given target in a sorted array.
void findLastOccurence(int *arr, int n, int& ansIndex, int target)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(target == arr[mid])
        {
            //Store
            ansIndex = mid;
            //Right mein last occurence hoi sakti hai
            s = mid+1;
        }
        if(target > arr[mid])
        {
            //right side 
            s = mid + 1;
        }
        if(target < arr[mid])
        {
            //left side
            e = mid -1;
        }

        mid = s + (e-s)/2;

    }
}


int main()
{
    int arr[] = {10, 20, 20, 20 ,40, 50, 60 ,70, 80};
    int n = 9;
    int target = 20;
    int ansIndex = -1;

    findLastOccurence(arr, n, ansIndex, target);
    cout<<"First ouccurence of "<<target<<" "<<ansIndex<<endl;
    return 0;
}