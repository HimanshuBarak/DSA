<h2>N meetings in one room </h2>
<h3>Easy</h3><hr>
<div><p>There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

</p>



<h3>  Your Task: </h3>
<p> 
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.
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


  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution
{
    public:
    
   static  bool comp(const pair<int,int> &a,const pair<int,int> &b){
        return a.second <b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back(make_pair(start[i],end[i]));
        }
        
        sort(v.begin(),v.end(),comp);
         pair<int,int> prev;
        prev =v[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(v[i].first >prev.second)
            {
                count++;
                prev =v[i];
            }
        }
        
        return count;
    }
};

  ```
</div>
