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

node *deleteFirst(node *head){
    node *tail, *temp;
    count -= 1;
    printf("Linked list after deleting the first node: ");
    temp = head;
    head = head->next;
    tail = findTail(head);
    tail->next = head;
    free(temp);
    return head;
}

void deleteLast(node *head){
    node *tail, *temp;
    tail = head;
    while(tail->next->next != head) tail = tail->next;
    printf("Linked list after deleting the last node: ");
    count -= 1;
    temp = tail->next;
    tail->next = head;
    free(temp);
    return;
}

node *findVal(node *head,int target){
    while(head->next->data != target) head = head->next;
    return head;
}

void deleteByVal(node *head){
    int target;
    node *pos, *temp, *tail;
    printf("Enter the key of the target node for deletion:");
    scanf("%d",&target);
    tail = findTail(head);
    if(head->data == target) printf("Sorry! You are trying to delete the first node!\n");
    else if(tail->data == target) deleteLast(head);
    else{
        
        pos = findVal(head,target);
        count -= 1;
        printf("Linked list after deleting the node with value %d: ",target);
        temp = pos->next;
        pos->next = pos->next->next;
        free(temp);
    }
    return;
}


node *findPos(node *head,int target){
    int i;
    for(i = 1;i<target;i++) head = head->next;
    return head;
}

void deleteByPos(node *head){
    int target;
    node *pos, *temp;
    printf("Enter the position of the target node for deletion:");
    scanf("%d",&target);
    if(target == 1) printf("Sorry! You are trying to delete the first node!\n");
    else if(target == count) deleteLast(head);
    else{
        target -= 1;
        pos = findPos(head,target);
        count -= 1;
        printf("Linked list after deleting the node at position %d: ",target+1);
        temp = pos->next;
        pos->next = pos->next->next;
        free(temp);
    }
    return;
}

void display(node *head){
    node *temp;
    temp = head;
    while(temp->next != head){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;
}

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
    printf("The size of the initial linked list is: %d\n",count);
    printf("The initial linked list is: ");
    display(head);
    head = deleteFirst(head);
    display(head);
    deleteByVal(head);
    display(head);
    deleteByPos(head);
    display(head);
    deleteLast(head);
    display(head);
    printf("The size of the final linked list is: %d\n",count);
    return 0;
}