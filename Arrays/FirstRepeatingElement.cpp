/*GEEKS FOR GEEKS 
First Repeating Element

Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. 

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.
Constraints:
1 <= arr.size <= 106
0 <= arr[i]<= 106
*/


//TIME COMPLEXITY: O(n)
//SPACE COMPLEXITY: O(n)

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        unordered_map<int, int> hash;
        //Storing the occurrences
        for(int i=0; i<arr.size(); i++)
        {
            if(hash[arr[i]])
                hash[arr[i]] += 1;
            else
                hash[arr[i]] = 1;
        }
        //Finding the first repeated element
        for(int i=0; i<arr.size(); i++)
        {
            if(hash[arr[i]] > 1)
            {
                return i+1;
            }
        }
        return -1;
    }
};