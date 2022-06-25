<h2>Minimum Platforms</h2>
<h3>Medium</h3><hr>
<div><p>
  
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
<strong>Output:</strong> 3
<strong>Explanation:</strong> Minimum 3 platforms are required to 
safely arrive and depart all trains.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>  n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 
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
     //ultra  bruteforce approach
  int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> tp;
        for(int i=0;i<n;i++)
        {
            tp.push_back({arr[i],dep[i]});
        }
        vector<int> plat;
        sort(tp.begin(),tp.end());
        
        plat.push_back(tp[0].second);
    	for(int i=1;i<n;i++)
    	{   bool f=false;
    	    for(int j=0;j<plat.size();j++)
    	    {    
    	        if(tp[i].first>plat[j])
    	        {
    	            f=true;
    	            plat[j]=tp[i].second;
    	            break;
    	        }
    	    }
    	    if(!f)
    	     plat.push_back(tp[i].second);
    	}
    	
    	return plat.size();
    }
  //using min heap
  int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> tp;
        for(int i=0;i<n;i++)
        {
            tp.push_back({arr[i],dep[i]});
        }
       
        sort(tp.begin(),tp.end());
        int cnt=1;
        priority_queue<int,vector<int> ,greater<int>> pq; //min element remains on top (min heap)
        pq.push(tp[0].second);
    	for(int i=1;i<n;i++)
    	{   
    	   if(pq.top()<tp[i].first)
    	     pq.pop();
    	   else
    	     cnt++;
    	   pq.push(tp[i].second);  
    	}
    	
    	return cnt;
    }
  
  ```
</div>
