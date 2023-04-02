#include<stdio.h>
#include<stdlib.h>
struct queue{
    int top;
    int rear;
    int *a[];
};
void initialize(struct queue *q);
void enqueue(struct queue*q,int value);
int dequeue(struct queue*q);
int main(){
    struct queue q;
    q.a==(int*)malloc(4*sizeof(int));
    initialize(&q);
    enqueue(&q,10);
    enqueue(&q,11);
    enqueue(&q,12);
     printf("Dequeuing element %d\n", dequeue(&q));
     printf("Dequeuing element %d\n", dequeue(&q));
     printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q,12);
    return 0;
}
void initialize(struct queue *q){
    q->top=-1;
    q->rear=-1;
}
void enqueue(struct queue*q,int value){
if(q->rear==3){
    printf("the queue is full\n");     
            
}else{
    q->rear=q->rear+1;
    q->a[q->rear]=value;
    printf("The enqueued element is %d",value);
    }
}
int dequeue(struct queue*q){
    int a=-1;
 if(q->top==q->rear){
    printf("The queue is empty\n");
 }else{
    q->top=q->top+1;
    a=q->a[q->top];
 }
 return a;
}