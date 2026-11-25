//binary search tree operation
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *lchild,*rchild;
};
void main(){
struct node *insert(struct node *,int);
struct node *delete(struct node *,int);
struct node *search(struct node *,int);
void inorder(struct node *);
struct node *root=0;
int opt,data;
do{
printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder Traversal\n5.Exit\n");
printf("enter your choice:");
scanf("%d",&opt);
switch(opt){
case 1:
printf("Enter data to insert:");
scanf("%d",&data);
root=insert(root,data);
break;
case 2:
if(root==NULL)
printf("BST is empty!\n");
else{
printf("Enter data to delete:");
scanf("%d",&data);
root=delete(root,data);
if(root==NULL)
printf("BST is empty!\n");
}
break;
case 3:
printf("Enter the data to search:");
scanf("%d",&data);
if(search(root,data)!=0)
printf("%d found in BST",data);
else
printf("%d not found in bst",data);
break;
case 4:
if(root==NULL)
printf("BST is empty!\n");
 else{
 printf("Inorder traversal:");
inorder(root);
}
break;
case 5:
exit(0);
}}
while(9);
}
//function to search an item in bst
struct node *search(struct node *root,int data){
while(root!=0 && root->data!=data)
if(data<root->data)
root=root->lchild;
else
root=root->rchild;
return root;
}
//function to insert an item in bst
struct node *insert(struct node *root,int data){
struct node *t,*par=0,*t1;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->lchild=t->rchild=0;
if(root==0)
root=t;
else if(search(root,data)!=0)
printf("%d is duplicated",data);
else{
t1=root;
while(t1!=0)
{
par=t1;
if(data<t1->data)
t1=t1->lchild;
else
t1=t1->rchild;
}
if(data<par->data)
par->lchild=t;
else
par->rchild=t;}
return root;
}
//function to display bst in inorder
void inorder(struct node *root)
{
if(root!=0){
inorder(root->lchild);
printf("%d ",root->data);
inorder(root->rchild);
}}
//function to delete an item in bst
struct node *delete(struct node *root,int data)
{
struct node *t=root,*par=0,*suc,*sucpar;
while(t!=0 && t->data != data){
par=t;
if(data<t->data)
t=t->lchild;
else
t=t->rchild;
}
if(t==0)
printf("%d not foumd",data);
else{
if(t->lchild==0 && t->rchild==0)
{
if(par==0)
root=0;
else if(data<par->data)
par->lchild=0;
else
par->rchild=0;
}
else if(t->lchild==0 || t->rchild==0)
{
if(par==0)
root=root->lchild==0 ? root->rchild:root->lchild;
else if(data<par->data)
par->lchild=t->lchild==0 ? t->rchild:t->lchild;
else
par->rchild=t->lchild==0 ? t->rchild:t->lchild;}
else{
sucpar=t;
suc=t->rchild;
while(suc->lchild!=0)
{
sucpar=suc;
suc=suc->lchild;
}
t->data=suc->data;
if(suc->data<sucpar->data)
sucpar->lchild=suc->rchild;
else
sucpar->rchild=suc->rchild;
t=suc; 
}
free(t);
}
return root;
}
