/*
PRATA - Roti Prata - SPOJ
https://www.spoj.com/problems/PRATA/ 

IEEE is having its AGM next week and the president wants to serve cheese prata after 
the meeting. 
The subcommittee members are asked to go to food connection 
and get P (P ≤ 1000) pratas packed for the function. 

The stall has L cooks (L ≤ 50) and each cook has a rank R (1 ≤ R ≤ 8). 

A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes 
and so on (he can only cook a complete prata) 
(For example if a cook is ranked 2, he will cook one prata in 2 minutes 
one more prata in the next 4 mins an 
one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas 
as he does not have enough time for the 4th prata). 

The webmaster wants to know the minimum time to get the order done. 
Please write a program to help him out.

Input
The first line tells the number of test cases. 
Each test case consist of 2 lines. 
In the first line of the test case we have P the number of prata ordered. 
In the next line the first integer denotes the number of cooks L and L integers 
follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

Example
Input:
3 -- Number of test cases
//First test case
10 -> P - the number of prata ordered.
4 1 2 3 4 - 4 denotes the number of cooks L; 1 2 3 4 -> Ranks for 4 cooks.
//Second test case
8
1 1

8
8 1 1 1 1 1 1 1 1

Output:
12
36
1
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool possibleSoln(vector<int>& v, int P, int maxTime, int L)
{
    int timeSum = 0;
    int cc = 0; //counter for cooks -->L
    int cp = 1; //counter for Prata -->P
     
    while(cp <= P && cc < L)
    {
        if((timeSum + v[cc] * cp) <= maxTime)
        {
            timeSum += v[cc] * cp;
            cp++;
        }
        else
        {
            P = P - cp + 1;
            cp = 1;
            cc++;
            timeSum = 0;
        }
    }
    if(cc >= L)
    {
        return false;
    }
    return true;
}
 

int cookPratas(int L, vector<int>& v, int P)
{   
    if(P==0)
    {
        return 0;
    }
    int ans = -1;
    int s = 0;
    int last_rank = v[L-1];
    //Max time to cook Prata
    int e =  last_rank * P * (P+1)/2;
    int mid = s +(e-s)/2;
    //Search space s --- e
    while(s<=e)
    {
        if(possibleSoln(v, P, mid, L))
        {
            ans = mid;
            e = mid - 1;               
        }
        else
        {
            s  = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{   
    int tests;
    cin>>tests;
    while(tests > 0)
    {  
        int P;
        cin>>P;
        int L;
        cin>>L;
        vector<int> v;
        for(int i = 0; i<L; i++)
        {   
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        cout<<cookPratas(L, v, P)<<endl;
        v.clear();
        tests--;
    }
    return 0;
}
