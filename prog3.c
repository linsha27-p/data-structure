#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front=0,rear=0;
void main(){
void enqueue(int);
int dequeue(),item,opt;
void display();
do{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt){
case 1:
printf("Enter your item:");
scanf("%d",&item);
enqueue(item);
break;
case 2:
item=dequeue();
if(item!=-9)
printf("Popped value=%d\n",item);
break;
case 3:
display();
break;
case 4:
exit(0);
}}
while(9);
}
void enqueue(int item)
{
int temp;
temp=(rear+1)%SIZE;
if(temp==front)
printf("Queue is full...!");
else{
rear=temp;
queue[rear]=item;
}
return;
}
int dequeue(){
if(front==rear){
printf("Queue is empty...!");
return -9;
}
else{
front=(front+1)%SIZE;
return queue[front];}}
void display(){
int i;
if(front==rear)
printf("Queue is empty...!");
else{
i=(front+1)%SIZE;
do
{
    printf("%d ", queue[i]);
    i = (i + 1) % SIZE;
}
while(i != (rear + 1) % SIZE);
}
return;
}
