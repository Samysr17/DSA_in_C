#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node * next;
};
void traversal(struct node * head);
struct node *insert_beg(struct node *head,int data);
struct node *insert_end(struct node *head,int data);
struct node *insert_index(struct node *head,int index,int data);
struct node *delete_beg(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_index(struct node *head,int index);
struct node *reverse(struct node *head);
int main(){
  struct node *head;
  struct node *second;
  head=(struct node *)malloc(sizeof(struct node));
  second=(struct node *)malloc(sizeof(struct node));
  head->next=second;
  head->data=2;
  second->data=3;
  second->next=NULL;
  head=insert_beg(head,4);
  head=insert_end(head,4);
  head=insert_index(head,2,6);
  // head=delete_beg(head);
  // head=delete_end(head);
  // head=delete_index(head,2);
  traversal(head);
  printf("\n");
  head=reverse(head);
  traversal(head);
  return 0;
}
void traversal(struct node * head){
  struct node *ptr=head;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}
struct node *insert_beg(struct node *head,int data){
  struct node *ptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=data;
  ptr->next=head;
  head=ptr;
  return head;
}
struct node *insert_end(struct node *head,int data){
  struct node *ptr=head;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  p->data=data;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=p;
  p->next=NULL;
  return head;
}
struct node *insert_index(struct node *head,int index,int data){
  struct node *ptr=head;
  struct node *p;
  p=(struct node *)malloc(sizeof(struct node));
  p->data=data;
  for(int i=0;i<index-1;i++){
    ptr=ptr->next;
  }
  p->next=ptr->next;
  ptr->next=p;
  return head;
}
struct node *delete_beg(struct node *head){
  struct node *ptr=head;
  head=head->next;
  free(ptr);
  return head;
}
struct node *delete_end(struct node *head){
  struct node *ptr=head;
  struct node *p=head->next;
  while(p->next!=NULL){
    ptr=ptr->next;
    p=p->next;
  }
  free(p);
  ptr->next=NULL;
  return head;
}
struct node *delete_index(struct node *head,int index){
  struct node *ptr=head;
  struct node *p=head->next;
  for(int i=0;i<index-1;i++){
    ptr=ptr->next;
    p=p->next;
  }
  ptr->next=p->next;
  free(p);
  return(head);
}
struct node *reverse(struct node *head){
  struct node *prev=NULL;
  struct node *next=head;
  struct node *current=head;
  while(next!=NULL){
    next=next->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;
  return head;
}
