/* Leet code 49.
49. Group Anagrams

Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
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

/*
Time Complexity of groupAnagramsMethod2
Let:

N = number of strings in strs
K = maximum length of a string
Step-by-step:

For each string, you compute its character frequency array (getHash):
O(K) per string (since you scan each character)
For all strings: O(NK)
Inserting into the map and building the answer:
Each map operation is O(log N) (for std::map), but the array comparison is O(256) = O(1) (constant).
So, for all strings: O(N log N) (but dominated by O(NK) if K is large).
Building the final answer vector:
O(N) (each string is pushed once)
Total time complexity:
O(NK) (since K can be up to 100, and log N is much smaller than K for large K)

Summary:

Time: O(NK)
*/

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

/*
Note:
Why std::map and not unordered map?

You cannot use unordered_map<std::array<int, 256>, vector<string>> directly because:

std::unordered_map requires the key type (std::array<int, 256>) to be hashable.
By default, std::array<int, 256> does not have a hash function defined in the C++ standard library.

std::map works because it only needs the < operator, which std::array provides (lexicographical comparison).
If you want to use unordered_map with std::array<int, 256> as the key, you must define a custom hash function.

Summary:
std::map works out of the box with std::array as key.
std::unordered_map does not work with std::array as key unless you provide a custom hash.
*/