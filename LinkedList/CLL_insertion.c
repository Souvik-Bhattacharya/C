#include<stdio.h>
#include<stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist node;

int count = 0;

void create(node *head){
    node *temp;
    int c = 0;
    temp = head;
    while(1){
        count += 1;
        printf("Enter the data of the node:");
        scanf("%d",&temp->data);
        printf("Press 1 if this is last node else Press any key:");
        scanf("%d",&c);
        if(c == 1){
            temp->next = head;
            break;
        }else{
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
        }
    }
    return;
}

node *findTail(node *head){
    int i;
    for(i = 1;i<count;i++) head = head->next;
    return head;
}

node *insertFirst(node *head){
    node *temp, *tail;
    int data;
    count += 1;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data of the new node:");
    scanf("%d",&temp->data);
    printf("Linked list after insertion at first: ");
    temp->next = head;
    head = temp;
    tail = findTail(head);
    tail->next = head;
    return head;
}

void insertLast(node *head){
    node *tail;
    int data;
    tail = findTail(head);
    count += 1;
    tail->next = (node *)malloc(sizeof(node));
    printf("Enter the data of the new node:");
    scanf("%d",&tail->next->data);
    printf("Linked list after insertion at last: ");
    tail->next->next = head;
    return;
}

node *findPosBefore(node *head,int target){
    while(head->next->data != target) head = head->next;
    return head;
}

void insertBefore(node *head){
    int target;
    node *pos, *temp;
    printf("Enter the data for finding the target node for insertion before:");
    scanf("%d",&target);
    if(head->data == target) printf("Sorry! You are trying to insert a node at first!\n");
    else{
    pos = findPosBefore(head,target);
    count += 1;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data for new node:");
    scanf("%d",&temp->data);
    printf("Linked list after insertion before the node with data %d: ",target);
    temp->next = pos->next;
    pos->next = temp;}
    return;
}

node *findPosAfter(node *head,int target){
    while(head->data != target) head = head->next;
    return head;
}

void insertAfter(node *head){
    int target;
    node *pos, *temp, *tail;
    printf("Enter the data for finding the target node for insertion after:");
    scanf("%d",&target);
    tail = findTail(head);
    if(tail->data == target){
        printf("Sorry! You are trying to insert a node at last!\n");
        insertLast(head);
    }
    else{
    pos = findPosAfter(head,target);
    count += 1;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data for new node:");
    scanf("%d",&temp->data);
    printf("Linked list after insertion after the node with data %d: ",target);
    temp->next = pos->next;
    pos->next = temp;}
    return;
}

void display(node *head){
    node *temp;
    temp = head;
    while(temp->next != head){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d..->..",temp->data);
    printf("%d\n",temp->next->data);
    return;
}

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
    printf("The size of the initial linked list is: %d\n",count);
    printf("The initial linked list is: ");
    display(head);
    head = insertFirst(head);
    display(head);
    insertBefore(head);
    display(head);
    insertAfter(head);
    display(head);
    insertLast(head);
    display(head);
    printf("The size of the final linked list is: %d\n",count);
    return 0;
}