#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int key;
    struct linkedlist *next;
};
typedef struct linkedlist node;

int count = 0;

void create(node *listhead)
{
    int c;
    printf("Enter value:");
    scanf("%d", &listhead->key);
    printf("Enter 1 if this is end else press any key:");
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

node *deleteFirst(node *listhead)
{
    printf("Linked List after deletion of first node:\n");
    node *new;
    new = listhead->next;
    free(listhead);
    listhead = new;
    return (listhead);
}

node *findByVal(node *listhead, int keyval)
{
    if (listhead->next->key == keyval)
        return (listhead);
    else
    {
        if (listhead->next->next == NULL)
            return (NULL);
        else
            findByVal(listhead->next, keyval);
    }
}

node *deleteByVal(node *listhead)
{
    node *n;
    node *new;
    int keyval;
    printf("Enter key value for deletion:");
    scanf("%d", &keyval);
    if (listhead->key == keyval)
    {
        new = listhead->next;
        free(listhead);
        listhead = new;
    }
    else
    {
        n = findByVal(listhead, keyval);
        if (n != NULL)
        {
            new = n->next->next;
            free(n->next);
            n->next = new;
        }
        else
            printf("The key is not found!\n");
    }
    return (listhead);
}

node *findByPos(node *listhead, int pos)
{
    count += 1;
    if ((count + 1) == pos)
        return (listhead);
    else
    {
        if (listhead->next->next == NULL)
            return (NULL);
        else
            findByPos(listhead->next, pos);
    }
}

node *deleteByPos(node *listhead)
{
    node *n;
    node *new;
    int pos;
    printf("Enter position for deletion:");
    scanf("%d", &pos);
    if ((count + 1) == pos)
    {
        new = listhead->next;
        free(listhead);
        listhead = new;
    }
    else
    {
        n = findByPos(listhead, pos);
        if (n != NULL)
        {
            new = n->next->next;
            free(n->next);
            n->next = new;
        }
        else
            printf("The position is not found!\n");
    }
    return (listhead);
}

node *findTail(node *listhead)
{
    if (listhead->next->next == NULL)
    {
        return (listhead);
    }
    else
        findTail(listhead->next);
}

node *deleteLast(node *listhead)
{
    printf("Linked List after deletion of last node:\n");
    node *n;
    if (listhead->next == NULL)
        listhead = NULL;
    else
    {
        n = findTail(listhead);
        n->next = n->next->next;
    }
    return (listhead);
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
    head = deleteFirst(head);
    if (head != NULL)
        print(head);
    else
    {
        printf("The linked list is empty!");
        return 0;
    }
    head = deleteByVal(head);
    if (head != NULL)
        print(head);
    else
    {
        printf("The linked list is empty!");
        return 0;
    }
    head = deleteByPos(head);
    if (head != NULL)
        print(head);
    else
    {
        printf("The linked list is empty!");
        return 0;
    }
    head = deleteLast(head);
    if (head != NULL)
        print(head);
    else
    {
        printf("The linked list is empty!");
        return 0;
    }
    free(head);
    return 0;
}