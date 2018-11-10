/* 
A Program for Singly Linked List
 */
#include <stdio.h>
#include <stdlib.h>

void create_list(int);
void addatbeg(int);
void addafter(int, int);
void del(int);
void display();
void search(int);

struct node
{
    int info;
    struct node *link;
} * start;

void main()
{
    int ch, n, m, i, pos;
    start = NULL;
    while (1)
    {
        printf("\n1.Create list");
        printf("\n2.Add at Beginning");
        printf("\n3.Add After");
        printf("\n4.Delete");
        printf("\n5.Display");
        printf("\n6.Search");
        printf("\n7.Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nHow many no of elements : ");
            scanf("%d",&n);
            for (i = 0; i<n; i++)
            {
                printf("\nEnter the element : ");
                scanf("%d", &m);
                create_list(m);
            }
            break;

        case 2:
            printf("\nEnter the element : ");
            scanf("%d", &m);
            addatbeg(m);
            break;

        case 3:
            printf("Enter the element & position after which to add : ");
            scanf("%d%d", &m, &pos);
            addafter(m, pos);
            break;

        case 4:
            if (start == NULL)
            {
                printf("\nList Empty ");
                continue;
            }
            printf("\nEnter element to delete : ");
            scanf("%d", &m);
            del(m);
            break;

        case 5:
            display();
            break;

        case 6:
            printf("\nEnter the element to search : ");
            scanf("%d", &m);
            search(m);
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("\nWrong choice");
        }
    }
}

void create_list(int data)
{
    struct node *q, *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start = NULL)
        start = tmp;

    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = tmp;
    }
}

void search(int data)
{
    struct node *ptr = start;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->info == data)
        {
            printf("\nItem %d found at position %d ", data, pos);
            return;
        }
        ptr = ptr->link;
        pos++;
        if (ptr == NULL)
        {
            printf("\nItem %d not found in the list", data);
        }
    }
}

void addatbeg(int data)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}

void addafter(int data, int pos)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < pos; i++)
    {
        q = q->link;
        if (q->link == NULL)
        {
            printf("\nThere are less than %d elements ", pos);
            return;
        }
    }
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->link = q->link;
    tmp->info = data;
    q->link = tmp;
}

void del(int data)
{
    struct node *tmp, *q;
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    q = start;
    while (q->link->link != NULL)
    {
        if (q->link->info == data)
        {
            tmp = q->link;
            q->link = tmp->link;
            free(tmp);
            return;
        }
        q = q->link;
        if (q->link->info == data)
        {
            tmp = q->link;
            free(tmp);
            q->link = NULL;
            return;
        }
        printf("\nElement %d not found ", data);
    }
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    q = start;
    printf("\nList is : ");
    while (q != NULL)
    {
        printf("%d\t", q->info);
        q = q->link;
    }
}