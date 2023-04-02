#include<stdio.h>
int linear_search(int a[],int size,int element);
int main(){
    int a[]={1,4,2,11,6,8,9,11};
    int size=8;
    int element=11;
    int search_index=linear_search(a,size,element);
    printf("The requred element %d is found at %d th position",element,search_index+1);
    return 0;
}
int linear_search(int a[],int size,int element){
    for(int i=0;i<size;i++){
        if(a[i]==element){
            return i;
        }
       
    }
  return -999;
}