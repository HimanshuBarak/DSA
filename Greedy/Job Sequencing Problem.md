<h2>Job Sequencing Problem</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
 
</p>


[Problem Link](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
<strong>Output:</strong> 2 60
<strong>Explanation:</strong> Job1 and Job3 can be done with
maximum profit of 60 (20+40).

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
   // { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
   static bool comp(Job a,Job b){
        return a.profit >b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        //we make slot for each deadline 
        int slot[maxi+1];
        //initally all slots are empty
        memset(slot,-1,sizeof(slot));
        //filling these slots one by one
        for(int i=0;i<n;i++)
        {
            int j=arr[i].dead;
            while(j)
            {   //if the slot is empty assign the job else check for any empty slot before this one
                if(slot[j]==-1){
                   slot[j] = arr[i].profit;break;  
                }
                
                j--; 
            }
        }
        int cnt=0,profit=0;
        for(int i=1;i<=maxi;i++)
        {
            if(slot[i]!=-1)
             cnt++,profit+=slot[i];
        }
        return {cnt,profit};
    } 
};
  ```
</div>
