
```c++
Kadane 's  Algorithm

    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int sum =INT_MIN;
        int temp=0;
        
        for(int i=0;i<n;i++)
        {
            temp+=arr[i];
            if(sum <temp)
             sum =temp;
             //if sum is below zero start again from the begining
            if(temp<0)
              temp=0;
        }
        
       return sum;
    }
```
