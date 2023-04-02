#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void traversal(struct node *ptr);
int insert_first(struct node *head,int data);
int insert_index(struct node *head,int data,int index);
int insert_end(struct node*head,int data);
int insert_after_node(struct node*head,struct node*prev_node,int data);
int delete_first(struct node *head);
int delete_index(struct node*head,int index);
int delete_last(struct node *head);
int delete_value(struct node *head,int value);
void search(struct node *head);
int reverse(struct node *head);
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->link=second;
    second->data=8;
    second->link=third;
    third->data=9;
    third->link=NULL;
    traversal(head);
    head=insert_index(head,10,1);
    printf("After Insertion at index\n");
    traversal(head);
    printf("After Insertion at front\n");
    head=insert_first(head,12);
    traversal(head);
    printf("After Insertion at end\n");
    head=insert_end(head,22);
    traversal(head);
    printf("Insertion after node\n");
    head=insert_after_node(head,third,99);
    traversal(head);
    head=delete_first(head);
    printf("Deletion of the first element in the linked list\n");
    traversal(head);
    head=delete_index(head,1);
    printf("Deletion of the indexed element in the linked list\n");
    traversal(head);
    head=delete_last(head);
    printf("Deletion of the last element in the linked list\n");
    traversal(head);
    head=delete_value(head,12);
    printf("Deletion of the indexed element in the linked list\n");
    traversal(head);
    search(head);
    reverse(head);
    traversal(head);
    
    return 0;
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
int insert_first(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->link=head;
    ptr->data=data;
    ptr=head;
    return(head);
}
int insert_index(struct node *head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->link;
        i++;
    }
    ptr->data=data;
    ptr->link=p->link;
    p->link=ptr;
    return head;
    
}
int insert_end(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    ptr->data=data;
    while(p->link!=NULL){
       p=p->link;
    }
    p->link=ptr;
    ptr->link=NULL;
    return head;
}
int insert_after_node(struct node*head,struct node*prev_node,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=prev_node->link;
    prev_node->link=ptr;
    return head;
}
int delete_first(struct node *head){
    struct node*ptr=head;
    head=head->link;
    free(ptr);
    return head;
}
int delete_index(struct node*head,int index){
    struct node*p=head;
    struct node *q=head->link;
    for(int i=0;i<index-1;i++){
        p=p->link;
        q=q->link;
    }
    p->link=q->link;
    free(q);
    return head;
}
int delete_last(struct node *head){
    struct node*p=head;
    struct node*q=head->link;
    while(q->link!=NULL){
        p=p->link;
        q=q->link;
    }
    p->link=NULL;
    free(q);
    return head;
}
int delete_value(struct node *head,int value){
    struct node*p=head;
    struct node *q=head->link;
    while(q->data!=value && q->link!=NULL){
        p=p->link;
        q=q->link;
    }
    if(q->data==value){
        p->link=q->link;
        free(q);
        
    }
    return head;

}
void search(struct node *head){
    struct node *p=head;
    struct node *q=head->link;
    int value;
    printf("Enter the value u want to search in the linked list\n");
    scanf("%d\n",&value);
    while(q->link!=NULL)
    if(q->data==value){
        printf("Data found in the linked list\n");
    }else{
        printf("Data not found\n");
    }

}
int reverse(struct node *head){
    struct node*prev_node,*current_node,*next_node;
      prev_node=0;
      current_node=head;
      next_node=head;
    while(next_node!=0){
     next_node=next_node->link;
     current_node->link=prev_node;
     prev_node=current_node;
     current_node=next_node;
    }
    return head;
}