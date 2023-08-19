<h2> Word Ladder II </h2>
<h3>Hard</h3><hr>
<div><p>
 A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk]. 

 
</p>


[Problem Link](https://leetcode.com/problems/word-ladder-ii/description/)

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

      
 
<pre><strong>Input:</strong>  beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
<strong>Explanation:</strong>  [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
<strong>Output:</strong> There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>  beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
     
<strong>Output:</strong> []
<strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
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
 class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
          /*
           just like in word ladder we will use bfs because we want to keep track of the shortest 
           path
           
           but while traversing we will be storing the sequence in the queue itself
           queue will be of type vector<string> to store the sequence itself
          */
        
        //storing everything in a hashset to make the searching easier
        unordered_set<string> words;
        for(auto x:wordList)
          words.insert(x);

        vector<vector<string>> res;
        queue<vector<string>> q;
        vector<string> v;
        v.push_back(beginWord);
        q.push(v);
        //create a visited hashset so we dont' take the same word again and again for our path
       
        // we also need to maintain a vector for marking the nodes visited in a given level
        // this is actually very imp to the solution since we are looking for multiple paths
        // we dont directly put a word in vis when it gets visited but we put it when it gets visited for that level
        vector<string> currLevel;

        while(!q.empty())
        {
           int sz = q.size();
           int flag=0; 
            while(sz--)
            {
               vector<string> path = q.front();
               if(path.back()==endWord)
               {
                   res.push_back(path);
                   flag=1;
               }
               string word = path.back();
               q.pop();
               //finding its neighbors
               for(int i=0;i<word.length();i++)
               {   
                   char k = word[i];
                   //replace each letter in the word with all 26 letters one by one
                   for(int j=0;j<26;j++)
                   {
                       word[i] = 'a'+j;
                       if(words.find(word)!=words.end())
                       {
                           currLevel.push_back(word);
                           path.push_back(word);
                            q.push(path);
                           path.pop_back(); 
                       } 
                   }
                   word[i]=k;
               }
            }
            // adding all the visited nodes of current level in the visited array
          for(auto x:currLevel)
              words.erase(x);
            currLevel.clear();  
          if(flag)
            break;
        }
       return res;  
    }
};
  ```
</div>
