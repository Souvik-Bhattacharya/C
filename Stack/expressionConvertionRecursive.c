#include<stdio.h>
#include<string.h>

int top = -1;
int maxsize;

char stack[50];

void push(char symbol){
    top++;
    stack[top] = symbol;
    return;
}

char pop(){
    char symbol;
    symbol = stack[top];
    top--;
    return symbol;
}

int priority(char symbol){
    switch (symbol)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    }
}

void reverse(char i[]){
    int ki, kr = 0;
    char r[maxsize];
    for(ki = strlen(i)-1;ki>=0;ki--){
        r[kr] = i[ki];
        kr++;
    }
    ki = 0;
    for(kr = 0;kr<strlen(r);kr++){
        i[ki] = r[kr];
        ki++;
    }
    return;
}

void resize(char i[]){
    int ki = 0;
    while(i[ki] != '\0'){
        if(i[ki] == '(') i[ki] = ')';
        else if(i[ki] == ')') i[ki] = '(';
        ki++;
    }
    return;
}

void toPost(char i[], char p[], int ki, int kp){
    int symbol, junk;
    if(i[ki] != '\0'){
        symbol = i[ki];
        if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'){
            while(priority(stack[top]) >= priority(symbol) && top != -1 && stack[top] != '('){
                p[kp] = pop();
                kp++;
            }
            push(symbol);
        }
        else if(symbol == '('){
            push(symbol);
        }
        else if(symbol == ')'){
            while(stack[top] != '('){
                p[kp] = pop();
                kp++;
            }
            junk = pop();
        }
        else{
            p[kp] = symbol;
            kp++;
        }
        ki++;
        toPost(i,p,ki,kp);
    }
    else{
        while(top != -1){
            p[kp] = pop();
            kp++;
        }
        p[kp] = '\0';
    }
    return;
}

void toPre(char i[], char p[], int ki, int kp){
    int symbol, junk;
    if(i[ki] != '\0'){
        symbol = i[ki];
        if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'){
            while(priority(stack[top]) >= priority(symbol) && top != -1 && stack[top] != '('){
                p[kp] = pop();
                kp++;
            }
            push(symbol);
        }
        else if(symbol == '('){
            push(symbol);
        }
        else if(symbol == ')'){
            while(stack[top] != '('){
                p[kp] = pop();
                kp++;
            }
            junk = pop();
        }
        else{
            p[kp] = symbol;
            kp++;
        }
        ki++;
        toPre(i,p,ki,kp);
    }
    else{
        while(top != -1){
            p[kp] = pop();
            kp++;
        }
        p[kp] = '\0';
        reverse(p);
    }
    return;
}

int main(){
    char i[50], p[50];
    int c, kp = 0, ki = 0;
    L:
    printf("Enter 1 for postfix, 2 for prefix & 3 for exit:");
    scanf("%d",&c);
    if(c == 3) goto R;
    printf("Enter the infix expression: ");
    scanf("%s",i);
    maxsize = strlen(i);
    R:
    switch (c)
    {
    case 1:
        toPost(i,p,ki,kp);
        printf("The postfix expression is: %s\n",p);
        goto L;
    case 2:
        reverse(i);
        resize(i);
        toPre(i,p,ki,kp);
        printf("The postfix expression is: %s\n",p);
        goto L;
    case 3:
        break;
    }
    return 0;
}