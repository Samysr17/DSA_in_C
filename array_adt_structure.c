#include<stdio.h>
#define CAPACITY 10
struct my_array{
    int a[CAPACITY];
    int last_index;
};
void initialisation(struct my_array *a1);
void add(struct my_array *a1,int n);
void create(struct my_array *a1,int n);
void display(struct my_array *a1);
void length(struct my_array *a1);
int main(){
    struct my_array a1;
    int n;
    initialisation(&a1);
    create(&a1,n);
    display(&a1);
    length(&a1);

    return 0;
}
void initialisation(struct my_array *a1){
    a1->last_index=-1;
}
void add(struct my_array *a1,int n){
    if(a1->last_index+1<CAPACITY){
        a1->last_index=a1->last_index+1;
        a1->a[a1->last_index]=n;
    }else{
        printf("Array is full \n");
    }
}
void create(struct my_array *a1,int n){
    printf("Enter the elements and type -999 to end the process\n");
    do{
        scanf("%d",&n);
        if(n==-999){
            break;
        }
        add(a1,n);
    }while(a1->last_index<CAPACITY);
}
void display(struct my_array *a1){
    for(int i=0;i<a1->last_index+1;i++){
      printf("%d\n",a1->a[i]);
    }
}
void length(struct my_array *a1){
    printf("The length of the array is %d\n",a1->last_index+1);
}