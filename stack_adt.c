#include<stdio.h>
#include<stdlib.h>
struct stack{
  int top;
  int *a[];
};
void initialize(struct stack*s1);
void push(struct stack*s1,int value);
int pop(struct stack*s1);
void peek(struct stack *s1);



int main(){
    struct stack*s1=(struct stack*)malloc(sizeof(int));
    initialize(&s1);
    s1->a==(int*)malloc(10*sizeof(int));
    push(s1,1);
    push(s1,2);
    push(s1,3);
    printf("Popped %d from the stack\n", pop(s1));
    peek(s1);

    return 0;
}



void initialize(struct stack*s1){
    s1->top=-1;
}
void push(struct stack*s1,int value){
    if(s1->top==9){
        printf("Stack is full\n");
    }else{
        s1->top=s1->top+1;
        s1->a[s1->top]=value;
    }
}
int pop(struct stack*s1){
    int value;
    if(s1->top==-1){
        printf("Stack is empty\n");

    }else{
        value=s1->a[s1->top];
        s1->top=s1->top=-1;
    }
    return value;
}
void peek(struct stack *s1){
    int value;
    value=s1->a[s1->top];
    printf("Element peeked %d\n",value);
}