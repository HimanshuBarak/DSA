<h2>Yet another Constructive Problem (code :ORANDCON) </h2>
<h3>Easy</h3><hr>
<div><p>You are given a positive integer X which is at most 108.

Find three distinct non-negative integers A,B,C that do not exceed 109 and satisfy the following equation:

(A∣B)&(B∣C)&(C∣A)=X
Here, ∣ denotes the bitwise OR operator and & denotes the bitwise AND operator.

It can be shown that a solution always exists for inputs satisfying the given constraints. If there are multiple solutions, you may print any of them.
</p>




<p>&nbsp;</p>
<p><strong>Input 1:</strong></p>

  ```
4 
3 
2 
13
100000000
 ```     
 

<strong>Output:</strong> 
  ```
1 2 3
2 3 4
6 9 13
23570468 129811858 80835401
  ```
<strong>Explanation:</strong> (1∣2)&(2∣3)&(3∣1)=3&3&3=3  and hence A=1,B=2,C=3 is one valid solution when X=3. However there are several other solutions.

For example, A=1,B=6,C=3 is also valid and will also be considered correct.


<p><strong>Input 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  
  <h2> Solution </h2>
  
  ``` c++ 
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	 int x;
	
	while(t--)
	{
	    cin>>x;
	    int a =x|(1<<28);
	    int b =x|(1<<29);
	    cout<<x<<" "<<a<<" "<<b<<endl;
	}
	return 0;
}

  ```
</div>
