/** Geeks for geeks
Question: Stream First Non-repeating
https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Given an input stream s consisting only of lowercase alphabets. 
While reading characters from the stream, 
you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every you need to consider the string from starting position till the ith position.
 

Examples:

Input: s = "aabc"
Output: "a#bb"
Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow- "a" - first non-repeating character is 'a' "aa" - no non-repeating character so '#' "aab" - first non-repeating character is 'b' "aabc" - there are two non repeating characters 'b' and 'c',  first non-repeating character is 'b' because 'b' comes before 'c' in the stream.
Input: s = "zz"
Output: "z#"
Explanation: For every character first non repeating character is as follow- "z" - first non-repeating character is 'z' "zz" - no non-repeating character so '#' 
Input: s = "bb"
Output: "b#"
Explanation: For every character first non repeating character is as follow- "b" - first non-repeating character is 'b' "bb" - no non-repeating character so '#'  
Constraints:
1 <= s.size()<= 105
'a' <= s[i] <= 'z'

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        unordered_map<char, int> freq;
        string ans = "";
        queue<int> q;
        
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            //initial sate maintian karne ke liye
            freq[ch]++;
            q.push(ch);
            
            //let's find the ans now
            while(!q.empty())
            {
                char frontElement = q.front();
                //check whether the front element is ans or not
                if(freq[frontElement] == 1)
                {
                    ans.push_back(frontElement);
                    break;
                }
                else
                {
                    q.pop();
                }
            }
            if(q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};