/* GFG

Count Derangements (Permutation such that no element appears in its original position)

A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of [0, 1, 2, 3] is [2, 3, 1, 0].
Given a number n, find the total number of Derangements of a set of n elements.

Examples : 

Input: n = 2
Output: 1
Explanation: For two balls [1, 2], there is only one possible derangement [2, 1].

Input: n = 3
Output: 2
Explanation: For three balls [1, 2, 3], there are two possible derangements [3, 1, 2] and [2, 3, 1].


Using Recursion - O(2 ^ n) Time and O(n) Space
The idea is to use recursion as, there are n - 1 way for element 0 (this explains multiplication with n - 1). 
Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return. 

i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices
The formula used in the solution is:

F(n) = (n - 1) * (F(n - 1) + F(n - 2)
*/
#include<iostream>

using namespace std;

int totalDerangement(int n)
{
    //base case
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }

    int ans = (n-1) * (totalDerangement(n-1) + totalDerangement(n-2));
    return ans;
}
int main()
{   
    int n = 4;
    cout<<"Ans: "<<totalDerangement(n)<<endl;
    return 0;
}