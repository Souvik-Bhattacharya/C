// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

char XOR(char d, char k){
    if(d == k) return '0';
    else return '1';
}

void encode(char data[20],char key[10]){
    int dl = strlen(data);
    for(int i = dl; i < dl + strlen(key) - 1; i++){
        data[i] = '0';
    }
    char temp[20];
    int i;
    for(i = 0; i < strlen(key); i++) temp[i] = XOR(data[i], key[i]);
    while(i <= strlen(data) - 1){
        if(temp[0] == '0'){
            int j;
            for(j = 0; j < strlen(temp) - 1; j++) temp[j] = temp[j + 1];
            temp[j] = data[i];
            i++;
        }
        else{
            for(int k = 0; k < strlen(key); k++) temp[k] = XOR(temp[k], key[k]);
        }
    }
    if(temp[0] == '1'){
        for(int k = 0; k < strlen(key); k++) temp[k] = XOR(temp[k], key[k]);
    }
    for(int a = 1; a < strlen(key); a++){
        data[a + strlen(data) - strlen(key)] = temp[a];
    }
}

int main() {
    char data[20], key[10];
    printf("Data:");
    scanf("%s", data);
    printf("Key:");
    scanf("%s", key);
    encode(data, key);
    printf("Data:%s Key:%s", data, key);
    return 0;
}