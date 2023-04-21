#include <stdio.h>
#include<limits.h>

int c[25][25], n = 0, optimal_path[20];

int TSP(int i, int vc[]){
    int min = INT_MAX, temp,j, flag = 0, temp_arr[20];
    vc[i] = 1;
    for(j = 0;j < n;j++){
        if(vc[j] == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(j = 0;j < n;j++){
            if(vc[j] == 0){
                for(int k = 0;k<n;k++) temp_arr[k] = vc[k];
                temp = c[i][j] + TSP(j,temp_arr);
                if(temp < min){
                    min = temp;
                    optimal_path[i] = j;
                }
            }
        }
        return min;
    }
    else{
        return c[i][0];
    }
}

void path(int start,int visited_path[]){
    if(visited_path[start] == 0){
        visited_path[start] = 1;
        printf("%d->",start+1);
        TSP(optimal_path[start],visited_path);
        path(optimal_path[start],visited_path);
    }
    else{
        printf("%d",start+1);
    }
}

int main()
{
    int i, j;
    int visited_cities[20], visited_path[20];
    printf("\nEnter Number of Cities:");
    scanf("%d", &n);
    printf("\nEnter the costs of Cost Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter costs of row %d\n",  i + 1);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
        visited_cities[i] = 0;
        visited_path[i] = 0;
    }
    printf("\nEntered Cost Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
    }
    int start = 0;
    printf("\nThe cost is:%d",TSP(start,visited_cities));
    printf("\nThe optimal path is:");
    path(start,visited_path);
    printf("\n");
    for(int l = 0;l<n;l++) printf("%d ",optimal_path[l]);
    return 0;
}