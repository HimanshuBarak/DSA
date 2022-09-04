<h2>Serialize and Deserialize a  Binary Tree</h2>
<h3>Hard</h3><hr>
<div><p>
  
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 
</p>


[Problem Link](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong> root = [1,2,3,null,null,4,5]
<strong>Output:</strong> [1,2,3,null,null,4,5]
<strong>Explanation:</strong> 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
     
<strong>Output:</strong> []
<strong>Explanation:</strong> 
</pre>

<p>&nbsp;</p>
<p><strong>Complexities:</strong></p>
<strong>Time:</strong> 
  
<strong>Space:</strong> 
  <h2> Algorithm </h2>
 <pre>
  1. 

  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
  class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        
        string res="";
        if(!root) return res;
        
        while(!q.empty())
        {
            TreeNode* curr =q.front();
            q.pop();
            
            if(curr==NULL)
                res+="#,";
            else
                res+= (to_string(curr->val)+",");
            
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
      //  cout<<res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        
        getline(s,str,','); //from s till , store in str
        TreeNode* root = new TreeNode(stoi(str));;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->left=temp;
                q.push(temp);
            }
            getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->right=temp;
                q.push(temp);

            }
        }
        return root;
    }
};
  ```
</div>
