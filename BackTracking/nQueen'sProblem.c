#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int chessBoard[20], count;

void display(int n){
    printf("\n\nThe solution %d is:\n\n \t",++count);
    for(int i = 1; i <= n; i++) printf("%d\t",i);
    for(int row = 1; row <= n; row++){
        printf("\n%d\t",row);
        for(int column = 1; column <= n; column++){
            if(chessBoard[row] == column) printf("Q\t");
            else printf("-\t");
        }
    }
}

bool place(int row, int column){
    for(int i = 1; i <= row - 1; i++){
        if(chessBoard[i] == column) return false;
        else if(abs(chessBoard[i] - column) == abs(i - row)) return false;
    }
    return true;
}

void queen(int row, int n){
    for(int column = 1; column <= n; column++){
        if(place(row, column)){
            chessBoard[row] = column;
            if(row == n) display(n);
            else queen(row + 1, n);
        }
    }
}

int main(){
    int n;
    printf("\nEnter the no of queens:");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}
