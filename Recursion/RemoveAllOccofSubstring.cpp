/* Leet Code
1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void removeOccurrencesRec(string& s, string& part)
        {   //Time complexity: O(N/K) * O(NK)
            //Space Complexity: O(N/K)
            int found = s.find(part);
            //Base case
            if(found == std::string::npos)
            {
                return;
            }
            //1K Case mein solve karungas
            s.erase(found, part.size());
            //Baaki recursion sambhal lega
            removeOccurrencesRec(s, part);
        }
        //Iterative has better perfromace for sure.
        string removeOccurrencesMethod1(string& s, string& part) {
            while(s.find(part)!=string::npos)
            {
                int pos = s.find(part);
                s.erase(pos, part.size());
            }
            return s;
        }
    
        string removeOccurrences(string s, string part) {
            //return removeOccurrencesMethod1(s, part);
            removeOccurrencesRec(s, part);
            return s;
        }
    };