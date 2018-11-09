#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next, *prev;
};

typedef struct node DLList;

DLList *start = NULL;
void insert_first()
{
    DLList *n;
    n = (DLList*)malloc(sizeof(DLList));

    printf("Enter Number to store : ");
    scanf("%d",&n->val );

    if (start == NULL)
    {    
        start = n;
    }
    else
    {
        start->prev=n;
        n->next=start;
        start=n;
    }
}

int main(int argc, char const *argv[])
{
    insert_first();
    insert_first();
    insert_first();

    

    // printf("%d",n->val);

    
    return 0;
}
