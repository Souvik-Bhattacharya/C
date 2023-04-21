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
    if(c == 1){
        listhead->next = NULL;
    }
    else{
        listhead->next = (node *)malloc(sizeof(node));
        create(listhead->next);
    }
    return;
}

node *reverse(node *listhead){
    node *temp1, *temp2, *temp3;
    temp3 = listhead;
    temp2 = NULL;
    while (temp3 != NULL){
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
        if(temp2->next != NULL) temp2->next->prev = temp2;
    }
    temp2->prev = NULL;
    return temp2;
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
    printf("The size of the linked list is: %d\n",count);
    printf("The initial linked list is:\n");
    print(head);
    printf("The reverse linked list is:\n");
    head = reverse(head);
    print(head);
    return 0;
}