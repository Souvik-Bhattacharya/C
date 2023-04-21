#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int key;
    struct linkedlist *next;
};
typedef struct linkedlist node;

void create(node *listhead)
{
    int c;
    printf("Enter value:");
    scanf("%d", &listhead->key);
    printf("Enter 1 if this is end else any number:");
    scanf("%d", &c);
    if (c != 1)
    {
        listhead->next = (node *)malloc(sizeof(node));
        create(listhead->next);
    }
    else
        listhead->next = NULL;
    return;
}

node *insertFirst(node *listhead)
{
    printf("Linked List after insertion at first:\n");
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("Enter value to insert at first:");
    scanf("%d", &new->key);
    new->next = listhead;
    listhead = new;
    return (listhead);
}

node *findBefore(node *listhead, int keyval)
{
    if (listhead->next->key == keyval)
        return (listhead);
    else
    {
        if (listhead->next->next == NULL)
            return (NULL);
        else
            findBefore(listhead->next, keyval);
    }
}

node *insertBefore(node *listhead)
{
    node *n;
    node *new;
    int keyval;
    printf("Enter key value to insert before:");
    scanf("%d", &keyval);
    if (listhead->key == keyval)
    {
        new = (node *)malloc(sizeof(node));
        printf("Enter value to insert before:");
        scanf("%d", &new->key);
        new->next = listhead;
        listhead = new;
    }
    else
    {
        n = findBefore(listhead, keyval);
        if (n != NULL)
        {
            new = (node *)malloc(sizeof(node));
            printf("Enter value to insert before:");
            scanf("%d", &new->key);
            new->next = n->next;
            n->next = new;
        }
        else
            printf("The key value is not found!\n");
    }
    return (listhead);
}

node *findAfter(node *listhead, int keyval)
{
    if (listhead->key == keyval)
        return (listhead);
    else
    {
        if (listhead->next == NULL)
            return (NULL);
        else
            findAfter(listhead->next, keyval);
    }
}

node *insertAfter(node *listhead)
{
    node *n;
    node *new;
    int keyval;
    printf("Enter key value to insert after:");
    scanf("%d", &keyval);
    n = findAfter(listhead, keyval);
    if (n != NULL)
    {
        new = (node *)malloc(sizeof(node));
        printf("Enter value to insert after:");
        scanf("%d", &new->key);
        new->next = n->next;
        n->next = new;
    }
    else
        printf("The key value is not found!\n");
    return (listhead);
}

void insertLast(node *listhead)
{
    if (listhead->next == NULL)
    {
        listhead->next = (node *)malloc(sizeof(node));
        printf("Insert nodes at end:\n");
        create(listhead->next);
    }
    else
        insertLast(listhead->next);
    return;
}

void print(node *listhead)
{
    if (listhead->next != NULL)
    {
        printf("%d->", listhead->key);
        print(listhead->next);
    }
    else if (listhead->next == NULL)
        printf("%d\n", listhead->key);
    return;
}

int main()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
    print(head);
    head = insertFirst(head);
    print(head);
    head = insertBefore(head);
    print(head);
    head = insertAfter(head);
    print(head);
    printf("Linked List after insertion at last:\n");
    insertLast(head);
    print(head);
    free(head);
    return 0;
}