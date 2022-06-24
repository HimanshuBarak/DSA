<h2>Trapping Water Problem</h2>
<h3>Hard</h3><hr>
<div><p>
  
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 
</p>


[Problem Link](https://leetcode.com/problems/trapping-rain-water/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> height = [4,2,0,3,2,5]
     
<strong>Output:</strong> 9
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

 class Solution {
public:
    int trap(vector<int>& ht) {
        
        
        //the basic concept is at each building the amount of water that 
        //can be stored is the min(tallest building on the left,tallest build on right)
        
        //BRUTE FORCE APPROACH   O(3N) => TIME 0(2N) =>SPACE
        
        //we calculate a prefix sum and suffix sum array to get the largest building
        //on left and right of each node
       /*
        int n=ht.size();
        
        vector<int> left(n,0);
        left[0]=ht[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],ht[i]);
        }
        vector<int> right(n,0);
        right[n-1]=ht[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],ht[i]);
        }
       
        int water=0;
        //finding the water stored
        for(int i=0;i<n;i++)
        {
            water+=(min(left[i],right[i])-ht[i]);
        }    
        return water;
        */
        
        // Optimal Approach O(N) => Time O(1) => Space
        
        /*the concept used here is same as well
          first we check if any building on right is grater than current element
          we find the water using leftmax
          incase the taller building is on the left ,we start to move towards it from the right
          the main thing to notice here is we always move from the direction with samller building thats the best I can explain
        */
        int n=ht.size();
        int leftmax=0,rightmax=0,water=0;
        int l=0,r=n-1;
        
        while(l<=r){
            if(ht[l]<ht[r])
            {
                if(ht[l]>leftmax)
                    leftmax=ht[l];
                else
                    water+=(leftmax-ht[l]);
                l++;
            }else{
                 if(ht[r]>rightmax)
                    rightmax=ht[r];
                else
                    water+=(rightmax-ht[r]);
                r--;
            }
        }
        return water;
    }
};
  ```
</div>
