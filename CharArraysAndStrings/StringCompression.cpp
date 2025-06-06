/* Leet code 443.
443. String Compression

Given an array of characters chars, 
compress it using the following algorithm:

Begin with an empty string s. 
For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, 
but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split 
into multiple characters in chars.

After you are done modifying the input array, 
return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars)
        {
            int prev = 0;
            int ansIndex = 0;
            int n = chars.size();
            while(prev < n)
            {   
                int curr = prev + 1;
                while(curr < n && chars[prev] == chars[curr])
                {
                    curr++;
                }
                //Here prev != curr
                //Let's store the old character first
                chars[ansIndex++] = chars[prev];
                //Now we get the count
                int count = curr - prev;
                if(count > 1)
                {
                    string str = to_string(count);
                    for(auto ch : str)
                    {
                        chars[ansIndex++] = ch;
                    }
                }
                //prev ko update karo with next character.
                prev = curr;
            }
            return ansIndex;
        }
    };
/*
Time Complexity:
Big O - O(n)	
The code iterates through the input vector 'chars' once, 
updating the 'prev' and 'curr' pointers. 
The inner while loop runs until 'curr' reaches the 
end of the vector or a different character is encountered. 
The overall time complexity is O(n) where n is the size of 
the input vector 'chars'.
*/