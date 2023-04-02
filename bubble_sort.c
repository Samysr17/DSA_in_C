#include<stdio.h>
void bubble_sort(int a[],int n);
void display(int a[],int n);
int main(){
    int a[]={3,2,4,1,5};
    int n=5;
    printf("Unsorted Array\n");
    display(a,n);
    bubble_sort(a,n);
    printf("Sorted Array\n");
    display(a,n);


    return 0;
}
void bubble_sort(int a[],int n){
    int i,j,temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
        }
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}