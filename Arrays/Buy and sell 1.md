<h2>Buy and Sell 1</h2>
<h3>Easy</h3><hr>
<div><p>
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 
</p>


[Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> prices = [7,1,5,3,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
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
  1. This is simple we just need to find the difference between a value and a value preceding teh value
  2. Thus we choose a min ,keep updating it
  3. keep finding the ma profit 
  4. Tadaaa Done
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int res=0;
        int mini=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<mini)
                mini =prices[i];
            else
                res= max(res,prices[i]-mini);
        }
        
        return res;
    }
};
  ```
</div>
