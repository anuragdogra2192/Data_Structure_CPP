/*
EKO - Eko
#binary-search

Lumberjack Mirko needs to chop down M metres of wood. 
It is an easy job for him since he has a nifty new woodcutting 
machine that can take down forests like wildfire. 
However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), 
and the machine raises a giant sawblade to that height and 
cuts off all tree parts higher than H (of course, 
trees not higher than H meters remain intact). 
Mirko then takes the parts that were cut off. 
For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres,
 and Mirko raises his sawblade to 15 metres, 
 the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, 
 respectively, while Mirko will take 5 metres off the first tree and 2 metres off
the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. 
That‟s why he wants to set his sawblade as high as possible. 
Help Mirko find the maximum integer height of the sawblade that still allows him 
to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, 
N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers 
less than 1 000 000 000, the heights of each tree (in metres). 
The sum of all heights will exceed M, thus Mirko will always be able to obtain 
the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example
Input:
4 7 Here N = 4, Number of trees and M = 7, Mirkos wood amount
20 15 10 17

Output:
15
Input:
5 20
4 42 40 26 46

Output:
36

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool possibleSoln(long long int N, long long int M, vector<long long int>& vec, long long int bladeHeight)
{
    long long int woodSum = 0;
    for(long long int i=0; i<N; i++)
    {   
        if(vec[i] > bladeHeight)//important condition
        {
            woodSum += vec[i] - bladeHeight;
        }
        if(woodSum >= M)
        {
            return true;
        }    
    }
    return false;
}

int main()
{
    long long int N, M;
    cin>>N;
    cin>>M;

    vector<long long int> vec;

    long long int val;
    long long int max = -1;
    for(long long int i=0; i<N; i++)
    {
        cin>>val;
        max = val>max?val:max;
        vec.push_back(val);
    }

    long long int s = 0;
    long long int e = max;
    long long int mid = s + ((e-s)>>1);
    long long int ans = -1;
    
    while(s<=e)
    {
        if(possibleSoln(N, M, vec, mid))
        {
            ans =  mid;
            s = mid + 1;
        }
        else
        {
            e =  mid - 1;
        }
        //Bhool jata huin
        mid = s + ((e-s)>>1);
    }
    cout<<ans;
    return 0;
}