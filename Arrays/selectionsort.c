/*The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning. 
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted
subarray is picked and moved to the sorted subarray.*/
#include<stdio.h>
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[i]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
int main(void){
    int arr[]={7,8,9,5,52,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
}