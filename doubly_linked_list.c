#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
void traversal(struct node *head);
struct node *insert_end(struct node *head, int data);
struct node *insert_beg(struct node *head, int data);
struct node *delete_beg(struct node *head);
struct node *delete_end(struct node *head);
struct node *insert_index(struct node *head, int index, int data);
struct node *delete_index(struct node *head, int index);
void bubbleSort(struct node *head, int n);
void reversal(struct node *head);
int main() {
  struct node *head;
  struct node *second;
  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  head->data = 4;
  head->prev = NULL;
  head->next = second;
  second->data = 5;
  second->prev = head;
  second->next = NULL;
  int choice;
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at"
               " starting\n");
        printf("\t3  For insertion at"
               " end\n");
        printf("\t4  For insertion at "
               "any position\n");
        printf("\t5  For deletion of "
               "first element\n");
        printf("\t6  For deletion of "
               "last element\n");
        printf("\t7  For deletion of "
               "element at any position\n");
        printf("\t8 To sort element\n");
        printf("\t9 To reverse the "
               "linked list\n");
       
    while (1) {
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            traversal(head);
            break;
        case 2:
            head = insert_beg(head, 20);
            printf("\nInserting at beginning\n");
            traversal(head);
            break;
        case 3:
             printf("\nInserting at end\n");
             head = insert_end(head, 12);
             traversal(head);
            break;
        case 4:
            printf("\nInserting at Index given\n");
            head = insert_index(head, 2, 10);
            traversal(head);
            break;
        case 5:
            printf("\nDeleting at first\n");
            head = delete_beg(head);
            traversal(head);
            break;
        case 6:
             printf("\nDeleting at last\n");
             head = delete_end(head);
             traversal(head);
            break;
        case 7:
             head = delete_index(head, 2);
             printf("\nDeleting at index given\n");
             traversal(head);
            break;
        case 8:
          bubbleSort(head, 2);
          printf("sorted linked list\n");
          traversal(head);
            break;
        case 9:
           printf("\n");
           printf("\nReversal of linked list\n");
           reversal(head);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }

  return 0;
}
void traversal(struct node *ptr) {
  while (ptr != NULL) {
    printf("Element :%d ", ptr->data);
    ptr = ptr->next;
  }
}
struct node *insert_end(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->data = data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->prev = p;
  ptr->next = NULL;
  return (head);
}
struct node *insert_beg(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));

  ptr->next = head;
  ptr->prev = NULL;
  ptr->data = data;
  head = ptr;
  return head;
}
struct node *delete_beg(struct node *head) {
  struct node *ptr = head;
  head = head->next;
  head->prev = NULL;
  free(ptr);
  return head;
}
struct node *delete_end(struct node *head) {
  struct node *ptr = head;
  struct node *p = head->next;
  while (p->next != NULL) {
    p = p->next;
    ptr = ptr->next;
  }
  ptr->next = NULL;
  ptr->prev = p;
  free(p);
  return head;
}
struct node *insert_index(struct node *head, int index, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  ptr->prev = p;
  return head;
}
struct node *delete_index(struct node *head, int index) {
  struct node *p = head;
  struct node *q = head->next;
  for (int i = 0; i < index - 1; i++) {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  p = q->next->prev;
  free(q);
  return head;
}

void reversal(struct node *head) {
  struct node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  do {
    printf("%d ", ptr->data);
    ptr = ptr->prev;
  } while (ptr != NULL);
}
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(struct node *head, int n) {
  struct node *ptr = head;
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (ptr->data > ptr->next->data)
        swap(&ptr->data, &ptr->next->data);
}