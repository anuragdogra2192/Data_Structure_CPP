/* Leet code 1691.
1691. Maximum Height by Stacking Cuboids 

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
Example 1:
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 

Constraints:

n == cuboids.length
1 <= n <= 100
1 <= widthi, lengthi, heighti <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    //Interview Question: bahot repeat 
    
public:
    bool isSafeToPlace(vector<int> c1, vector<int> c2)
    {
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2])
        {
            return true;
        }
        return false;
    }

    int solveUsingRec(vector<vector<int>>& cuboids, int curr, int prev)
    {
        //base case
        if(curr >= cuboids.size())
        {
            return 0;
        }

        //include
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
        {//height
            incl = cuboids[curr][2] + solveUsingRec(cuboids, curr+1, curr);
        }

        //exclude
        int excl = 0 + solveUsingRec(cuboids, curr+1, prev);
        int finalAns = max(incl, excl);
        return finalAns;
    }

    int solveUsingMem(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>>& dp)
    {
        //base case
        if(curr >= cuboids.size())
        {
            return 0;
        }

        if(dp[curr][prev+1] != -1) //prev + 1, to make prev a valid index.
        {
            return dp[curr][prev+1];
        }

        //include
        int incl = 0;
        if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
        {//height
            incl = cuboids[curr][2] + solveUsingMem(cuboids, curr+1, curr, dp);
        }

        //exclude
        int excl = 0 + solveUsingMem(cuboids, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
        
        return dp[curr][prev+1];//prev + 1, to make prev a valid index.
    }

    int solveUsingTab(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, 0));
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                //include
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
                {//height
                    incl = cuboids[curr][2] + dp[curr+1][curr+1];//[curr+1] [-1+1]
                }
                //exclude
                int excl = 0 + dp[curr+1][prev+1];//prev+1 [-1+1]
                dp[curr][prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
            }
        }
        return dp[0][-1+1];
    }

    int solveUsingTabSpaceOptimize(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0); //i
        vector<int>prevRow(n+1, 0); //i+1
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                //include
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
                {//height
                    incl = cuboids[curr][2] + prevRow[curr+1];//[curr+1] [-1+1]
                }
                //exclude
                int excl = 0 + prevRow[prev+1];//prev+1 [-1+1]
                currRow[prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
            }
            //Shifting bhul jate hai
            prevRow = currRow;
        }
        return prevRow[-1+1];
    }

    int solveUsingTabSpaceOptimize2(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0); //i
        //vector<int>prevRow(n+1, 0); //i+1
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = -1; prev <= curr-1; prev++)
            {
                //include
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
                {//height
                    incl = cuboids[curr][2] + currRow[curr+1];//[curr+1] [-1+1]
                }
                //exclude
                int excl = 0 + currRow[prev+1];//prev+1 [-1+1]
                currRow[prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
            }
            //Shifting bhul jate hai
            //prevRow = currRow;
        }
        return currRow[-1+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        //Sorting individual (vector of 3 elements is O(3) only). 
        //We sorting so that we can assume the last element as height (2nd index). 
        //As we need to maximize height.
        for(auto& cuboid : cuboids)//by ref lena is important '&'
        {
            sort(cuboid.begin(), cuboid.end());
        }
        //Now sorting all cubiods. default with respect of first element of each cuboid.
        sort(cuboids.begin(), cuboids.end());
        int curr = 0; //current cuboid
        int prev = -1; //prev cuboid
        //int ans = solveUsingRec(cuboids, curr, prev);
        //2-D dp ads prev anmd curr are changing
        int n = cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        //int ans = solveUsingMem(cuboids, curr, prev, dp);
        //int ans = solveUsingTab(cuboids);
        //int ans = solveUsingTabSpaceOptimize(cuboids);
        int ans = solveUsingTabSpaceOptimize2(cuboids);
        return ans;
    }
};