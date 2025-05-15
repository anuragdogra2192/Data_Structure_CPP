/* Leet Code 345
345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string
and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and
they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. 
On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include<iostream>
#include<string>
using namespace std;

//Time Complexity - O(N)
class Solution {
    public:
        bool isVowel(char ch)
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch = ch - 'A' + 'a';
            }
            if(ch =='a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                return true;
            }
            return false;
        }
    
        string reverseVowels(string s) {
            int i = 0;
            int j = s.length()-1;
            
            while(i<=j)
            {
                if(isVowel(s[i]) && isVowel(s[j]))
                {
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else if(!isVowel(s[i]))
                {
                    i++;
                }
                else //(!isVowel(s[j]))
                {
                    j--;
                }
            }  
            return s;  
        }
    };