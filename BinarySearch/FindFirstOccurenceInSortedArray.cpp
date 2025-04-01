#include<iostream>

using namespace std;

void firstOccurenceSortedArray(int arr[], int n, int target, int& ansIndex)
{
   int s = 0;
   int e =  n-1;
   int mid = s+(e-s)/2;

   while(s<=e)
   {    //cout<< "Target" << target<<endl; 
        //cout<<"arr val: "<<arr[mid];
        if(target == arr[mid])
        {
            //store karo
            ansIndex = mid;
            //cout<<"arr val: "<<arr[mid];
            //Compute karo
            //Further first occurence left mein hi milega.
            e = mid-1; 
        }
        if(target > arr[mid])
        {// right me jao
            s = mid + 1;
        }
        if(target < arr[mid])
        {// left mein jao
            e = mid - 1;
        }

        mid = s + (e - s)/2;
   } 
}

int main()
{
    int arr[] = {10, 20, 20, 30 ,40, 50, 60 ,70, 80};
    int n = 9;
    int target = 20;
    int ansIndex = -1;

    firstOccurenceSortedArray(arr, n, target, ansIndex);
    cout<<"First ouccurence of "<<target<<" "<<ansIndex<<endl;

    return 0;
}