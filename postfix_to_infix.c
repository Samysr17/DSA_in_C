#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
 int size;
 int top;
 char *data;
 int *arr;
};
int isFull(struct stack *s);
char stacktop(struct stack *s);
int isEmpty(struct stack *s);
void push(struct stack *s,char character);
char pop(struct stack *s);
void push1(struct stack *s,int ch);
int pop1(struct stack *s);
int isOperator(char ch);
int precendence(char ch);
char *infixToPost(char *infix);
int eval(char ch,int a,int b);
int conversion(char ch);
int evaluation(char *postfix);
int main(){
 char *infix = "1+2-4/8*9";
 printf("Original Expression is %s\n",infix);
 char *postfix;
 postfix = infixToPost(infix);
 printf("Postfix Expression is %s\n",postfix);
 int result = evaluation(postfix);
 printf("Ans of postfix : %d\n",result);
 return 0;
}
int isFull(struct stack *s){
 if(s->top==(s->size)-1){
 return 1;
 }
 return 0;
}
char stacktop(struct stack *s){
 return s->data[s->top];
}
int isEmpty(struct stack *s){
 if(s->top==-1){
 return 1;
 }
 return 0;
}
void push(struct stack *s,char character){
 if(isFull(s)){
 printf("Stack is full\n");
 }
 else{
 s->top=s->top+1;
 s->data[s->top]=character;
 }
}
char pop(struct stack *s){
 if(isEmpty(s)){
 printf("Stack empty\n");
 }
 else{
 char val = s->data[s->top];
 s->top=s->top-1;
 return val;
 }
}
void push1(struct stack *s,int ch){
 if(isFull(s)){
 printf("Stack is full\n");
 }
 else{
 s->top=s->top+1;
 s->arr[s->top]=ch;
 }
}
int pop1(struct stack *s){
 if(isEmpty(s)){
 printf("Stack empty\n");
 }
 else{
 int val = s->arr[s->top];
 s->top=s->top-1;
 return val;
 }
}
int isOperator(char ch){
 if(ch=='/' || ch=='+' || ch=='-' || ch=='*'){
 return 1;
 }
 return 0;
}
int precendence(char ch){
 if(ch=='/' || ch=='*'){
 return 2;
 }
 else if(ch=='+' || ch=='-'){
 return 1;
 }
 return 0;
}
char *infixToPost(char *infix){
 struct stack *p = (struct stack *)malloc(sizeof(struct stack));
 p->size = strlen(infix);
 p->top = -1;
 p->data = (char *)malloc(p->size*sizeof(char));
 char *postfix = (char *)malloc((p->size+1)*sizeof(char));
 int i = 0;
 int j = 0;
 while(infix[i]!='\0'){
 if(!isOperator(infix[i])){
 postfix[j]=infix[i];
 i++;
 j++;
 }
 else{
 if(precendence(infix[i])>precendence(stacktop(p))){
 push(p,infix[i]);
 i++;
 }
 else{
 postfix[j] = pop(p);
 j++;
 }
 }
 }
 while(!isEmpty(p)){
 postfix[j]=pop(p);
 j++;
 }
 postfix[j]='\0';
 return postfix;
}
int eval(char ch,int a,int b){
 int ans;
 switch (ch)
 {
 case '+':
 ans = a+b;
 break;
 case '-':
 ans = a-b;
 break;
 case '*':
 ans = a*b;
 break;
 case '/':
 ans = a/b;
 break;
 default:
 break;
 }
 return ans;
}
int conversion(char ch){
 int a = (int)ch - 48;
 return a;
}
int evaluation(char *postfix){
 struct stack *op = (struct stack *)malloc(sizeof(struct stack));
 op->size = strlen(postfix);
 op->top=-1;
 op->arr = (int *)malloc(op->size*sizeof(int));
 int i=0; // Traversing postfix expression
 while( postfix[i]!='\0'){
 if(!isOperator(postfix[i])){
 push1(op,(int)postfix[i]);
 i++;
 }
 else{
 int a = conversion(pop1(op));
 int b = conversion(pop1(op));
 int c = perform(postfix[i],b,a);
 push1(op,c);
 i++;
 }
 }
 int ans = (pop1(op));
 return (ans+48);
}
