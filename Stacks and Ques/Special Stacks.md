<h2> Special Stacks</h2>
<h3>Medium</h3><hr>
<div><p>
  Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional 
  operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/special-stack/1)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> Stack: 18 19 29 15 16
<strong>Output:</strong> 15
<strong>Explanation:</strong> The minimum element of the stack is 15.
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
  1. For the O(N) solution use a recursive function to delete 
  2. For O(1) its is intersesting quite interesting
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
    //O(N) => Time   O(N) => Space
  
   void push(stack<int>& s, int a){
	if(is)
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()==n?true:false;
}

bool isEmpty(stack<int>& s){
	return s.size()==0?true:false;
}

int pop(stack<int>& s){
	int ele = s.top();
	s.pop();
	return ele;
}

int getMin(stack<int>& s){
  return mini;  
    
}

int getMin(stack<int>& s){
	// Your code goes here
	int top =s.top();
	int mini =top;
	
	if(s.size()>1)
	{
	   s.pop(); 
	   mini = min(mini,getMin(s));
	}
	s.push(top);
	return mini;
}
  
  // O(1) =>Time
  
  int mini=-1;
void push(stack<int>& s, int a){
	if(s.size()==0){
	    s.push(a);
	    mini=a;
	}else if(a<mini)
	{
	    //value to be pushed is less than current min 
	    int k = 2*a- mini; //this k is always and i mean always less than mini
	    s.push(k);
	    mini = a;
	}else
	 s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()==n?true:false;
}

bool isEmpty(stack<int>& s){
	return s.size()==0?true:false;
}

int pop(stack<int>& s){
	int top =s.top();
	if(top > mini)
	 {
	     //normal element 
	     s.pop();
	     return top;
	 }else{
	     // the modified min is this value
	     top = mini; //first select the value to be returned
	     //set the mini to its previous value
	     mini = 2*mini -top;
	     s.pop();
	     return top;
	 }
}

int getMin(stack<int>& s){
  return mini;  
    
}

  ```
</div>
