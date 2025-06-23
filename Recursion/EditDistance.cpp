/** Leet Code:
 * 72. Edit Distance - Interview (hard Category)
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

Time Limit Exceeded: Can be improved by DP.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int solve(string& word1, string& word2, int i, int j)
    {
        //Base Case:
        if(i >= word1.length())
        {//word1 wali string khatam ho gayi hai
         //word1 may be word2 se choti hai.
          return word2.length() - j; //Remaining words2 return 
        }

        if(j >= word2.length())
        {//word2 wali string khatam ho gayi hai
          //word2 maybe word1 se choti hai
          return word1.length() - i; 
        }

        int ans = 0;
        if(word1[i] == word2[j])
        {//match hai toh
        //ans 0 hogaya + aage bad jate hai.
            ans = 0 + solve(word1, word2, i+1, j+1);
        }
        else//Not match
        {//Means operation performed, toh +1 toh kardo (+1 add karna bhul jate hai apan.)
            //insert
            int option1 = 1 + solve(word1, word2, i, j+1);
            //remove
            int option2 = 1 + solve(word1, word2, i+1, j);
            //replace
            int option3 = 1 + solve(word1, word2, i+1, j+1);
            ans = min(option1, min(option2, option3));
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        int ans = solve(word1, word2, i, j);
        return ans;
    }
};