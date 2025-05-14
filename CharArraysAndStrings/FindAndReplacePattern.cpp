/* Leet Code 890.
890. Find and Replace Pattern
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

Time Complexity: O(N)
As pattern and words max length is fixed.
1 <= pattern.length <= 20
1 <= words.length <= 50

Space Complexity  - O(S), S - words[i].length
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        void normalize(string &str)
        {
            //Create Mapping
            char start = 'a';
            unordered_map<char, char> mapping;
            for(int i=0; i < str.length(); i++)
            {
                char curr = str[i];
                if(mapping.find(curr) == mapping.end())
                {
                    //Not found in the map
                    mapping[curr] = start;
                    start++;
                }
            }
            //Now using the mapping we normalize the str
            for(int i=0; i < str.length(); i++)
            {
                char mapped = mapping[str[i]]; 
                str[i] = mapped;
            }//Normalized str 
        }
    
        vector<string> findAndReplacePattern(vector<string>& words, string pattern)
        {
         //Lets normalize the pattern
         cout<<pattern<<endl;
         normalize(pattern);
         cout<<pattern<<endl;
         vector<string> ans;
         //Traverse the vector of words and normalize them to compare the pattern.
         for(int i=0; i < words.size(); i++)
         {
            string word = words[i];
            normalize(word);
            if(word.compare(pattern) == 0)
            {
                ans.push_back(words[i]);
            }
         }
         return ans;
        }
    };
