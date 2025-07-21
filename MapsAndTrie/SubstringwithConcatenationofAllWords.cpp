/* Leet code 30. Substring with Concatenation of All Words

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.


Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

Time Complexity
Let:

n = length of string s
m = number of words in words
k = length of each word
Analysis:

For each offset in [0, k), you scan the string in steps of k.
For each position, you may need to check up to m words (in the worst case, due to the sliding window and while loop).
So, for each offset: O(n)
For all offsets: O(k * n)
For each window, the while loop can run up to m times, so worst-case: O(m)
Total time complexity:
O(n * k) (practically, O(n * m * k) in worst case, but usually O(n * k))
Space Complexity
The map and visited hash maps store up to m words.
Space complexity:
O(m)
Summary:

Time: O(n * k) (worst-case O(n * m * k))
Space: O(m)
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
//Map ka sabse tough question hai.
    unordered_map<string, int> map; //track each word ka count

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        for(int i=0; i<words.size(); i++)
        {
            map[words[i]]++;
        }    
        int wordLength = words[0].length();
        
        //offset logic start -> 0,1,2 < wordLength, offsest.
        for(int offset=0; offset<wordLength; offset++)
        {
            unordered_map<string, int> visited;
            //ans mila kya track karne ke liye we need to track count
            int count = 0;
            //ab main wordLength k substring uthaunga and check karunga
            for(int i=offset; i+wordLength <= s.length(); i = i + wordLength)
            {
                string substr = s.substr(i, wordLength);
                //check whether the string is valid or not
                if(map.find(substr) == map.end())
                {//invalid string 
                 //purane saare answer ko bhulana chahiye
                 //naye start karna chahiye
                 visited.clear();
                 count = 0;
                 continue;
                }
                else
                {//valid string
                    visited[substr]++;
                    count++; 

                    //GAME CHANGER - removal kaise karoge
                    while(visited[substr] > map[substr])
                    {
                        //each word must be removed from visited and count
                        string temp = s.substr(i-(count-1)*wordLength, wordLength);
                        visited[temp]--;
                        count--;
                    }
                    //GAME CHANGER - Never forget this logic

                    //ans mila kya
                    if(count == words.size())
                    {//ans mil gaya 
                     //then insert the starting index into ans
                        ans.push_back(i-(count-1)*wordLength);
                    }
                }
            }
        }
        return ans;
    }
};