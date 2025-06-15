/* Leet Code 279 
279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:

1 <= n <= 104
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int numSquareHelper(int n)
    {
        //Base case
        if(n==0) return 1;

        //1K we will solve
        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while(i<=end)
        {
            int perfectSquare = i*i;
            //baaki recursion sambhalega
            int numberOfPerfectSquares = 1 + numSquareHelper(n-perfectSquare);
            if(numberOfPerfectSquares < ans)
            {
                ans = numberOfPerfectSquares;
            }
            i++;
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquareHelper(n)-1;
    }
};