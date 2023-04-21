#include<stdio.h>
#include<stdlib.h>

int count = 0;

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

void countNode(node *listhead){
    count += 1;
    if(listhead->next == NULL) return;
    else countNode(listhead->next);
    return;
}

node *reverse(node *listhead){
    node *temp1, *temp2, *temp3;
    temp3 = listhead;
    temp2 = NULL;
    while(temp3 != NULL){
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
    }
    return(temp2);
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

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
    countNode(head);
    printf("No of nodes is: %d\n",count);
    printf("Initial linked list is:\n");
    print(head);
    printf("Reversed linked list is:\n");
    head = reverse(head);
    print(head);
    free(head);
    return 0;
}