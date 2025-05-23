/* Leet code 1209.
1209. Remove All Adjacent Duplicates in String II

You are given a string s and an integer k, a k 
duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 
Constraints:

1 <= s.length <= 105
2 <= k <= 104
s only contains lowercase English letters.
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
    public:
        bool areLastK_1CharsSame(const string& ans, const char& newCh, int k_1)
        {
            int it = ans.size()-1;
            for(int i=0; i<k_1; i++)
            {
                if(newCh != ans[it])
                    return false;
                it--; 
            }
            return true;
        }
    
        string removeDuplicatesMethod1(string s, int k) {
            //Time Complexity - O(NK)
            string ans="";
            for(int i=0; i< s.size(); i++)
            {
                char& newCh = s[i];
                if(ans.size() < k-1)
                {
                    ans.push_back(newCh);
                }
                else
                {
                    if(areLastK_1CharsSame(ans, newCh, k-1))
                    {
                        for(int j=0; j<k-1; j++)
                        {
                            ans.pop_back();
                        }
                    }
                    else
                    {
                        ans.push_back(newCh);
                    }
                }
            }
            return ans;
        }
        //BEST APPROACH
        string removeDuplicatesMethod2(string s, int k) {
            //Two pointer approach -
            //Time complexity: O(N)
            //Incredible
            /* Steps:
            1) s[i] = s[j]
            2) count[i] = 1
            3) if(i>0 && s[i-1] == s[i])
                count[i]+=count[i-1];
            4) count[i] == k
                move i = i-k
            5) i++, j++
            */
            string ans="";
            int n = s.size();
            vector<int> count(n);
            int i = 0, j=0; 
            while(i<=j && j<n)
            {   
                //Step 1
                s[i] = s[j];
                //Step 2
                count[i] = 1;
                //Step3
                if(i>0 && s[i] == s[i-1])
                {
                    count[i] += count[i-1];
                }
                //Step 4
                if(count[i] == k)
                {
                    i = i-k;
                }
                //Step 5
                i++ , j++;
            }
            ans = s.substr(0, i);// i == size of ans.
            return ans;
        }
    
        string removeDuplicates(string s, int k)
        {
            //return removeDuplicatesMethod1(s, k);
            return removeDuplicatesMethod2(s, k);
        }
    };