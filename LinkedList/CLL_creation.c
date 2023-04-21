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

node *reverse(node *head){
    node *temp1, *temp2, *temp3, *temp;
    int pos;
    temp3 = head;
    temp2 = NULL;
    for(pos = 0;pos<count;pos++){
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
    }
    temp = temp2;
    while(temp->next != NULL) temp = temp->next;
    temp->next = temp2;
    return(temp2);
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
    printf("The reversed linked list is: ");
    head = reverse(head);
    display(head);
    return 0;
}