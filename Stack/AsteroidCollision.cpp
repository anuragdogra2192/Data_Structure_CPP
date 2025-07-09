/* Leet Code 735.
 * 735. Asteroid Collision
Interview one and tough
We are given an array asteroids of integers 
representing asteroids in a row.
The indices of the asteriod in the array represent
their relative position in space.
For each asteroid, the absolute value represents
its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 
Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

Time Complexity
The algorithm iterates through each asteroid once: O(N)
Each asteroid is pushed and popped from the stack at most once: O(N)
Building the answer vector from the stack: O(N)
Total Time Complexity:
O(N), where N is the number of asteroids.

Space Complexity
The stack can store up to N asteroids: O(N)
The answer vector uses up to N space: O(N)
Total Space Complexity:
O(N)

Summary:
Time Complexity: O(N)
Space Complexity: O(N)
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(auto ast: asteroids)
        {
            bool IncommingAstDestroy = false; //initially no destruction.
            if(!st.empty())
            {
                if(ast > 0 || (st.top()<0 && ast<0))
                {//Always push
                    st.push(ast);
                }
                else
                {
                    //collision
                    while(!st.empty() && (st.top()>0 && ast<0))//+ve -ve
                    {
                        if(abs(ast) == st.top())
                        {
                            //cout<<ast<<" ";
                            IncommingAstDestroy = true;
                            st.pop();
                            break; //ast is also destroyed after collision
                        }
                        else if(abs(ast) > st.top())
                        {
                            //cout<<ast<<" ";
                            IncommingAstDestroy = false;
                            st.pop();
                        }
                        else//abs(ast) < st.top()
                        {//top() has greater size so ast can't be pushed in the stack
                         //top() destroys the ast
                            IncommingAstDestroy = true;
                            break; 
                        }
                    }
                    if(!IncommingAstDestroy)
                    {
                        st.push(ast);
                    }
                }
            }
            else// is stack is empty then push
            {
                st.push(ast);
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1; i>=0; i--)
        {
            ans[i] = st.top();
            st.pop();
        } 
        return ans;
    }
};
