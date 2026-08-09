#include<stdio.h>
int main(){
    int n;
    printf("enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements in the array in sorted:");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key,pos;
    printf("enter the element to find:");
    scanf("%d",&key);
    int low=0,mid,high=n-1;
    for(i=0;i<n;i++){
        mid=(low+high)/2;
        if(key==arr[mid]){
            pos=mid+1;
            printf("entered element is found at %d",pos);
            break;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

        
    }
    return 0;
}