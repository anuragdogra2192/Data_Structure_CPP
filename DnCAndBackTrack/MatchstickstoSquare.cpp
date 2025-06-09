/*
Leet Code 473
473. Matchsticks to Square.
Interview Question

You are given an integer array matchsticks where matchsticks[i] 
is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. 
You should not break any stick, but you can link them up, 
and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.


Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, 
one side of the square came two sticks with length 1.

Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all 
the matchsticks.
 
Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

//Intuition and logic matches with this question:
Leet Code: 416. Partition Equal Subset Sum
*/
//Can be optimized with DP

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int>& sides, int i)
    {
        if(i == matchsticks.size())
        {//All matchsticks are being used.
            return sides[0] == 0 && sides[1] == 0 
                && sides[2] == 0 && sides[3] == 0;
        //If all sideSum are 0 then we have found the 4 equal subsets.
        }
        
        bool ans = false;
        //ith matchstick can be a part of subset A / B / C / D
        for(int j=0; j<sides.size(); j++)
        {   
            if(matchsticks[i] <= sides[j])
            {
                //include
                sides[j] -= matchsticks[i];
                ans = ans || solve(matchsticks, sides, i+1); 
                if(ans == true)
                {
                    return true;
                }
                //Backtrack
                //if we are here means starting with ith stick didnot work
                //Exclude the matchstick
                sides[j] += matchsticks[i];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4)
            return false;
        
        //int sum = 0;
        // for(auto i : matchsticks)
        // {
        //     sum += i;
        // }
        auto sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0)
        {
            return false;
        }
        
        int sideSum = sum / 4;  //int
        vector<int> sides (4, sideSum);
        //Decreasing order sort of matchsticks can reduce recursive calls.
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, sides, 0);
    }
};