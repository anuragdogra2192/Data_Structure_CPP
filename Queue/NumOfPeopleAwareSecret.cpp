/* Leet code 2327. 
2327. Number of People Aware of a Secret
Medium
Topics - Dynamic Programming, Queue, Simulation

Hint
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
Example 2:

Input: n = 4, delay = 1, forget = 3
Output: 6
Explanation:
Day 1: The first person is named A. (1 person)
Day 2: A shares the secret with B. (2 people)
Day 3: A and B share the secret with 2 new people, C and D. (4 people)
Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)

Constraints:

2 <= n <= 1000
1 <= delay < forget <= n

Time Complexity
The main loop runs for n days: O(n)
Each queue operation (push/pop/front) is O(1)
Each person is added and removed from the queues at most once
All queue operations over all days are O(n)
Total Time Complexity:
O(n)

Space Complexity
Each queue (delayQ, forgetQ) can store at most O(n) entries (one for each day/person)
Other variables use O(1) space
Total Space Complexity:
O(n)

Summary:

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;
        int cur = 0; //active spreader
        int ans = 1; // persons who knows about secret
        queue<pair<int,int>> delayQ, forgetQ; //<uss din, kitne new logo ko secret pata chala>
        //Intial state (Day 1 and Person A)
        delayQ.push({1,1});
        forgetQ.push({1,1});

        for(int i=1; i<=n; i++)
        {
            //step1: Active spreader and persons know secrets kam karo
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i)
            {
                auto front = forgetQ.front();
                forgetQ.pop();
                auto num = front.second;
                ans = (ans - num + M) % M;
                cur = (cur - num + M) % M;
            }

            //step2: make new active spreaders
            if(!delayQ.empty() && delayQ.front().first + delay <= i)
            {
                auto front = delayQ.front();
                delayQ.pop();
                cur = (cur + front.second) % M;// active klar diya hai.
            }

            //Step 3: Spread the secret finally
            if(cur > 0)
            {
                ans = (ans + cur)%M;
                delayQ.push({i, cur});
                forgetQ.push({i, cur});
            }
        }
        return ans;
    }
};