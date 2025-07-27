/* Geeks for geeks: 
0 - 1 Knapsack Problem
https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Difficulty: MediumAccuracy: 31.76%Submissions: 508K+Points: 4
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103

Expected Complexities
Time Complexity: O (n * W)
Auxiliary Space: O (n * W)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int solveUsingRec(vector<int> &val, vector<int> &wt, int capacity, int index)
    {   //Right to left traverse, n - 0
        //single item and base case
        if(index == 0)//single item
        {
            if(wt[0] <= capacity)
            {
                return val[0];
            }
            return 0;
        }
        
        //incl/excl pattern
        //include
        int incl = 0;
        if(wt[index] <= capacity)
        {
            //1k mein
            incl = val[index];
            //bakki recur 
            incl += solveUsingRec(val, wt, capacity - wt[index], index-1);//Right to left traverse, n - 0
        }
        //exclude
        //1k mein
        int excl = 0;
        //Baaki recur
        excl += solveUsingRec(val, wt, capacity, index-1);//Right to left traverse, n - 0
        
        int finalAns = max(incl, excl);
        return finalAns;
    }
    
    //Top Down approach
    int solveUsingRecMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int> >& dp)
    {   //Right to left traverse, n - 0
        //single item and base case
        if(index == 0)//single item
        {
            if(wt[0] <= capacity)
            {
                return val[0];
            }
            return 0;
        }
        //Step 3 check if ans already exists.
        if(dp[capacity][index]!= -1)
        {
            return dp[capacity][index]; 
        }
        
        //incl/excl pattern
        //include
        int incl = 0;
        if(wt[index] <= capacity)
        {
            //1k mein
            incl = val[index];
            //bakki recur 
            incl += solveUsingRecMem(val, wt, capacity - wt[index], index-1, dp);//Right to left traverse, n - 0
        }
        //exclude
        //1k mein
        int excl = 0;
        //Baaki recur
        excl += solveUsingRecMem(val, wt, capacity, index-1, dp);//Right to left traverse, n - 0
        //Step 2: ans sretunr and store
        dp[capacity][index] = max(incl, excl);
        return dp[capacity][index];
    }
    
    
    int solveUsingTab(vector<int> &val, vector<int> &wt, int capacity)
    {   
        int n = val.size();
        
        //Step 1: dp creation 
        vector<vector<int> > dp(capacity+1, vector<int>(n+1, 0));
        
        //analyse the base case
        for(int w=wt[0]; w<=capacity;w++)
        {
          dp[w][0] = val[0];
        }
        
        //Recur
        // capacity: W -> 0
        // index: n-1 -> 0
        //Reverse
        //capacity: 0 -> W
        //index: 0 - n-1
        for(int weight=0; weight<=capacity; weight++)
        {
            for(int index = 1; index <= n-1; index++)
            {
                 //incl/excl pattern
                //include
                int incl = 0;
                if(wt[index] <= weight)
                {
                    //1k mein
                    incl = val[index];
                    //bakki recur 
                    incl += dp[weight-wt[index]][index-1];
                }
                //exclude
                //1k mein
                int excl = 0;
                //Baaki recur
                excl += dp[weight][index-1];//Right to left traverse, n - 0
                //Step 2: ans sretunr and store
                dp[weight][index] = max(incl, excl);
            }
        }
        return dp[capacity][n-1];
    }
    
    //Space optimization S.C O(W)
    int solveUsingTabSpaceOptimization(vector<int> &val, vector<int> &wt, int capacity)
    {   
        int n = val.size();
        //Step 1: dp creation with spaceOptimzation
        vector<int>prev(capacity+1, 0);
        vector<int>curr(capacity+1, 0);
        
        //analyse the base case
        for(int w=wt[0]; w<=capacity;w++)
        {
          prev[w] = val[0];
        }
        //Recur
        // capacity: W -> 0
        // index: n-1 -> 0
        //Reverse
        //capacity: 0 -> W
        //index: 0 - n-1
        for(int index = 1; index <= n-1; index++)
        {
            for(int weight=0; weight<=capacity; weight++)
            {
            
                 //incl/excl pattern
                //include
                int incl = 0;
                if(wt[index] <= weight)
                {
                    //1k mein
                    incl = val[index];
                    //bakki recur 
                    incl += prev[weight-wt[index]];
                }
                //exclude
                //1k mein
                int excl = 0;
                //Baaki recur
                excl += prev[weight];//Right to left traverse, n - 0
                //Step 2: ans sretunr and store
                curr[weight] = max(incl, excl);
            }
            //Shift-  yeah bhul jata huin
            prev = curr;
        }
        return prev[capacity];
    }
    
    //Space optimization2 S.C O(W)
    int solveUsingTabSpaceOptimization2(vector<int> &val, vector<int> &wt, int capacity)
    {   
        int n = val.size();
        //Step 1: dp creation with spaceOptimzation
        //vector<int>prev(capacity+1, 0);
        vector<int>curr(capacity+1, 0);
        
        //analyse the base case
        for(int w=wt[0]; w<=capacity;w++)
        {
          curr[w] = val[0];
        }
        //Recur
        // capacity: W -> 0
        // index: n-1 -> 0
        //Reverse
        //capacity: 0 -> W
        //index: 0 - n-1
        for(int index = 1; index <= n-1; index++)
        {
            for(int weight=capacity; weight>=0; weight--)
            {
                 //incl/excl pattern
                //include
                int incl = 0;
                if(wt[index] <= weight)
                {
                    //1k mein
                    incl = val[index];
                    //bakki recur 
                    incl += curr[weight-wt[index]];
                }
                //exclude
                //1k mein
                int excl = 0;
                //Baaki recur
                excl += curr[weight];
                //Step 2: ans sretunr and store
                curr[weight] = max(incl, excl);
            }
        }
        return curr[capacity];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int index = wt.size()-1;
        int capacity = W;
        //return solveUsingRec(val, wt, capacity, index);
        //step1 create dp -> 2D because capacity and index both are changing.
        int n = wt.size();
        vector<vector<int> > dp(capacity+1, vector<int>(n+1, -1));
        //return solveUsingRecMem(val, wt, capacity, index, dp);  
        //return solveUsingTab(val, wt, capacity);
        //return solveUsingTabSpaceOptimization(val, wt, capacity);
        return solveUsingTabSpaceOptimization2(val, wt, capacity);
        
    }
};