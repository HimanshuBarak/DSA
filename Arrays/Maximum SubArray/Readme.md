<h2>Maximum Sub Array </h2>
<h3>Medium</h3><hr>
<div><p>Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length.
NOTE 2: If there is still a tie, then return the segment with minimum starting index.</p>



<h3>  Your Task: </h3>
<p> 
Complete the function findSubarray() which takes the array a and the size of the array, n, as input parameters and returns an array representing the answer. If there is no subarray return an array of length 1 containing -1 only. You don't to print answer or take inputs.
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> T
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
     
<strong>Output:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Nodes &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;=Data of a Node  &lt;= 5</code></li>
</ul>
  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	   vector<int> res;
	   int index=0,ans=-1,temp=0,f_ind=0;
	   int flag=0;
	   for(int i=0;i<n;i++)
	   {
	       if(a[i]>=0 && flag==0)
	       {
	         index=i; temp+=a[i]; flag=1;
	       }
	       else if(a[i]>=0)
	       {
	           temp+=a[i]; 
	       }
	         
	       else
	       {
	          temp=0; flag=0; 
	       }
	         
	      // cout<<temp<<"->"<<ans<<">"<<index<<endl;
	       if(temp>ans)
	       {
	           ans=temp;
	           f_ind=index;
	       }
	   }
	   
	   for(int i=f_ind;i<n;i++)
	   {
	       if(a[i]>=0)
	        res.push_back(a[i]);
	        else
	         break;
	   }
	   if(res.size()==0)
	    res.push_back(-1);
	   return res;
	}
};

  ```
</div>
