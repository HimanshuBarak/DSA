<h2>Anti Palindrome (code :ANTI_PAL) </h2>
<h3>Easy</h3><hr>
<div><p>A (1-indexed) string S of length N is said to be anti-palindrome if, for each 1≤i≤N, Si≠S(N+1−i).

You are given a string S of length N (consisting of lowercase Latin letters only). Rearrange the string to convert it into an anti-palindrome or determine that there is no rearrangement which is an anti-palindrome.

If there are multiple rearrangements of the string which are anti-palindromic, print any of them.
</p>


  <p>  <strong> Input Format </strong> </p>
  1.The first line of input contains a single integer T — the number of test cases. The description of T test cases follows.
  
  2.The first line of each test case contains an integer N — the length of the string S.
  
  3.The second line of each test case contains the string S
  <p><strong> Output Format </strong></p>
 For each test case, if it is possible to rearrange S to convert it into an anti-palindrome, print YES in the first line and print the rearranged string in the second line. Otherwise, print NO.
  
  You may print each character of YES and NO in uppercase or lowercase (for e.g. yes, yEs, Yes will be considered identical).

If there are multiple rearrangements of the string which are anti-palindromic, print any of them.
<p>&nbsp;</p>
<p><strong>Input 1:</strong></p>

  ```
4
3
abc
8
abccccdd
4
xyyx
6
ppppqr

 ```     
 

<strong>Output 1:</strong> 
  ```
NO
YES
abddcccc
YES
xxyy
NO

  ```
<

<strong>Explanation:</strong> 
  Test case 1: No matter how the string is rearranged, the condition Si≠S(N+1−i) will not be satisfied for i=2.

Test case 2: One possible rearrangement of the string which is anti-palindromic is abddcccc. Other answers, such as ccdaccdb, will also be accepted.

Test case 3: One possible rearrangement of the string which is anti-palindromic is xxyy.

Test case 4: It can be shown that none of the rearrangements of A is anti-palindromic.
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>


  
  <h2> Solution </h2>
  
  ``` c++ 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t,n;
	string s;
	cin>>t;
	
	while(t--)
	{
	    cin>>n;
	    cin>>s;
	    
	    if(n%2)
	     cout<<"NO"<<endl;
	    else{
	     bool   flag=false;
	        sort(s.begin(),s.end());
	        int x=n-1;
	        int i=n/2;
	        //reversing the 2nd half of the string
	        while(i<x)
	          {
	             char t=s[x];
	              s[x]=s[i];
	              s[i]=t;
	              x--;
	              i++;
	          }
	        string k = s;
	        reverse(k.begin(),k.end());
	        for(int i=0;i<n;i++)
	        {
	            if(k[i]==s[i])
	             {
	                 flag=true;
	                 break;
	             }
	        }
	        if(flag)
	         cout<<"NO"<<endl;
	         else{
	             cout<<"YES"<<endl;
	             cout<<s<<endl;
	         }
	          
	    } 
	   
	    
	    
	}
	
	return 0;
}

  ```
</div>
