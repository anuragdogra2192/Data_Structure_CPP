/* Geek for Geeks
The Celebrity Problem - Inerview question.
https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//Pratice before Interview, At hi hai.\
The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 319K+Points: 4Average Time: 30m
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person. 
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 <= mat.size()<= 1000
0 <= mat[i][j]<= 1
mat[i][i] == 1
*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
  public:
  //Note: There is only one celebrity in the party.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        int nPersons = mat.size();
        //step1: Push all persons in stack
        for(int i=0; i<nPersons; i++)
        {
            st.push(i);
        }
        //Step 2: Lets find/get the celebritiy by elimination.
        //Discard Method
        while(st.size() != 1)
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            //Let's see if A knows B?
            if(mat[A][B] == 1)
            {
                //A knows B then A is not a celeb.
                // A is eliminated.
                // But B can be a celeb;
                st.push(B);
            }
            else //No A doesnot know B
            {
                //A can be celeb.
                st.push(A);
            }
        }
        //Now lets check the single person is a celeb or not.
        int mightBeCeleb = st.top();
        st.pop();
        
        //celeb should not know anyone.//Row should be zero
        //except the diagonal element, Celeb should know it self.
        for(int i=0; i<nPersons; i++)
        {
            if(mat[mightBeCeleb][i] != 0 && (i != mightBeCeleb))
            {
                return -1;
            }
        }
        
        //everybody Should know celeb.//Column should be 1 except its own.
        for(int i=0; i<nPersons; i++)
        {
            if((mat[i][mightBeCeleb] == 0) /*(i!= mightBeCeleb)*/)
            {
                return -1;
            }
        }
        
        return mightBeCeleb;
    }
};