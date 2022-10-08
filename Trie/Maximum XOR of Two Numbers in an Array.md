<h2>Maximum XOR of Two Numbers in an Array</h2>
<h3>Medium</h3><hr>
<div><p>
  Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 
</p>


[Problem Link](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>
<strong>Output:</strong> 
<strong>Explanation:</strong> 
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
   struct Node{
    Node* links[2];
    bool flag;
    
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
};

class Trie{
    Node* root;
    public:
    Trie()
    {
        root =new Node();
    }
     void insert(int num)
     {
         Node* node =root;
         for(int i=31;i>=0;i--)
         {
             int bit = (num>>i)&1 ; //find if the bit at this index is 0 or 1
             if(!node->containsKey(bit))
                 node->put(bit,new Node());
             node=node->get(bit);
         }
         
     }
    int getMax(int num){
         Node* node =root;
        int maxNum=0;
         for(int i=31;i>=0;i--)
         {
             int bit = (num>>i)&1 ; //find if the bit at this index is 0 or 1
             if(node->containsKey(1-bit)){
                  maxNum = (maxNum)|1<<i;
                  node=node->get(1-bit);
             }
             else
             node=node->get(bit);
         }
        return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj = new Trie();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            obj->insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            ans = max(obj->getMax(nums[i]),ans);
        }
        return ans;
    }
};

  ```
</div>
