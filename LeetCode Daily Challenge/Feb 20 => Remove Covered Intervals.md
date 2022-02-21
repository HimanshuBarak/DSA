<h2>Remove Covered Intervals</h2>
<h3>Medium</h3><hr>
<div><p> Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> intervals = [[1,4],[3,6],[2,8]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Interval [3,6] is covered by [2,8], therefore it is removed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,4],[2,3]]
     
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  <h2> Algorithm </h2>
  <pre>
    [[1,2],[1,4],[3,4]] 
    For this testcase we need to dont need to update count in the first iteration thats why the update is in the second if
    Hope this makes sense
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
#define f first
#define s second
class Solution {
public:
   
    static bool compare1(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),compare1);
        
        int count=1;
        pair<int,int> p ;
        p.f= v[0][0];
        p.s = v[0][1];
        

        for(int i=1; i<v.size();i++)
        {
            if(p.f < v[i][0] && p.s < v[i][1])
                count++;          
            
            if(v[i][1]>p.s)
            {    
                 p.f = v[i][0];
                 p.s = v[i][1];
            }
                
            
        }
        return count;
    }
};
  ```
</div>
