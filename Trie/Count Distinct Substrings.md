<h2>Count Distinct Substrings</h2>
<h3>Medium</h3><hr>
<div><p>
  
Couldn't copy paste the question statement,coding ninja sucks 
 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0)

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
 
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
struct Node{
    Node* links[26];
    bool flag;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
};

class Trie{
   Node* root;
    
    public:
    int cnt=1;
    Trie()
    {
        root =new Node();
    }
    void insert(string &s,int index){
        Node* node = root;   
        for(int i=index;i<s.length();i++)
        {
            if(!node->containsKey(s[i]))
            {
                node->put(s[i],new Node());
                cnt++;
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
};

int countDistinctSubstrings(string &s)
{
    //this is a good question
    //lessss goooooo
    Trie* obj = new Trie();
    
    for(int i=0;i<s.length();i++)
    {
        obj->insert(s,i);
    }
    return obj->cnt;
}
  ```
</div>
