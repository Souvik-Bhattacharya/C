#include<stdio.h>
#include<stdlib.h>

struct polynomial{
    int coef;
    int power;
    struct polynomial *next;
};
typedef struct polynomial node;
int count = 0;

void create(node *head){
    int c;
    while(1){
        count ++;
        printf("Enter the coefficient of variable %d:",count);
        scanf("%d",&head->coef);
        printf("Enter the power of variable %d:",count);
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

void display(node *head){
    while(head->next != NULL){
        printf("Coefficient:%d,Power:%d -> ",head->coef,head->power);
        head = head->next;}
    printf("Coefficient:%d,Power:%d\n",head->coef,head->power);
    return;
}

int main(){
    node *head;
    head = (node *)malloc(sizeof(node));
    printf("Create the polynomial equation:\n");
    create(head);
    printf("The polynomial equation of size %d is: ",count);
    display(head);
    return 0;
}