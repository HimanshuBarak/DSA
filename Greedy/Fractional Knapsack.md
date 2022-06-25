<h2>Fractional Knapsack</h2>
<h3>Easy</h3><hr>
<div><p>
  Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
<strong>Output:</strong> 
<strong>Explanation:</strong> Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
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
  1. Self explanatory
  2.
  3. 
  4. 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution
{
    public:
     static bool comp(Item a,Item b){
         return ((double)a.value/(double)a.weight)> ((double)b.value/(double)b.weight);
     }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double prof=0;
        sort(arr,arr+n,comp);
        int i=0;
        while(i<n && W>0)
        {
            if(arr[i].weight<=W)
              prof+=arr[i].value ,W-=arr[i].weight;
            else 
             {
                 prof = prof+ ((double)(arr[i].value)/(double)(arr[i].weight))*W;
                 W=0;
             }
             i++;
        }
        return prof;
    }
        
};
  ```
</div>
