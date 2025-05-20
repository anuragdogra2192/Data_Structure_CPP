/* Leet Code 767.
767. Reorganize String
Given a string s, rearrange the characters of s 
so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        //Better method for Time Complexity is to 
        // use Priority Queue DS O(nlogn).
        // Now we will solve using Greedy Approach.
        string reorganizeString(string s) {
            int n  = s.length();        
            int hash[26] = {0}; //lower alphabet char
            
            for(int i = 0; i<n; i++)
            {//s[i]-'a' -> to normalize index 0-25
                hash[s[i]-'a']++;
            }
            //If we are here means answers exists
            int max_freq_char;
            int max_freq = INT_MIN;
            for(int i=0; i<26; i++)
            {
                if(hash[i] > max_freq)
                {
                    max_freq = hash[i];
                    max_freq_char = i + 'a';
                }
            }
            int index = 0;
            while(max_freq > 0 && index < s.size())
            {
                s[index] = max_freq_char;
                max_freq--;
                index+=2;
            }
            //Lets check
            if(max_freq != 0)
            {
                //Still the max freq char remained means
                //it will appear adjacent.
                return ""; 
            }
            //If we are here, we can fill the remianing characters
            hash[max_freq_char - 'a'] = 0;
            for(int i=0; i<26; i++)
            {
                while(hash[i]>0)
                {
                    index = (index >=s.size()) ? 1 : index;
                    s[index] = i + 'a';
                    hash[i]--;
                    index += 2;
                }        
            }
            return s;
        }
    };

/* Time Complexity:
    O(n): The code iterates through the input string once to 
          calculate the frequency of each character, 
          then iterates through the alphabet characters 
          to fill the string. 
          The overall time complexity is O(n) 
          where n is the length of the input string.
*/