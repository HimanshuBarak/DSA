``` c++

// this is not binary seach simple version it is some sort of binary search related question's answer
int search(vector<int>& nums, int t) {

        int res=-1,mid=-1;

        int start=0,end=nums.size()-1;

        while(start<=end){

            mid =start+(end-start)/2;

            if(nums[mid]==t){
                res =mid;
                break;
            }
            if(nums[mid]>=nums[start])
            {
                if(t>=nums[start] && t<nums[mid])
                    end=mid-1;

                else
                    start=mid+1;

            }

            else if(nums[mid]<nums[start])
            {
                if(t<=nums[end] && t>nums[mid])
                    start=mid+1;
                else
                    end=mid-1;

            }
        }
        return res;
    }
```
