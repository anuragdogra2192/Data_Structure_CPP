/*
1753. Maximum Score From Removing Stones

You are playing a solitaire game with 
three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. 
Each turn you choose two different non-empty piles, 
take one stone from each, and add 1 point to your score. 
The game stops when there are fewer than two non-empty piles 
(meaning there are no more available moves).

Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

Example 1:

Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.
Example 2:

Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.
Example 3:

Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.

Constraints:

1 <= a, b, c <= 105
*/
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a==0 && b==0 && c==0)
        {
            return 0;
        }
        //maxHeap
        priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int score = 0;

        while(maxHeap.size() > 1) //at least we will get two piles
        {
            int pile1 = maxHeap.top(); maxHeap.pop();
            int pile2 = maxHeap.top(); maxHeap.pop();

            pile1--;
            pile2--;
            score++;
            
            if(pile1 > 0)
            {
                maxHeap.push(pile1);
            }
            if(pile2 > 0) maxHeap.push(pile2);
        }
        return score;
    }
};