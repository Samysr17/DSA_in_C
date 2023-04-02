#include<stdio.h>
void display(int *a,int n);
void merge(int a[],int low,int mid,int high);
void merge_sort(int a[],int low,int high);
int main(){
  int a[]={5,4,3,2,1};
  int n=5;
  printf("Unsorted array\n");
  display(a,n);
  merge_sort(a,0,n-1);
  printf("Sorted Array\n");
  display(a,n);
  return 0;
}
void display(int *a,int n){
  for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
}
void merge(int a[],int low,int mid,int high){
  int i,j,k,b[10];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid && j<=high){
  if(a[i]<a[j]){
    b[k]=a[i];
    i++;
    k++;
  }else{
    b[k]=a[j];
    j++;
    k++;
  }
    }
  while(i<=mid){
    b[k]=a[i];
    k++;
    i++;
  }
  while(j<=mid){
    b[k]=a[j];
    k++;
    j++;
  }
  for(int x=low;x<=high;x++){
    a[x]=b[x];
  }
}
void merge_sort(int a[],int low,int high){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}