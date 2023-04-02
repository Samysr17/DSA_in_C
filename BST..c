#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *createnode(int data);
void inorder_traversal(struct node *root);
void insert(struct node *root,int data);
struct node *delete1(struct node *root,int data);
void smallest(struct node *root);
int height(struct node *root);
int leafnodes(struct node *root);
void mirror(struct node *root);
int main(){
  struct node *root=createnode(20);
  struct node*root_1=createnode(10);
  struct node *root_2=createnode(30);
  root->left=root_1;
  root->right=root_2;
  insert(root,40);
  delete1(root,40);
  inorder_traversal(root);
  smallest(root);
  int height1=leafnodes(root);
  printf("\n%d",height1);
  mirror(root);
  printf("\n");
  inorder_traversal(root);
  return 0;
}
struct node *createnode(int data){
  struct node *root=(struct node *)malloc(sizeof(struct node));
  root->data=data;
  root->left=NULL;
  root->right=NULL;
  return root;
}
void inorder_traversal(struct node *root){
  if(root==NULL)return;
  inorder_traversal(root->left);
  printf("%d ",root->data);
  inorder_traversal(root->right);
}
void insert(struct node *root,int data){
  struct node *prev=NULL;
  while(root!=NULL){
    prev=root;
  if(data<root->data){
    root=root->left;
  }else if(data>root->data){
    root=root->right;
  }else printf("\nFerrari\n");
    }
  struct node *new=createnode(data);
  if (prev->data>data){
    prev->left=new;
  }else{
    prev->right=new;
  }
  
}
struct node *inorder_predecessor(struct node *root) {
  root = root->left;
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
  }
struct node *delete1(struct node *root,int data){
  struct node *ipre;
  if(root==NULL)return NULL;
  if(root->left==NULL && root->right==NULL){
    free(root);
    return NULL;
  }
  if(data<root->data)
    root->left=delete1(root->left,data);
  else if(data>root->data)
    root->right=delete1(root->right,data);
  else{
    ipre=inorder_predecessor(root);
    root->data=ipre->data;
    root->left=delete1(root->left,ipre->data); 
  }
  return root;
}
void smallest(struct node *root){
  struct node *ptr=root;
  while(ptr->left!=NULL){
    ptr=ptr->left;
  }
  printf("\n%d",ptr->data);
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int height(struct node *root){
  if(root==NULL)return 0;
  int left=height(root->left);
  int right=height(root->right);
  return max(left,right)+1;
}
int leafnodes(struct node *root){
  if(root==NULL)return 0;
  if(root->left==NULL && root->right==NULL){
    return 1;
  }
  int left=leafnodes(root->left);
  int right=leafnodes(root->right);
  return left+right;
}
void mirror(struct node *root){
  {
    if (root== NULL)
        return;
    else {
        struct node* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
}