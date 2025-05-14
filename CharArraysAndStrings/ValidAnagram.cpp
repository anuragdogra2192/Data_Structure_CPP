/* Leet Code 242
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? 
How would you adapt your solution to such a case?
Method 1 is suitable for unicode.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isAnagramMethod1(string& s, string& t)
        {   //Time Complexity O(nlog(n))
            //brute force method sort and compare.
            //For unicode this will work
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            
            return(s.compare(t) == 0);
        }
        bool isAnagramMethod2(string& s, string& t)
        {   
            //Counting method
            //Create a frequency table of chars in 's' string
            //and chars in 't' string.
            //Finally compare the tables. same == true.
            //How to make freq. table for strings.
            //Only work for ASCIIs
            int freqTable[256] = {0}; //0-255 ASCII values for strings
            
            for(int i=0; i<s.size();i++)
            {
                freqTable[s[i]]++; //updating the frequency of ith char position.
            }//O(N)
            //Lets use the same freqTable and decrement the frequencies as we found
            //in second string. If the freqTable has all 0 values means s and t are anagram.
            for(int i=0; i<t.size(); i++)
            {
                freqTable[t[i]]--;//Decrement
            }//O(M)
    
            for(int i=0; i<256; i++)
            {
                if(freqTable[i] != 0)
                {
                    return false;
                }
            }//O(256).
            return true;
            //Time Complexity - O(N) + O(M) + O(256)
            //Space Complexity - O(256) constant.
        }
    
        bool isAnagram(string s, string t) {
            //return isAnagramMethod1(s, t);
            return isAnagramMethod2(s, t);
        } 
    };
