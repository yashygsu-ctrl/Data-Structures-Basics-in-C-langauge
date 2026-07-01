#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
void insert_front(int value)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }
    else
    {
        new->link = first;
        first = new;
    }
}
void insert_end(int value)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }
    else
    {
        struct node *save;
        save = first;
        while (save != NULL)
        {
            save = save->link;
        }
        save->link = new;
        new->link = NULL;
    }
}
void insert_sorted(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->info = value;
    if (first == NULL)
    {
        new->link = NULL;
        first = new;
    }
    else if(new->info < first->info){
        new->link = first;
        first = new;
    }
    else{
        struct node*save;
        struct node*pred;
        while ((save!=NULL)&&((new->info)>=(save->info))){
            pred->link = save;
            save = save->link;
        }
        if(save->link==NULL){
            new->link=  NULL;
            save->link=new;
        }
        else{
            new->link=save;
            pred->link=new;
        }
    }
}
void delete_first(){
    
}
void display()
{
    struct node *save;
    if (first == NULL)
    {
        printf("List is empty");
    }
    else
    {
        save = first;
        while (save != NULL)
        {
            printf("%d\n", save->info);
            save = save->link;
        }
    }
}
#define MAX 5
void main()
{
    int choice, pos, value;
    do
    {
        printf("Select any of the funtions of simply linked list as below from 1-8---\n");
        printf("1. Insert at Front.\n");
        printf("2.Insert at end\n");
        printf("3.Insert in sorted order\n");
        // printf("4. Delete first\n");
        // printf("5.Delete before given positon.\n ");
        // printf("6.Delete after given podition\n ");
        printf("4.Display.\n ");
        printf("5.Exit\n\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_front(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_sorted(value);
            break;
        // case 4:
        //     printf("Enter value: ");
        //     scanf("%d", &value);
        //     delete_first(value);
        //     break;
        // case 5:
        //     printf("Enter value: ");
        //     scanf("%d", &value);
        //     delete_before_position(value);
        //     break;
        // case 6:
        //     printf("Enter value: ");
        //     scanf("%d", &value);
        //     delete_after_position(value);
        //     break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting Program!");
            break;
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (choice != 5);
}