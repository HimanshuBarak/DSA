<h2>Longest String with all Prefixes</h2>
<h3>Medium</h3><hr>
<div><p>
  Given a string of arrays find a complete string. A string is called complete if all its prefixes are also present in the input array.
  
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos)

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
     struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    bool checkIfAllPrefixExists(string &s)
        {
            Node* node =root;
            for(int i=0;i<s.length();i++)
            {
               if(!node->containsKey(s[i]))
                {
                    return false;
                } 
                node =node->get(s[i]);
                if(!node->isEnd())
                    return false;
            }
            
            return true;
        }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(auto word : a) obj->insert(word); 
    string longest = ""; 
    for(auto word: a) {
        if(obj->checkIfAllPrefixExists(word)) {
            if(word.size() > longest.size()) {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) {
                longest = word; 
            }
        }
    }
    if(longest == "") return "None"; 
    return longest; 
}
  ```
</div>
