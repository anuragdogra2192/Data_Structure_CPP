/* Leet code 49.
49. Group Anagrams

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged 
to form each other.

The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<map>
using namespace std;

class Solution {
    public:
        std::array<int, 256>getHash(string str)
        {
            array<int, 256>hash={0};
            for(int i=0; i<str.length(); i++)
            {
                hash[str[i]]++;
            }
            return hash;
        }
    
        vector<vector<string>> groupAnagramsMethod2(vector<string>& strs)
        { //Better Time Complexity.
            std::map<std::array<int, 256>, vector<string>> map_anagrams;
            for(auto str : strs)
            {   
                map_anagrams[getHash(str)].push_back(str);
            }
            vector<vector<string>> ans;
            for(auto it=map_anagrams.begin(); it!=map_anagrams.end(); it++)
            {
                ans.push_back(it->second);
            }
            return ans;
            //N is the length of strings
            //K is the length of max string
            //Time Complexity - O(NK)
            //Space Complexity - O(NK)
        }
    
        vector<vector<string>> groupAnagramsMethod1(vector<string>& strs) {
            unordered_map<string, vector<string>> map_anagrams;
            for(auto str : strs)
            {   string temp = str;
                sort(temp.begin(), temp.end());
                map_anagrams[temp].push_back(str);
            }
            vector<vector<string>> ans;
            for(auto it=map_anagrams.begin(); it!=map_anagrams.end(); it++)
            {
                ans.push_back(it->second);
            }
            return ans;
            //N is the length of strings
        //K is the length of max string
        //Time Complexity - O(NKLogK)
        //Space Complexity - O(NK)
        }
    
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            //return groupAnagramsMethod1(strs);
            return groupAnagramsMethod2(strs);
        }
    };