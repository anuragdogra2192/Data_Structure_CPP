/* Leet code 127.
127. Word Ladder
Highly important - Interview
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/
#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        //Intial state
        q.push({beginWord, 1});
        //Unordered set // Dijkstra algorithm
        //copy my word list to set
        unordered_set<string> st(wordList.begin(), wordList.end());

        //kynki main beginWord use kar chuka hu queue mein
        //toh i should erase it from the dictionary or set
        st.erase(beginWord);

        //Main logic
        while(!q.empty())
        {
            pair<string, int> frontPair = q.front();
            q.pop();
            string frontString = frontPair.first;
            int frontDist = frontPair.second;

            //check kar lo, jo frontString hai wo ans toh nahi hai
            if(frontString == endWord)
            {
                return frontDist;
            }
            else
            {//nhi mili hai ans string
                for(int index=0; index<frontString.length(); index++)
                {
                    char originalChar = frontString[index];
                    //we will replace this front char and check
                    //that's why we first store it in originalChar, to keep a copy
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        frontString[index] = ch;
                        //check if the new string is there in the dictionary or not
                        if(st.find(frontString) != st.end())
                        {//valid string
                            q.push({frontString, frontDist+1});
                            //ab set se delete kar do
                            st.erase(frontString);
                        }
                    }
                    //yeah bhul jate hai
                    //backtrack, to maintain orginal state
                    frontString[index] = originalChar;
                }
            }
        }
        return 0;
    }
};