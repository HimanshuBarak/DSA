<h3>Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K. </h3>

[Problem Link](https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1)

Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}

Output: 2

Explanation: 

arr[0] + arr[1] = 1 + 5 = 6 

and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:

N = 4, X = 2

arr[] = {1, 1, 1, 1}
Output: 6

Explanation: 

Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105

1 <= K <= 108

1 <= Arr[i] <= 106




//////////////////// Code ///////////////////////////
``` c++
 int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> umap;
        int count=0;
        //adding values to the hashmap
        for(int i=0;i<n;i++)
        {   
            
            if(umap.find(k-arr[i])!=umap.end())
            {
                count+=umap[k-arr[i]];
            }
  /*          if(umap.find(arr[i])!=umap.end())
            {
                umap[arr[i]]+=1;
            }
            else
             umap.insert({arr[i],1});  */
            
            umap[arr[i]]++;  //this line of code is equivalent to the above commented out code
        }   
        
        
        return count;
    }

 ```
