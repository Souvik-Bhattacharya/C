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

node *deleteFirst(node *head){
    node *temp;
    count -= 1;
    printf("Linked list after deletion at first:\n");
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

node *findKey(node *head,int target){
    while(head->data != target) head = head->next;
    return head;
}

node *findPos(node *head,int target){
    int pos;
    for(pos = 1;pos<target;pos++) head = head->next;
    return head;
}

void deleteMid(node *head){
    node *pos, *temp;
    int target,will;
    printf("If you want to find by value press 1 and if you want to find by position press any number:");
    scanf("%d",&will);
    if(will == 1){
    printf("Enter the data for finding the target node for deletion:");
    scanf("%d",&target);
    printf("Linked list after deleting the node with key %d:\n",target);
    pos = findKey(head,target);}
    else{
    printf("Enter the position for finding the target node for deletion:");
    scanf("%d",&target);
    printf("Linked list after deleting the node at position %d:\n",target);
    pos = findPos(head,target);}
    count -= 1;
    temp = pos;
    pos = pos->prev;
    pos->next->next->prev = pos->next->prev;
    pos->next = pos->next->next;
    free(temp);
    return;
}

node *findTail(node *head){
    while(head->next != NULL) head = head->next;
    return head;
}

void deleteLast(node *head){
    node *tail, *temp;
    count -= 1;
    tail = findTail(head);
    temp = tail;
    printf("Linked list after deletion at last:\n");
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
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
    head = deleteFirst(head);
    print(head);
    deleteMid(head);
    print(head);
    deleteMid(head);
    print(head);
    deleteLast(head);
    print(head);
    printf("The size of the final linked list is: %d\n",count);
    return 0;
}