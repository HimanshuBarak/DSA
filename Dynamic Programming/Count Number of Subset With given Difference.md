<h1> Count Number of Subset with given Difference </h1>


<strong>
Let sum of subset 1 be s1 and subset 2 with s2
  
s1 - s2 = diff (given)
  
s1 + s2=sum of array (logical)
  
Therefore adding both eq we get :
  
2s1= diff + sum of array
  
s1= (diff + sum of array)/2;
  
Problem reduces to find no of subsets with given sum** 
</strong>


<h2> Code </h2>

``` c++
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
            else
                  dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int countWithGivenSum(int arr[ ], int n, int diff)
{   
     int sum=0;
    for(int i=0;i<n;i++)
         sum+=nums[i]
	 
	 int reqSum=(diff+sum)/2;
	 return subsetSum(arr,n,reqSum);
}
```
