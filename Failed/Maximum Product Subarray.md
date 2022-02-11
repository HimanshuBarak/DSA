<h2>Maximum Product Subarray </h2>
<h3>Medium</h3><hr>
<div><p>Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
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
 long long int ans=INT_MIN,temp=1;
	   // cout<<ans;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==0)
	         temp=1;
	        else
	         temp*=a[i];
	         
	         ans = max(temp,ans);
	    }
	    temp=1;
	    for(int i=n-1;i>=0;i--)
	    {
	        if(a[i]==0)
	         temp=1;
	        else
	         temp*=a[i];
	         
	         ans = max(temp,ans);
	    }
	    
	    return ans;

  ```
</div>
