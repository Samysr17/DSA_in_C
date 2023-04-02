#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};
void traversal(struct node *head);
struct node* insert_first(struct node *head, int data);
struct node* insert_end(struct node *head, int data);
struct node* insert_index(struct node *head, int index, int data);
struct node* delete_first(struct node *head);
struct node* delete_last(struct node * head);
int main() {
  struct node *head;
  struct node *second;
  struct node *third;
  struct node *fourth;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  fourth = (struct node *)malloc(sizeof(struct node));

  head->data = 2;
  head->next = second;

  second->data = 4;
  second->next = third;

  third->data = 6;
  third->next = fourth;

  fourth->data = 8;
  fourth->next = head;
  traversal(head);
  printf("Created Linked list\n");
  head = insert_first(head, 20);
  printf("Inserting first\n");
  traversal(head);
  head = insert_end(head, 12);
  printf("Inserting last\n");
  traversal(head);
  head = insert_index(head, 1, 13);
  printf("Inserting at specefic index\n");
  traversal(head);
  head= delete_last(head);
  printf("Deleting last\n");
  traversal(head);
  return 0;
}
void traversal(struct node *head) {
  struct node *ptr = head;
  do {
    printf("Element : %d\n", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
}
struct node* insert_first(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *p = head->next;
  while (p->next != head) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = head;
  head = ptr;
  return (head);
}
struct node* insert_end(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *p = head->next;
  while (p->next != head) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = head;
  return (head);
}
struct node* insert_index(struct node *head, int index, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  struct node *p = head->next;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->next = p->next;
  p->next = ptr;
  return (head);
}
struct node* delete_first(struct node *head){
   struct node *ptr=head;
    struct node *p=head->next;
    head=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=head->next;
    free(ptr);

    return head;
}
struct node* delete_last(struct node * head){
    struct node *ptr=head;
    struct node *p=head->next;
    while(p->next!=head){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=head;
    free(p);
    return(head);

}