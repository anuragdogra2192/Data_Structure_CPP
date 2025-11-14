/* Leet code
68. Text Justification

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth 

Time Complexity: O(n^2); n = num of words;
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currentLine;
        int currentLineTotalChars = 0;
        for(int i = 0; i < words.size(); i++)
        {
            string &currentWord = words[i];
            int currentLineNeededSpaces = currentLine.size(); //single space after space
            if (currentLineTotalChars + currentLineNeededSpaces + currentWord.size() > maxWidth) 
            {//Means we have exceeded the maxWidth.
                //Fully justified case
                //lets form a line with space.
                //extraspaces = abs(currentLine - maxWidth)
                //spaces in b/w = extraspaces / (currentLine.size() - 1)
                //remainder extraspaces = extraspaces % (currentLine.size() - 1);
                int extraSpaces = maxWidth - currentLineTotalChars;
                int spaceBtwnWords = extraSpaces / max(1, (int)(currentLine.size() - 1)); // max used to avoid divide / 0
                int remainder = extraSpaces % max(1, (int)(currentLine.size() - 1));

                //We don't need spaces after last word
                for(int j=0; j<currentLine.size() - 1; j++)
                {
                    //add even spaces
                    for(int k=0; k<spaceBtwnWords; k++)
                    {
                        currentLine[j] += " "; //add spaces after the word
                    }
                    if(remainder > 0)
                    {
                        currentLine[j] += " ";
                        remainder--;
                    }
                }

                if(currentLineNeededSpaces == 1)
                {//left justified case, only one word
                    while(extraSpaces--)
                    currentLine[0] += " "; 
                }

                //lets prepare our final line
                string finalLine = "";
                for(string wordWithSpaces :  currentLine)
                {
                    finalLine += wordWithSpaces;
                }
                ans.push_back(finalLine);
                currentLine.clear();
                currentLineTotalChars = 0;
            }
            //current line not complete
            currentLine.push_back(currentWord);
            currentLineTotalChars += currentWord.size();
        }

        //lets handle the last line
        //add one space b/w words 
        string finalLine = "";
        for(auto word : currentLine)
        {
            finalLine += word + " ";
        }
        finalLine.pop_back(); //remove extra added space

        //if still maxwidth id not achieved
        int leftSpaces = maxWidth - finalLine.size();
        while(leftSpaces--)
        {
            finalLine += " ";
        }
        ans.push_back(finalLine);
        return ans;
    }
};