<h2>Print all K Sum Paths in a Binary Tree </h2>
<h3>Medium</h3><hr>
<div><p>Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).</p>



<h3>  Your Task: </h3>
<p> 
Return total no of such paths which sum of to TargetSum
</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
<strong>Output:</strong> 3
<strong>Explanation:</strong> The paths that sum to 8 are shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
     
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= Number of Nodes &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;=Data of a Node  &lt;= 5</code></li>
</ul>
  
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int count=0;
    void ksum(TreeNode* root,vector<int> &v,int k)
    {
        if(!root) return;
        
        v.push_back(root->val);
        
        ksum(root->left,v,k);
        ksum(root->right,v,k);
        
        int sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            sum+=v[i];
            if(sum==k)
                count++;
        }
        v.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        ksum(root,v,targetSum);
        return count;
    }
};
  ```
</div>
