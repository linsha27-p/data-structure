//doubly linked list operation
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
int main()
{
struct node *list=(struct node *)0;
struct node *insert(struct node *, int);
struct node *delete(struct node *, int);
struct node *search(struct node *, int);
void display(struct node *);
struct node *start = (struct node *)0;
int item, opt;
while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                printf("Item to insert: ");
                scanf("%d", &item);
                start = insert(start, item);
                break;
            case 2:
                printf("Item to delete: ");
                scanf("%d", &item);
                start = delete(start, item);
                break;
            case 3:
                printf("Item to search: ");
                scanf("%d", &item);
                if (search(start, item) == (struct node *)0)
                    printf("Not found\n");
                else
                    printf("Found\n");
                break;
            case 4:
                display(start);
                break;
            case 5:
                exit(0);  
        }
    }
}
//function to insert
struct node *insert(struct node *s, int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = (struct node *)0;
    t->right = s;
    if(s!=0)
        s->left=t;
    return t;
}
//function to display
void display(struct node *s)
{
if(s==0)
{
printf("\n list is empty..");
return;
}
printf("\nlist elements are:");
    while (s!=0)
    {
        printf("%d\t ", s->data);
        s = s->right;
    }

    printf("\n");
    return;
}
//function to search
struct node *search(struct node *s, int data)
{
    while (s != 0 && data != s->data)
        s = s->right;

    return s;
}
//function to delete 
struct node *delete(struct node *s, int data)
{
    struct node *t;
    t = search(s, data);
    if (t == 0)
    {
        printf("Data not found\n");
        return s;
    }
    if (t->left == 0)
        s = t->right;
    else
        t->left->right = t->right;
    if (t->right != 0)
        t->right->left = t->left;
    free(t);
    return s;
}
