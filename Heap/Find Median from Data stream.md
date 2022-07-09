<h2>Find Median from Data Stream</h2>
<h3>Hard</h3><hr>
<div><p>
 The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted. 

  <h4> Constraints </h4>
  
 
</p>


[Problem Link](https://leetcode.com/problems/find-median-from-data-stream/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
<strong>Output:</strong> [null, null, null, 1.5, null, 2.0]
<strong>Explanation:</strong> MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class MedianFinder {
public:
     priority_queue<int> maxheap;
     priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
       
    }
    //takes O(log(n))
    void addNum(int num) {
        //this the main thing
        if(maxheap.empty() || maxheap.top()>num)
             maxheap.push(num);
        else
            minheap.push(num);
        
        //balancing both the heaps
        
         if(maxheap.size()>(1+minheap.size()))
        {
            minheap.push(maxheap.top());
            maxheap.pop();  
        }else if((maxheap.size()+1)<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
         } 
    }
    //happens in O(1)
    double findMedian() {
        if(minheap.size()==maxheap.size())
            return (maxheap.top()+minheap.top())/2.0;
        else
            return maxheap.size()>minheap.size()?maxheap.top():minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
  ```
</div>
