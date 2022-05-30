<h2>Word Ladder</h2>
<h3>Hard</h3><hr>
<div><p> A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
</p>




<p>&nbsp;</p>
<p><strong>Example 1:</strong></p> 

      
 
<pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>  beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
     
<strong>Output:</strong> 0
<strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
1 <= s.length, p.length <= 3 * 104

  <h2> Algorithm </h2>
 <pre>
   Store the wordlist in a unordered set
   this is a graph where neigbours of a node are the words which have one character different. draw the graph and you will understand the approach
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordlist) {
        unordered_set<string> wl(wordlist.begin(),wordlist.end());
        
        queue<string> q;
        
        if(wl.find(ew)==wl.end())
            return 0;
        q.push(bw);
        int ladder=1;
        
        while(!q.empty())
        {  
            //this is a beautiful question 
            string word;
            int n =q.size();
            for(int i=0;i<n;i++){
                word = q.front();
                 q.pop(); 
                  if(word==ew)
                return ladder;
                wl.erase(word);  
                
                //check for this word's immediate neighbour
                for(int j=0;j<word.length();j++)
                {
                    char c =word[j];
                    for(int k=0;k<26;k++)
                    {
                        word[j]='a'+k;
                        if(wl.find(word)!=wl.end())
                        {
                            q.push(word);
                        }
                    }
                    word[j]=c;
                }
            }
            
           //one set of neigbours visited in each iteration of the queue elements
            ladder++;      
    }
                  
        return 0;
    }
};
  ```
</div>
