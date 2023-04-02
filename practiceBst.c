#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *createnode(int data);
void inorder(struct node *root);
void insert(struct node *root,int data);
int height(struct node *root);
int count_leaf(struct node *root);
int count_non(struct node *root);
struct node *delete(struct node *root,int data);

int main(){
  struct node *root = createnode(2);
  struct node *root_1 = createnode(1);
  struct node *root_2 = createnode(3);
  root->left = root_1;
  root->right = root_2;
  insert(root,8);
  insert(root,12);
  delete(root,12);
  inorder(root);
  int realmadrid=height(root);
  printf("\n%d",realmadrid);
    int realmadrid_1=count_leaf(root);
  printf("\n%d",realmadrid_1);
    int realmadrid_3=count_non(root);
  printf("\n%d",realmadrid_3);
  
  return 0;
}
struct node *createnode(int data){
  struct node *root;
  root=(struct node*)malloc(sizeof(struct node));
  root->data=data;
  root->right=NULL;
  root->left=NULL;
  return root;
}
void inorder(struct node *root){
  if(root==NULL)return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void insert(struct node *root,int data){
  struct node *prev;
  struct node *new=createnode(data);
  while(root!=NULL){
    prev=root;
    if(root->data<data){
      root=root->right;
    }else if(root->data>data){
      root=root->left;
  
  }else{
      printf("Already in Bst,cannot insert %d\n",data);
      return;
  }
      
  }
  if(prev->data>data){
    prev->left=new;
  }else{
    prev->right=new;
  }
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
int count_non(struct node *root)
{
    if(root == NULL || (root->left== NULL && root->right== NULL))
        return 0;
    else
        return count_non(root->left) + count_non(root->right) + 1;
}
int countl = 0;
int count_leaf(struct node *root)
{
    
    if( root!= NULL)
    {
        count_leaf(root->left);
        if(root->left == NULL && root->right== NULL)
            countl++;
        count_leaf(root->right);
    }
    return countl;
}
// void mirror(struct Node* node)
// {
//     if (node == NULL)
//         return;
//     else {
//         struct Node* temp;
 
//         /* do the subtrees */
//         mirror(node->left);
//         mirror(node->right);
 
//         /* swap the pointers in this node */
//         temp = node->left;
//         node->left = node->right;
//         node->right = temp;
//     }
// }
struct node *inorder_predecessor(struct node *root) {
  root = root->left;
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
  }

struct node *delete(struct node *root,int data){
  if(root==NULL){
    return NULL;
  }
  if(root->right==NULL && root->left==NULL){
    free(root);
    return NULL;
  }
  struct node *ipre;
  if(data>root->data){
    root->right=delete(root->right,data);
  }else if(data<root->data){
    root->left=delete(root->right,data);
  }else{
    ipre=inorder_predecessor(root);
    root->data=ipre->data;
    root->left=delete(root->left,data);
  }
  return root;
}
