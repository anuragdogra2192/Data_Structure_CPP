/* Leet Code 205
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced 
to get t.

All occurrences of a character must be replaced with another character 
while preserving the order of characters. 
No two characters may map to the same character, 
but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs 
to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            //Map the chars of s to t
            char map_s_t[256]={0};
            bool is_t_CharMapped[256];//This is for the case: baba -> badc
            string ans;
            for(int i = 0; i<s.length(); i++)
            {
                if((is_t_CharMapped[t[i]] ==  false) && (map_s_t[s[i]] == 0))
                { 
                    map_s_t[s[i]] = t[i];  
                    is_t_CharMapped[t[i]] = true;
                }   
            }
    
            for(int i = 0; i<s.length(); i++)
            {
                if(t[i] != map_s_t[s[i]])
                {
                    return false;
                }
            }
            //Track whats already mapped in vector
            return true;
        }
    };