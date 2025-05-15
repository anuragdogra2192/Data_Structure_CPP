/* Leet code 917
917. Reverse Only Letters

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) 
should be reversed.

Return s after reversing it.

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
*/
#include<iostream>
#include<string> 
using namespace std;
class Solution {
    public:
        string reverseOnlyLetters(string s) {
            int i = 0;
            int j = s.length()-1;
            //Time Complexity - O(N)
            while(i<=j)
            {   
                //ASCII a - z                 A - Z
                //if((ch>=95 && ch<=122) || (ch>=65 && ch<=90))
                //{
                    //alphabet
                //}
                //Lets use C++ function isalpha()
                bool flag1;
                bool flag2;
    
                flag1 = std::isalpha(s[i]);
                //cout<<flag1;
                flag2 = std::isalpha(s[j]);
                //cout<<flag2;
                if(flag1 == true && flag2 == true)
                {
                    std::swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else if(flag1==true && flag2==false)
                {
                    j--;
                }
                else if(flag1==false && flag2==true)
                {
                    i++;
                }
                else if(flag1 == false && flag2 == false)
                {
                    i++;
                    j--;
                }
            }
            return s;
        }
    };