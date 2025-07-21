/* Leet Code 621.
621. Task Scheduler

You are given an array of CPU tasks, each labeled with a letter
 from A to Z, and a number n. 
 Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required 
to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100

Time Complexity: O(n * m)
m - idle time, max it would be 100, not so much
n - number of tasks.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto task : tasks)
        {
            freq[task]++;
        }
        //Lets have a maxHeap of frequencies.
        priority_queue<int, vector<int>> maxHeap;
        for(auto f : freq)
        {
            maxHeap.push(f.second);
        }
        //pair containing currentFreq, nextAvailableTime
        queue<pair<int, int>> q; 
        int time = 0;
        //main logic 
        while(!maxHeap.empty() or !q.empty())
        {   
            time += 1;
            if(!maxHeap.empty())
            {
                //1) take out the task to process
                int taskFreq = maxHeap.top();
                maxHeap.pop();
                //2) Task processed
                taskFreq -= 1;
                //3) queue mein update karo current taskfreq and next available time
                int nextAvailableTime = time + n;
                if(taskFreq != 0)//if more task of this type.
                {
                    q.push({taskFreq, nextAvailableTime});
                }
            }
            
            //4) Check queue for next available task for heap update.
            if(!q.empty())
            {
                auto front = q.front();
                if(front.second == time)
                {
                    q.pop();
                    maxHeap.push(front.first);
                }
            }
        }
        return time;
    }
};