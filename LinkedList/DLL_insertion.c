#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct linkedlist{
    struct linkedlist *prev;
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist node;

node *end = NULL;

void create(node *listhead){
    int c;
    count += 1;
    listhead->prev = end;
    end = listhead;
    printf("Enter data:");
    scanf("%d",&listhead->data);
    printf("Press 1 if this is last node else press any key:");
    scanf("%d",&c);
    if(c == 1) listhead->next = NULL;
    else{
        listhead->next = (node *)malloc(sizeof(node));
        create(listhead->next);
    }
    return;
}

node *insertFirst(node *head){
    node *temp;
    count += 1;
    printf("Linked list after insertion at first:\n");
    temp = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
    return head;
}

node *findPos(node *head,int target){
    while(head->data != target) head = head->next;
    return head;
}

void insertBefore(node *head){
    node *pos, *temp;
    int target;
    count += 1;
    printf("Enter the data for finding the target node for insertion before:");
    scanf("%d",&target);
    printf("Linked list after insertion before the node with key %d:\n",target);
    pos = findPos(head,target);
    temp = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->prev = pos->prev;
    temp->next = pos->prev->next;
    pos->prev->next = temp;
    pos->prev = temp;
    return;
}

void insertAfter(node *head){
    node *pos, *temp;
    int target;
    count += 1;
    printf("Enter the data for finding the target node for insertion after:");
    scanf("%d",&target);
    printf("Linked list after insertion after the node with key %d:\n",target);
    pos = findPos(head,target);
    temp = (node *)malloc(sizeof(node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->next = pos->next;
    temp->prev = pos->next->prev;
    pos->next->prev = temp;
    pos->next = temp;
    return;
}

node *findTail(node *head){
    while(head->next != NULL) head = head->next;
    return head;
}

void insertLast(node *head){
    node *tail;
    tail = findTail(head);
    printf("Linked list after insertion at last:\n");
    tail->next = (node *)malloc(sizeof(node));
    create(tail->next);
    return;
}

void print(node *listhead){
    if(listhead->next != NULL){
        printf("%d<->",listhead->data);
        print(listhead->next);
    }
    else printf("%d\n",listhead->data);
    return;
}

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
    printf("The size of the initial linked list is: %d\n",count);
    printf("The initial linked list is:\n");
    print(head);
    head = insertFirst(head);
    print(head);
    insertBefore(head);
    print(head);
    insertAfter(head);
    print(head);
    insertLast(head);
    print(head);
    printf("The size of the final linked list is: %d\n",count);
    return 0;
}