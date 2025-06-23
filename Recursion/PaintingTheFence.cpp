/** Geek for Geeks
 * Painting the Fence
Difficulty: MediumAccuracy: 32.89%Submissions: 120K+Points: 4Average Time: 40m
Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer.

Examples:

Input: n = 3, k = 2 
Output: 6
Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR
Input: n = 2, k = 4 
Output: 16
Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
Constraints:
1 ≤ n ≤ 300
1 ≤ k ≤ 105
*/

#include<iostream>
using namespace std;

class Solution {
  public:
    int getPaintingWays(int n, int k)
    {
        //base case
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {//       same  diff
            return (k + k*(k-1));
        }
        
        //1K case mein karunga 
        int ans = (k-1)*(getPaintingWays((n-2), k) + getPaintingWays((n-1), k));
        
        return ans;
    }
    int countWays(int n, int k) {
        // code here
        int ans = getPaintingWays(n,k);
        return ans;
    }
};