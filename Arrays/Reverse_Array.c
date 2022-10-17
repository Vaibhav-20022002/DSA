#include<stdio.h>
void reverse(int arr[],int n){
    int temp;
    for(int i=0;i<n/2;++i){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
}
int main(void){
    int arr[]={4,5,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    for(int i=0;i<n;++i)
        printf("%d ",arr[i]);
    reverse(arr,n);
    printf("\nREVERSED ARRAY: ");
    for(int i=0;i<n;++i)
        printf("%d ",arr[i]);
    return 0;
}