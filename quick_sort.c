#include<stdio.h>
void display(int *a,int n);
int partition(int a[],int low,int high);
void quick_sort(int a[],int low,int high);
int main(){
  int a[]={2,34,45,12,1,34,77};
  int n=7;
  display(a,n);
  quick_sort(a,0,n-1);
  display(a,n);
  return 0;
}
void display(int *a,int n){
  for(int i=0;i<n;i++){
    printf("\n%d\n",a[i]);
  }
}
int partition(int a[],int low,int high){
  int i=low+1;
  int j=high;
  int pivot=a[low];
  int temp;
  do{
  while(a[i]<pivot){
    i++;
  }
  while(a[j]>=pivot){
    j--;
  }if(i<j){
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
  }}while(i<j);
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;
   return j;
}
void quick_sort(int a[],int low,int high){
  int partition_index;
  if(low<high){
    partition_index=partition(a,low,high);
    quick_sort(a,low,partition_index-1);
    quick_sort(a,partition_index+1,high);
  }
}