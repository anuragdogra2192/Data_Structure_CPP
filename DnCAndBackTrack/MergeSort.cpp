/*
Beautiful sorting algorithm using Divide and Conquer
Coding:
                    Intial Main array
                    /               \ 
    Left Part                              Right Part
    Recursion - Sort                       Recursion Sort
                    \                /
                Merge the 2 sorted Arrays

*/
#include<iostream>
#include<vector>

using namespace std;

//Time Complexity: O(nlogn)
//Space Complexity: O(n)

void merge(vector<int>&arr, int s, int e, int mid)
{
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    //Create a left array
    int* leftArr = new int[leftLength];
    //Create a right array
    int* rightArr =  new int[rightLength];

    //Fill and copy the left and right arr

    //Copying the left part
    int index = s;
    for(int i = 0; i<leftLength; i++)
    {
        leftArr[i] = arr[index];
        index++;
    }

    //Copying the right part
    index = mid+1;
    for(int j = 0; j<rightLength; j++)
    {
        rightArr[j] = arr[index++];
    }
    
    //Merging now
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = s;
    
    while(leftIndex < leftLength && rightIndex < rightLength)
    {
        if(leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrIndex] = leftArr[leftIndex];
            mainArrIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrIndex] = rightArr[rightIndex];
            mainArrIndex++;
            rightIndex++;
        }
    }
    //Need to handle the remaining elements
    while(leftIndex < leftLength)
    {
        arr[mainArrIndex] = leftArr[leftIndex];
        mainArrIndex++;
        leftIndex++;
    }

    while(rightIndex < rightLength)
    {
        arr[mainArrIndex] = rightArr[rightIndex];
        mainArrIndex++;
        rightIndex++;
    }
    delete[] rightArr;
    delete[] leftArr;
}

void mergeSort(vector<int>&arr, int s, int e)
{
    //base case
    /*if(s>e)
    {
        return;
    }
    //    +
    //Single element in array
    //Single element means already sorted.
    if(s==e)
    {
        return;
    }
    */
    //base case + single element case
    if(s>=e)
    {
        return;
    }

    int mid =  (s+e)/2;
    //int mid = s+(e-s)/2;

    //Left part - recursion will solve
    mergeSort(arr, s, mid-1);
    
    //Right part - recursion will solve
    mergeSort(arr, mid+1, e);

    //Merge the two sorted parts
    //With info of "mid" value we can 
    //create the left anf right array
    merge(arr, s, e, mid);
}
int main()
{   
    vector<int> arr = {100, 45, 32, 23, 123, 101, 56, 21, 12};
    int s = 0;
    int e =  arr.size()-1;
    mergeSort(arr, s, e);

    // Print the sorted array
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/*
---------------------------------
Time Complexity of Merge Sort
Merge Sort is a divide-and-conquer algorithm. The time complexity can be analyzed as follows:

Divide Step:

The array is divided into two halves recursively until each subarray contains only one element.
Dividing the array takes O(log n) levels of recursion, where n is the size of the array.
Merge Step:

At each level of recursion, the merging process combines two sorted subarrays into one sorted array.
Merging two subarrays takes O(n) time at each level.
Total Time Complexity:

Since there are O(log n) levels of recursion and merging takes O(n) time at each level, the total time complexity is:
O(n * log n)

--------------------------------------------
Space Complexity of Merge Sort
Merge Sort requires additional space for temporary arrays during the merging process. The space complexity can be analyzed as follows:

Temporary Arrays:

At each level of recursion, two temporary arrays (leftArr and rightArr) are created to store the elements of the left and right subarrays.
The total space required for these arrays is proportional to the size of the input array, i.e., O(n).
Recursion Stack:

The recursion depth is O(log n) because the array is divided into halves recursively.
Each recursive call adds a frame to the stack, but this space is negligible compared to the space required for the temporary arrays.
Total Space Complexity:

The dominant factor is the space required for the temporary arrays, which is O(n).

Total Space: O(n)
*/