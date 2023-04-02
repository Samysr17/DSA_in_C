#include<stdio.h>
int binary_search(int a[],int size,int element);
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int size=10;
    int element=8;
    int search_index=binary_search(a,size,element);
    printf("The requred element %d is found at %d th position",element,search_index+1);
    return 0;
}
int binary_search(int a[],int size,int element){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==element){
            return mid;
        }else if(a[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }

    }
    return -999;
}