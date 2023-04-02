#include<stdio.h>
void selection_sort(int a[],int n);
void display(int a[],int n);
int main(){
  int a[]={3,4,1,2,5};
    int n=5;
    printf("Unsorted Array\n");
  display(a,n);
  selection_sort(a,n);
  printf("Sorted Array\n");
  display(a,n);

  return 0;
}
void selection_sort(int a[],int n){
  int i,j,minimum_index,temp;
  for(int i=0;i<n-1;i++){
    minimum_index=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[minimum_index])
        minimum_index=j;
      }
     if(a[i]!=minimum_index){
        temp=a[minimum_index];
        a[minimum_index]=a[i];
        a[i]=temp;
    }
  }
}
void display(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
}