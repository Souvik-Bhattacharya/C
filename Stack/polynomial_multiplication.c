#include<stdio.h>
#include<stdlib.h>

struct polynomial{
    int coef;
    int power;
    struct polynomial *next;};
typedef struct polynomial node;
int count = 0;

void create(node *head){
    int c;
    while(1){
        printf("Enter the coefficient of variable:");
        scanf("%d",&head->coef);
        printf("Enter the power of variable:");
        scanf("%d",&head->power);
        printf("Press 1 if it's last node else press any number:");
        scanf("%d",&c);
        if(c == 1){
            head->next = NULL;
            break;
        }else{
            head->next = (node *)malloc(sizeof(node));
            head = head->next;}}
    return;
}

void multiply(node *a,node *b,node *c){
    node *temp;
    while(a != NULL){
        temp = b;
        while(temp != NULL){
            count ++;
            c->coef = (a->coef) * (temp->coef);
            c->power = (a->power) + (temp->power);
            if(a->next == NULL && temp->next == NULL) c->next = NULL;
            else{
            c->next = (node *)malloc(sizeof(node));
            c = c->next;}
            temp = temp->next;}
        a = a->next;}
    return;
}

void display(node *head){
    while(head->next != NULL){
        printf("%dX^%d + ",head->coef,head->power);
        head = head->next;}
    printf("%dX^%d\n",head->coef,head->power);
    return;
}

int main(){
    node *head1, *head2, *head3;
    head1 = (node *)malloc(sizeof(node));
    printf("Create the first polynomial equation:\n");
    create(head1);
    printf("The first polynomial equation is:\n");
    display(head1);
    head2 = (node *)malloc(sizeof(node));
    printf("Create the second polynomial equation:\n");
    create(head2);
    printf("The second polynomial equation is:\n");
    display(head2);
    head3 = (node *)malloc(sizeof(node));
    multiply(head1,head2,head3);
    printf("The resultant polynomial equation of size %d is:\n",count);
    display(head3);
    return 0;
}