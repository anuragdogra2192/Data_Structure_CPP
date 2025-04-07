/* Leet Code:
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, 
the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas 
before the guards return.

Return the minimum integer k such that she can eat all the bananas 
within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

class Solution {
public:
    long long int totalHrsToFinishBananasWithKSpeed(vector<int>& piles, int h, int k)
    {//T.C - O(n)
        long long int totalhrs = 0;
        for(int i=0; i<piles.size(); i++)
        {
            totalhrs += ceil(piles[i]/(double)k); 
        }
        return totalhrs; 
    }
    //Time Comlexity: 
    //range 1 - max_val in piles. O(log(max_val)) * O(n)
    //TC = O(nlog(max_val))
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        
        int mid = start + (end - start)/2;
        int ans = 0;
        while(start <= end)
        {
            int k = mid;
            if(totalHrsToFinishBananasWithKSpeed(piles, h, k)<=h)
            {//May ot may not be the ans
                ans = k; // Store
                //Koko can eat in slower speed
                end = mid-1;
            }
            else
            {//Koko needs to increase the speed
                start = mid+1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }   
};