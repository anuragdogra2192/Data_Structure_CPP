/*
Geek for Geeks
 * Sum of minimum and maximum elements of all subarrays of size k.

 Given an array of both positive and negative integers, 
 the task is to compute sum of minimum and maximum elements
 of all sub-array of size k.

Examples: 

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Missing sub arrays - 
     
     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27
     
     Sum of all min & max = 6 + 4 + 4 + 4 = 18

     //Time Complexity: O(N)
     //Space Complexity: O(k) + O(k) (auxiliary)
     */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> maxMinSumSliding(int k, vector<int>& nums)
{
    vector<int> ans;
    deque<int> dq1, dq2;//containing indicies

    //Process first window of dq1 and dq2
    for(int i=0; i<k; i++)
    {
        int element = nums[i];
        //In dq1 - Get rid of index of values smaller than element
        while(!dq1.empty() && nums[dq1.back()] < element)
        {
            dq1.pop_back();
        }
        dq1.push_back(i);

        //In dq2 - Get rid of index of values greater than element
        while(!dq2.empty() && nums[dq2.back()] > element)
        {
            dq2.pop_back();
        }
        dq2.push_back(i);
    }
    
    //Remaining Windows
    for(int i=k; i<nums.size(); i++)
    {
        //Ans Store per window
        int maxElement = nums[dq1.front()];
        int minElement = nums[dq2.front()];
        ans.push_back((maxElement+minElement));
        
        //Removal, shifting window of dq1 and dq2
        //Thats possible only if queue is not empty
        if(!dq1.empty() && (i-dq1.front())>=k)
        {
            dq1.pop_front();
        }
        if(!dq2.empty() && (i-dq2.front())>=k)
        {
            dq2.pop_front();
        }

        //Addition
        int element = nums[i];
        //In dq1 - Get rid of index of values smaller than element
        while(!dq1.empty() && nums[dq1.back()] < element)
        {
            dq1.pop_back();
        }
        dq1.push_back(i);
        //In dq2 - Get rid of index of values greater than element
        while(!dq2.empty() && nums[dq2.back()] > element)
        {
            dq2.pop_back();
        }
        dq2.push_back(i);
    }
    //Ans Store for last window
    int maxElement = nums[dq1.front()];
    int minElement = nums[dq2.front()];
    ans.push_back((maxElement+minElement));

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};  
    int k = 4;
    vector<int>ans = maxMinSumSliding(k, arr);
    int sum = 0; 
    for(auto i : ans)
    {
        cout<<i<<" ";
        sum+=i;
    }
    cout<<endl;
    cout<<"Sum: "<<sum<<endl;
    return 0;
}