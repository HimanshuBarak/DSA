<h2></h2>
<h3>Hard</h3><hr>
<div><p>
  insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".

 
</p>


[Problem Link](https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0)

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
   /*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* links[26]; //one for each alphabet
    bool flag; //to indicate the end of a given word
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    //for checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
    void setEnd() {
        flag = true;
    }
};

class Trie {
   Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
          root = new Node();
    }

    /** Inserts a word into the trie. Time => (length of the word) */
    void insert(string word) {
         Node* node =root;
        for(int i=0;i<word.length();i++)
        {
            // if the letter is not already present in the trie add it
            if(!node->containsKey(word[i]))
            {  //adding a new empty refernce to a boolean false element
                node->put(word[i],new Node());
            }
            node = node->get(word[i]); //move to the reference pointed by the letter
        }
        // adding the end of the word
        node->setEnd();
    }

    /** Returns if the word is in the trie  O(N) time => length of the world. */
    bool search(string word) {
         Node* node =root;
        for(int i=0;i<word.length();i++)
        {
           if(!node->containsKey(word[i]))
               return false;
            //else move to the refernce pointer by the node
            node =node->get(word[i]); 
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
          Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
  ```
</div>
