/*Leet code 187.

187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.

Time Complexity
The main loop slides a window of size 10 over the string s of length n.
For each window, extracting the substring is O(10) (constant).
There are n - 9 windows, so total: O(n)
Inserting into the unordered_map and iterating over it is also O(n) in the worst case.
Total time complexity:
O(n)

Space Complexity
The unordered_map can store up to O(n) unique substrings of length 10.
The answer vector can also be up to O(n) in the worst case.
Total space complexity:
O(n)

Summary:

Time: O(n)
Space: O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seqCount;
        vector<string> ans;

        if(s.size() < 10) 
        {
            return {};
        }
        int window_size = 10;
        int lastWindowIndex = s.size() - window_size;
        for(int i=0; i <= lastWindowIndex; i++)
        {
            string currentWindowSizeSubstring = s.substr(i, window_size);
            seqCount[currentWindowSizeSubstring]++;
        }

        //C++17 
        for(auto [subStr, freq] : seqCount)
        {
            if(freq > 1)
            {
                ans.push_back(subStr);
            }
        }
        return ans;
    }
};