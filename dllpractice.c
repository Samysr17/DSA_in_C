#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
struct node *prev;
};
void traversal(struct node *head);
void reverse(struct node *head);
struct node *insert_beg(struct node *head,int data);
struct node *insert_end(struct node *head,int data);
struct node *insert_index(struct node *head,int index,int data);
struct node *delete_beg(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_index(struct node *head,int index);
int main(){
  struct node * head;
  struct node *second;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    head->data=2;
    head->next=second;
    head->prev=NULL;
    second->data=4;
    second->next=NULL;
    second->prev=head;
  head=insert_beg(head,8);
  head=insert_end(head,8);
  head=insert_index(head,2,8);
  // head=delete_beg(head);
  // head=delete_end(head);
 head=delete_index(head,3);
  traversal(head);
  printf("\n");
  reverse(head);
  return 0;
}
void traversal(struct node *head){
  struct node *ptr=head;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}
void reverse(struct node *head){
    struct node *ptr=head;
    while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  do{
    printf("%d ",ptr->data);
    ptr=ptr->prev;
  }while(ptr!=NULL);
}
struct node *insert_beg(struct node *head,int data){
   struct node *ptr;
   ptr=(struct node *)malloc(sizeof(struct node));
   ptr->prev=NULL;
   ptr->next=head;
   head->prev=ptr;
   ptr->data=data;
   head=ptr;
  return head;
}
struct node *insert_end(struct node *head,int data){
   struct node *ptr;
   struct node *p=head;
   ptr=(struct node *)malloc(sizeof(struct node));
   while(p->next!=NULL){
     p=p->next;
   }
   ptr->data=data;
   p->next=ptr;
   ptr->next=NULL;
   ptr->prev=p;
  return head;
}
struct node *insert_index(struct node *head,int index,int data){
     struct node *ptr;
   struct node *p=head;
   ptr=(struct node *)malloc(sizeof(struct node));
  for(int i=0;i<index-1;i++){
    p=p->next;
  }
  ptr->data=data;
  p->next->prev=ptr;
  ptr->next=p->next;
  p->next=ptr;
  ptr->prev=p;
  return head;
}
struct node *delete_beg(struct node *head){
  struct node *ptr=head;
  head=head->next;
  free(ptr);
  head->prev=NULL;
  return head;
}
struct node *delete_end(struct node *head){
  struct node *ptr=head;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->prev->next=NULL;
  free(ptr);
  return head;
}
struct node *delete_index(struct node *head,int index){
  struct node *ptr=head;
  for(int i=0;i<index-1;i++){
    ptr=ptr->next;
  }
  ptr->prev->next=ptr->next;
  ptr->next->prev=ptr->prev;
  free(ptr);
  return head;
}