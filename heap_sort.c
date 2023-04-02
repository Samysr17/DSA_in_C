#include<stdio.h>
void heapify(int a[],int n,int i);
void heap_sort(int a[],int n);
void display(int a[],int n);
void heapify(int a[],int n,int i){
    int largest=i;
    int temp;
    int left=2*i;
    int right=2*i+2;
    while(left<=n && a[left]>a[largest] ){
        largest=left;
    }
    while(right <=n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,i);   }
}
void heap_sort(int a[],int n){
    int temp_1;
    for(int i=(n/2);i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n;i>=0;i--){
        temp_1=a[0];
        a[0]=a[i];
        a[i]=temp_1;
        heapify(a,n,0);
    }
    
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}
