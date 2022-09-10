<h2>Number of Weak Characters in a Game</h2>
<h3>Medium</h3><hr>
<div><p>
 You are playing a game that contains multiple characters, and each of the characters has two main properties: attack and defense. You are given a 2D integer array properties where properties[i] = [attacki, defensei] represents the properties of the ith character in the game.

A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

Return the number of weak characters. 

 
</p>


[Problem Link](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)

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
<strong>Time:</strong> O(Nlog(N))
  
<strong>Space:</strong> O(1)
  <h2> Algorithm </h2>
 <pre>
  1. Sort according to the decreasing order of attack
  2. For same values of attacj sort as per increasing order of defence
  3. Traverse the sorted array will maintaing the highest defence observed till now
  4. If less than highest defence add to ans else update highest defence value
  </pre>
  <h2> Solution </h2>
  
  ``` c++ 
class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0]) //if attack value is not same sort decreasing order of attack
            return a[0]>b[0];
        else     
          return   a[1]<b[1]; //increasing order of defence
    }
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(),props.end(),comp);
        int cnt=0;
        int maxDef=props[0][1];
        for(int i=1;i<props.size();i++)
        {
            if(props[i][1]<maxDef)
                cnt++;
            maxDef=max(maxDef,props[i][1]);
        }
        
        return cnt;
    }
};

  ```
</div>
