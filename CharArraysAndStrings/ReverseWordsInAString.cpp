/* Leet code 151.
151. Reverse Words in a String

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.


Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

Follow-up: If the string data type is mutable in your language, 
can you solve it in-place with O(1) extra space?

Time Complexity: O(n) 
*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0, end = 0;
        
        for(int i=0; i<n; i++)
        {
            //skip leading spaces
            while(i < n && s[i] == ' ')
            {
                i++;
            }
            if(i == n) break;// out of bound check
            
            //copy char to the right poistion
            while(i < n && s[i] != ' ')
            {
                s[end++] = s[i++];
            }
            
            // after copy, reverse the individual word
            reverse(s.begin() + start, s.begin() + end);

            //add extra space between the words
            s[end++] = ' ';
            //update the start
            start = end;
        }

        //resize the final string 
        s.resize(end - 1);
        return s;
    }
};