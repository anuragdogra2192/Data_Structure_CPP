/* Leet code 295.
295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

Highly important question.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Time Complexity
addNum(num): Each insertion into a heap is O(log n), where n is the number of elements so far.
findMedian(): Returns the median in O(1) time.
Space Complexity
Two heaps together store all n elements: O(n)
Summary:

addNum: O(log n)
findMedian: O(1)
Space: O(n)
*/
#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;//leftpart
    priority_queue<int, vector<int>, greater<int>> minHeap;//rightpart
    double median;

public:
    MedianFinder() {
        median = 0;    
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size())
        {
            if(num > median)
            {//insert in right part
                minHeap.push(num);
                //Now update the median
                median = minHeap.top();
            }
            else
            {//insert in left part
                maxHeap.push(num);
                //Now update the median
                median = maxHeap.top();
            }
        }
        else if(maxHeap.size() == minHeap.size()+1)
        {//maxHeap ka size bada as comparision to minHeap
            if(num > median)
            {//insert in right part
                minHeap.push(num);
                //Now the size of minHeap == maxHeap
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
            else
            {//insert in left part
                //left part already bada hai
                int element = maxHeap.top();
                maxHeap.pop();
                //now insert it to the minHeap
                minHeap.push(element);
                //now insert the num into the maxHeap
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
        }
        else if(maxHeap.size() + 1 == minHeap.size())
        {//minHeap bada hai maxHeap se
            if(num > median)
            {//insert in the right part
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                minHeap.push(num);

                median = (minHeap.top() + maxHeap.top())/2.0;
            }
            else
            {//insert in to the left part
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};
/**
 * Note: We have used heap because we are interested in the middle element.
    therefore Min and Max Heap.
 */