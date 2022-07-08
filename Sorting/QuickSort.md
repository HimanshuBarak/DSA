//
// Created by himan on 11/12/2021.
//

``` c++
#include<bits/stdc++.h>

using namespace std;
//finding the position of the first element in the range low to high
int partiton(int a[],int low,int high) {

    int pivot = a[low];
    int i = low +1;
    int j = high;
    while(true) {

        while (a[i] <= pivot && i <= j)
            i++;
        while (a[j] >= pivot &&j>=i)
            j--;
        if (j < i)
            break;
        else
        swap(a[i], a[j]);
    }

        swap(a[low], a[j]);
    return j;
}

void QuickSort(int a[],int low,int high)
{
    //sorting the pivot element

    if(low<high){ //stopping condition of recusrive function
        int j= partiton(a,low,high);
        QuickSort(a,low,j-1);
        QuickSort(a,j+1,high);
    }
    //apply it on the left half



}
//Algorithm
// For every element we find its correct position(the position that the element is going to take inthe sorted array)
// the selected element whose position we find is called pivot
// for pivot = first element, for an already sorted array time will be o(n)^2
// average and best case will  nlogn reason

int main(){

    int a[] = {50,7,60,90,430,80,10,20,30};
    int n=9;
    QuickSort(a,0,8);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

    return 0;
}

```


