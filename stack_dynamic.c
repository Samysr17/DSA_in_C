#include<stdio.h>
#include<stdlib.h>
struct stack{
   int size;
   int top;
   int *a;
};
void initialise(struct stack*s1);
void create(struct stack*s1);
void push(struct stack*s1,int element);//this fn has the condn for reallocation in case full
void status(struct stack*s1);
int main(){
    struct stack s1;
    initialise(&s1);
    create(&s1);
    push(&s1,4);
    push(&s1,3);
    status(&s1);
    push(&s1,5);
    status(&s1);
    push(&s1,6);
    status(&s1);
    return 0;
}
void initialise(struct stack*s1){
    s1->top=-1;
}
void create(struct stack*s1){
    printf("Enter the size of stack\n");
    scanf("%d",&s1->size);
    s1->a=(int*)malloc(s1->size*sizeof(int));
}
void push(struct stack*s1,int element){
    
    if(s1->top==s1->size-1){
      int new_size=1.5*s1->size;
      s1->a=(int*)realloc(s1->a,new_size*sizeof(int));
      printf("\nStack overflowed so size increased by 1.5times\n");

    }
    s1->top=s1->top+1;
   s1->a[s1->top]=element;
}
void status(struct stack*s1){
    for(int i=s1->top;i>=0;i--){
        printf("%d  ",s1->a[i]);
    }printf("\n");
}
