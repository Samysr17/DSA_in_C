#include<stdio.h>
#define CAPACITY 10
void initialisation(int a[],int *last_index);
void add(int a[],int *last_index,int n);
void create(int a[],int *last_index,int n);
void display(int a[],int*last_index);
void length(int a[],int *last_index);
int main(){
    int a[CAPACITY],last_index,n;
    initialisation(a,&last_index);
    create(a,&last_index,n);
    display(a,&last_index);
    length(a,&last_index);

    return 0;
}
void initialisation(int a[],int *last_index){
    *last_index=-1;
}
void add(int a[],int *last_index,int n){
    if(*last_index+1<CAPACITY){
        *last_index=*last_index+1;
        a[*last_index]=n;
    }else{
        printf("Array is full\n");
    }
}
void create(int a[],int *last_index,int n){
    printf("Enter the elements and type -999 to end the process\n");
    do{
        scanf("%d",&n);
        if(n==-999){
          break;
        }
        add(a,last_index,n);
    }while(*last_index<CAPACITY);

}
void display(int a[],int *last_index){
    for(int i=0;i<*last_index+1;i++){
        printf("%d\n",a[i]);
    }
}
void length(int a[],int *last_index){
    printf("The length of the array is %d\n",*last_index+1);
}
