#include<stdio.h>
#include<math.h>

int keys[50];
int size_keys;
int hashValues[50];

int digits(int k){
    int c = 0;
    while(k > 0){
        c++;
        k = k/10;
    }
    return c;
}

void hashing(){
    int i, j, k, count_seed, count_power, iterations, divisor, hv;
    for(i = 0;i < size_keys;i++){
        count_seed = digits(keys[i]);
        k = keys[i]*keys[i];
        count_power = digits(k);
        if(count_seed % 2 == 0) iterations = ceil(count_power/4.0);
        else iterations = count_power/4;
        for(j = 0;j < iterations;j++) k = k/10;
        if(count_seed % 2 == 0) divisor = pow(10, count_seed - 1);
        else divisor = pow(10, count_seed);
        hv = k % divisor;
        hashValues[i] = hv;
    }
    return;
}

int main(){
    int i;
    printf("Enter the no of keys:");
    scanf("%d",&size_keys);
    printf("Enter the keys:\n");
    for(i = 0;i < size_keys;i++) scanf("%d",&keys[i]);
    hashing();
    printf("The hash values of the given keys are: ");
    for(i = 0;i < size_keys;i++) printf("%d ",hashValues[i]);
    return 0;
}