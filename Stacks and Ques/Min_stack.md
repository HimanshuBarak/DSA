<h2>Min Stack</h2>
<h3>Medium</h3><hr>
<div><p>
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
</p>


[Problem Link](https://leetcode.com/problems/min-stack/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> ["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>Output:</strong> [null,null,null,null,-3,null,0,-2]
<strong>Explanation:</strong> MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> O(1) for each operation
  
<strong>Space:</strong>  O(N)
  <h2> Notes </h2>
 <pre>
    
            so we can do it using 2 stacks or a single stack

            when using 2 stack we need to maintain a stack of previous minimum 


            using a single stack we can do it more efficiently

            so in case of one stack what we do is when we encounter a element
            less than our min element we push the previous min in the stack
            before pushing the new min

            the reason we do is because when the new min is deleted we can easily replace
            it as we know for a fact that the new min is the top element of the stack 

        
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
   class MinStack {
public:
    MinStack() {
       
    }
    stack<int> s1,s2;
    
    int min =INT_MAX;
    void push(int x) {
       
	    if (x<=min)  
        {
           s1.push(min);
           min=x;
        }
          
        s1.push(x);	
    }
    
    void pop() {
        if(s1.top()==min)
        { 
            s1.pop();
            min =s1.top();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
  ```
</div>
