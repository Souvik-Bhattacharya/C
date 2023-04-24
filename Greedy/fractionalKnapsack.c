#include<stdio.h>

float x[25] = {0.0}, totalProfit = 0.0;

void display(int n){
    printf("\nThe resultant array vector is:");
    for(int i = 0; i < n; i++) printf("\t%f", x[i]);
    printf("\nThe total profit is: %f", totalProfit);
}

void sort(int n, float profit[], float weight[], float ratio[]){
    float temp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ratio[j] > ratio[i]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }
}

void fracKnap(int n, float profit[], float weight[], float capacity){
    float ratio[25], varCapacity;
    varCapacity = capacity;
    for(int i = 0; i < n; i++) ratio[i] = profit[i]/weight[i];
    sort(n, profit, weight, ratio);
    for(int i = 0;i < n; i++){
        if(weight[i] > varCapacity){
            x[i] = varCapacity/weight[i];
            totalProfit += x[i] * profit[i];
            varCapacity = 0.0;
            break;
        }
        else{
            x[i] = 1.0;
            totalProfit += profit[i];
            varCapacity -= weight[i];
        }
    }
    display(n);
}

int main(){
    float profit[25], weight[25], capacity;
    int n;
    printf("\nEnter total no of items:");
    scanf("%d", &n);
    printf("\nEnter the total capacity of the sack:");
    scanf("%f", &capacity);
    printf("\nEnter the profits and weights of the %d items:\n", n);
    for(int i = 0; i < n; i++){
        printf("\nEnter the profit and weight of item %d: ", i + 1);
        scanf("%f %f", &profit[i], &weight[i]);
    }
    fracKnap(n, profit, weight, capacity);
    return 0;
}