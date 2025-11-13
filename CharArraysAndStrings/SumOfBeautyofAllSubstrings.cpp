/* Leet code 1781
1781. Sum of Beauty of All Substrings

The beauty of a string is the difference in frequencies between 
the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.
 
Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17
 
Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //Time Complexity: O(N^2)*O(26)
    int beautySum(string s) {
        int beautySum = 0;
        unordered_map<char, int> mp;
        //find all substrings
        for(int i=0; i<s.size(); i++) // O(N^2)*O(26)
        {
            mp.clear();
            for(int j=i; j<s.size(); j++)
            {
                char &ch = s[j];
                mp[ch]++; //freq update of the char ch

                int mini  = INT_MAX;
                int maxi = INT_MIN;

                //find most and least frequent ch from the map
                for(auto each : mp) //O(26) - chars
                {
                    maxi = max(maxi, each.second);
                    mini = min(mini, each.second);
                }

                int beauty = maxi - mini;
                beautySum += beauty; 
            }
        }
        return beautySum;
    }
};