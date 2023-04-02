#include<stdio.h>
#define CAPACITY 10
void initialisation();
void enqueue_1(int front_1,int rear_1,int front_2,int rear_2,int a[]);
void enqueue_2(int front_1,int rear_1,int front_2,int rear_2,int a[]);
void dequeue_1(int front_1,int rear_1,int front_2,int rear_2,int a[]);
void dequeue_2(int front_1,int rear_1,int front_2,int rear_2,int a[]);
int main(){
    int front_1;
    int rear_1;
    int front_2;
    int rear_2;
    int a[CAPACITY];
    enqueue_1(front_1,rear_1,front_2,rear_2,a);
    enqueue_2(front_1,rear_1,front_2,rear_2,a);
    return 0;
}
void initialisation(){
    int front_1=-1;
    int rear_1=-1;
    int front_2=CAPACITY;
    int rear_2=CAPACITY;
    int a[CAPACITY];
}
void enqueue_1(int front_1,int rear_1,int front_2,int rear_2,int a[]){
 int element;
 initialisation();
 if(rear_1<rear_2-1){
    printf("Enter the element of q1\n");
    scanf("%d",&element);
    if(front_1==-1)
    front_1=0;
    rear_1++;
    a[rear_1]=element;
 }else{
    printf("queue 1 is overflown\n");
 }
}
void enqueue_2(int front_1,int rear_1,int front_2,int rear_2,int a[]){
int element;
 initialisation();
if(rear_1<rear_2-1){
printf("Enter queue 2 element\n");
scanf("%d",&element);
if(front_2==CAPACITY)
    front_2=CAPACITY-1;
    rear_2--;
    a[rear_2]=element;
}else{
      printf("queue 2 is overflown\n");
}
}
void dequeue_1(int front_1,int rear_1,int front_2,int rear_2,int a[]){
 initialisation();
}
void dequeue_2(int front_1,int rear_1,int front_2,int rear_2,int a[]){
 initialisation();
}
