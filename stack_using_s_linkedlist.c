#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void traversal(struct node *ptr);
struct node* push(struct node *head, int data);
struct node* pop(struct node *head);
struct node* peek(struct node *head);
int main(){
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    traversal(head);
    head=push(head,6);
    traversal(head);
    return 0;
}
void traversal(struct node *ptr) {
 while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
   }
}
struct node* push(struct node *head, int data) {
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    ptr=head;
    return(head);
}
struct node* pop(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    int data;
    data=ptr->data;
    return(head);
}
struct node* peek(struct node *head){
    struct node *ptr=head;
    head=head->next;
    int data_1;
    data_1=ptr->data;
    return(data_1);
}