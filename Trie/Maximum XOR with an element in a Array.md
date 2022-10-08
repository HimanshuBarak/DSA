<h2>Maximum XOR with an element of an Array</h2>
<h3></h3><hr>
<div><p>
  You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 
</p>


[Problem Link](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
<strong>Output:</strong> [3,3,7]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
     
<strong>Output:</strong> [15,-1,5]
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
   struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};

class Solution {
public:
    /*
     Think about this problem I mean really think about this problem this is similar to the previous problem " Find max XOR of two elements in an array"
     Here we just need to make sure tht our trie contains elements lesser than the 
     queries ,we need to sort the queries
    */
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> q; //the second pair is to store the index
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(q.begin(),q.end());
        int j=0;
        Trie* obj = new Trie();
        vector<int> res(q.size(),0);
        for(int i=0;i<q.size();i++)
        {
            while(j<nums.size() && nums[j]<=q[i].first)
            {
                obj->insert(nums[j]);;
                j++;
            } 
            if(j==0)
                res[q[i].second.second]=-1;
            else
                res[q[i].second.second] =obj->findMax(q[i].second.first);
            
        }
        return res;
    }
};
  ```
</div>
