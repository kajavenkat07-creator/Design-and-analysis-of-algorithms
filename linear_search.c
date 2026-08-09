#include<stdio.h>
int main(){
    int n;
    printf("enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements in the array:");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key,pos;
    printf("enter the element to find:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(key==arr[i]){
            pos=i+1;
            printf("element is found at %d",pos);
        }
    }
    return 0;
}